#include <iostream>
#include <memory>
#include <functional>
#include <utility>
#include <stdexcept>
#include <cstddef>
#include <algorithm>

template <
    class Key, 
    class T, 
    class Compare = std::less<Key>, 
    class Allocator = std::allocator<std::pair<const Key, T>>
>
class custom_multimap {
public:
    // --- Member Types ---
    using key_type        = Key;
    using mapped_type     = T;
    using value_type      = std::pair<const Key, T>;
    using size_type        = std::size_t;
    using difference_type  = std::ptrdiff_t;
    using key_compare     = Compare;
    using allocator_type  = Allocator;
    using reference       = value_type&;
    using const_reference = const value_type&;

private:
    // Internal Tree Node Structure
    struct Node {
        value_type value;
        Node* left;
        Node* right;
        Node* parent;
        size_type insertion_id; // Ensures stable positioning for equivalent keys

        Node(const value_type& val, size_type id) 
            : value(val), left(nullptr), right(nullptr), parent(nullptr), insertion_id(id) {}
    };

    using NodeAllocator = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
    
    Node* m_root;
    size_type m_size;
    size_type m_insertion_counter; // Monotonic counter for stable sorting
    key_compare m_compare;
    NodeAllocator m_node_alloc;

    // Helper to find the leftmost element in a subtree
    static Node* minimum(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    // Helper to find the rightmost element in a subtree
    static Node* maximum(Node* node) {
        while (node && node->right) node = node->right;
        return node;
    }

    // Successor node helper for iteration
    static Node* successor(Node* node) {
        if (!node) return nullptr;
        if (node->right) return minimum(node->right);
        Node* p = node->parent;
        while (p && node == p->right) {
            node = p;
            p = p->parent;
        }
        return p;
    }

    // Predecessor node helper for iteration
    static Node* predecessor(Node* node) {
        if (!node) return nullptr;
        if (node->left) return maximum(node->left);
        Node* p = node->parent;
        while (p && node == p->left) {
            node = p;
            p = p->parent;
        }
        return p;
    }

    void clear_tree(Node* node) {
        if (!node) return;
        clear_tree(node->left);
        clear_tree(node->right);
        std::allocator_traits<NodeAllocator>::destroy(m_node_alloc, node);
        m_node_alloc.deallocate(node, 1);
    }

    bool keys_equal(const Key& a, const Key& b) const {
        return !m_compare(a, b) && !m_compare(b, a);
    }

    // Custom comparison incorporating the insertion index to handle equivalent keys stably
    bool node_less(const Key& k1, size_type id1, const Key& k2, size_type id2) const {
        if (m_compare(k1, k2)) return true;
        if (m_compare(k2, k1)) return false;
        return id1 < id2; // If keys are equivalent, older insertion comes first
    }

public:
    // --- Iterators ---
    class iterator {
        friend class custom_multimap;
        Node* m_node;
        Node* m_root_ref; // To handle end() tracking safely
        
        iterator(Node* n, Node* r) : m_node(n), m_root_ref(r) {}
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = custom_multimap::value_type;
        using difference_type  = custom_multimap::difference_type;
        using pointer           = value_type*;
        using reference         = value_type&;

        reference operator*() const { return m_node->value; }
        pointer operator->() const { return &(m_node->value); }

        iterator& operator++() {
            if (!m_node) return *this; 
            m_node = successor(m_node);
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        iterator& operator--() {
            if (!m_node) { // Moving backward from end()
                m_node = maximum(m_root_ref);
            } else {
                m_node = predecessor(m_node);
            }
            return *this;
        }
        iterator operator--(int) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }
        bool operator==(const iterator& other) const { return m_node == other.m_node; }
        bool operator!=(const iterator& other) const { return m_node != other.m_node; }
    };

    // --- Constructors & Destructor ---
    custom_multimap() : m_root(nullptr), m_size(0), m_insertion_counter(0), m_compare(Compare()), m_node_alloc(NodeAllocator()) {}
    
    ~custom_multimap() { clear(); }

    // --- Capacity ---
    bool empty() const noexcept { return m_size == 0; }
    size_type size() const noexcept { return m_size; }

    // --- Iterators Boundaries ---
    iterator begin() noexcept { return iterator(minimum(m_root), m_root); }
    iterator end() noexcept { return iterator(nullptr, m_root); }

    // --- Modifiers ---
    void clear() noexcept {
        clear_tree(m_root);
        m_root = nullptr;
        m_size = 0;
        m_insertion_counter = 0;
    }

    iterator insert(const value_type& value) {
        Node* new_node = m_node_alloc.allocate(1);
        std::allocator_traits<NodeAllocator>::construct(m_node_alloc, new_node, value, m_insertion_counter++);
        
        if (!m_root) {
            m_root = new_node;
            m_size++;
            return iterator(m_root, m_root);
        }

        Node* current = m_root;
        Node* parent = nullptr;
        while (current) {
            parent = current;
            if (node_less(value.first, new_node->insertion_id, current->value.first, current->insertion_id)) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        new_node->parent = parent;
        if (node_less(value.first, new_node->insertion_id, parent->value.first, parent->insertion_id)) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }

        m_size++;
        return iterator(new_node, m_root);
    }

    size_type erase(const Key& key) {
        size_type removed_count = 0;
        iterator it = find(key);
        while (it != end() && keys_equal(it->m_node->value.first, key)) {
            iterator next = it;
            ++next;
            erase(it);
            it = next;
            removed_count++;
        }
        return removed_count;
    }

    iterator erase(iterator pos) {
        if (pos == end() || !pos.m_node) return end();
        
        Node* z = pos.m_node;
        Node* next_node = successor(z);
        Node* x = nullptr;
        Node* y = z;

        // Tree structural reconfiguration node excision code
        if (z->left == nullptr) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            next_node = y; 
            x = y->right;
            if (y->parent != z) {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }

        std::allocator_traits<NodeAllocator>::destroy(m_node_alloc, z);
        m_node_alloc.deallocate(z, 1);
        m_size--;

        return iterator(next_node, m_root);
    }

    // --- Lookup Operations ---
    iterator find(const Key& key) {
        Node* current = m_root;
        Node* first_match = nullptr;
        
        while (current) {
            if (keys_equal(current->value.first, key)) {
                first_match = current;
                current = current->left; // Go left to check if there are earlier elements with same key
            } else if (m_compare(key, current->value.first)) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return first_match ? iterator(first_match, m_root) : end();
    }

    size_type count(const Key& key) const {
        size_type occurrences = 0;
        Node* current = m_root;
        count_helper(current, key, occurrences);
        return occurrences;
    }

    iterator lower_bound(const Key& key) {
        Node* current = m_root;
        Node* result = nullptr;
        while (current) {
            if (!m_compare(current->value.first, key)) { // current->first >= key
                result = current;
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return iterator(result, m_root);
    }

    iterator upper_bound(const Key& key) {
        Node* current = m_root;
        Node* result = nullptr;
        while (current) {
            if (m_compare(key, current->value.first)) { // current->first > key
                result = current;
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return iterator(result, m_root);
    }

    std::pair<iterator, iterator> equal_range(const Key& key) {
        return std::make_pair(lower_bound(key), upper_bound(key));
    }

private:
    void transplant(Node* u, Node* v) {
        if (!u->parent) {
            m_root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v) {
            v->parent = u->parent;
        }
    }

    void count_helper(Node* node, const Key& key, size_type& count) const {
        if (!node) return;
        count_helper(node->left, key, count);
        if (keys_equal(node->value.first, key)) count++;
        count_helper(node->right, key, count);
    }
};
