// ============================================================================
// SYSTEM REGISTRY HEADERS
// ============================================================================
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <compare>
#include <format>
#include <tuple> 

namespace mystd {

    // ============================================================================
    // 1. CORE ENGINE LAYOUT: THE PAIR CLASS TEMPLATE
    // ============================================================================
    template <typename T1, typename T2>
    struct pair {
        // Member Types
        using first_type  = T1;
        using second_type = T2;

        // Member Objects
        T1 first;
        T2 second;

        // --- Member Functions: Constructors ---
        // 1. Default constructor
        constexpr pair() : first(), second() {}

        // 2. Direct initialization constructor
        constexpr pair(const T1& x, const T2& y) : first(x), second(y) {}

        // 3. Perfect forwarding constructor
        template <typename U1, typename U2>
        constexpr pair(U1&& x, U2&& y) 
            : first(std::forward<U1>(x)), second(std::forward<U2>(y)) {}

        // 4. Converting constructor from alternative pair templates
        template <typename U1, typename U2>
            requires std::is_constructible_v<T1, const U1&> && std::is_constructible_v<T2, const U2&>
        constexpr pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

        // 5. Converting move constructor from alternative pair templates
        template <typename U1, typename U2>
            requires std::is_constructible_v<T1, U1&&> && std::is_constructible_v<T2, U2&&>
        constexpr pair(pair<U1, U2>&& p) : first(std::move(p.first)), second(std::move(p.second)) {}

        // --- Member Functions: Assignment Operators ---
        constexpr pair& operator=(const pair& other) {
            first = other.first;
            second = other.second;
            return *this;
        }

        template <typename U1, typename U2>
        constexpr pair& operator=(const pair<U1, U2>& other) {
            first = other.first;
            second = other.second;
            return *this;
        }

        constexpr pair& operator=(pair&& other) noexcept(
            std::is_nothrow_move_assignable_v<T1> && std::is_nothrow_move_assignable_v<T2>
        ) {
            first = std::move(other.first);
            second = std::move(other.second);
            return *this;
        }

        template <typename U1, typename U2>
        constexpr pair& operator=(pair<U1, U2>&& other) {
            first = std::move(other.first);
            second = std::move(other.second);
            return *this;
        }

        // --- Member Functions: Swap (C++11) ---
        constexpr void swap(pair& other) noexcept(
            noexcept(std::swap(first, other.first)) && noexcept(std::swap(second, other.second))
        ) {
            using std::swap;
            swap(first, other.first);
            swap(second, other.second);
        }
    };

    // ============================================================================
    // 2. CLASS TEMPLATE ARGUMENT DEDUCTION GUIDES (C++17)
    // ============================================================================
    template <typename T1, typename T2>
    pair(T1, T2) -> pair<T1, T2>;

    // ============================================================================
    // 3. FACTORY AND NON-MEMBER UTILITY FUNCTIONS
    // ============================================================================
    template <typename T1, typename T2>
    constexpr pair<std::decay_t<T1>, std::decay_t<T2>> make_pair(T1&& x, T2&& y) {
        return pair<std::decay_t<T1>, std::decay_t<T2>>(std::forward<T1>(x), std::forward<T2>(y));
    }

    template <typename T1, typename T2>
    constexpr void swap(pair<T1, T2>& x, pair<T1, T2>& y) noexcept(noexcept(x.swap(y))) {
        x.swap(y);
    }

    // ============================================================================
    // 4. MODERN OPERATORS & LEXICOGRAPHICAL COMPARISONS (C++20)
    // ============================================================================
    template <typename T1, typename T2>
    constexpr bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <typename T1, typename T2>
    constexpr auto operator<=>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
        if (auto cmp = lhs.first <=> rhs.first; cmp != 0) return cmp;
        return lhs.second <=> rhs.second;
    }

    // ============================================================================
    // 5. TUPLE INTERFACE STUBS (ADL get overloads inside mystd namespace)
    // ============================================================================
    template <std::size_t I, typename T1, typename T2>
    constexpr decltype(auto) get(pair<T1, T2>& p) noexcept {
        static_assert(I < 2, "Index out of bounds for mystd::pair!");
        if constexpr (I == 0) return (p.first);
        else return (p.second);
    }

    template <std::size_t I, typename T1, typename T2>
    constexpr decltype(auto) get(const pair<T1, T2>& p) noexcept {
        static_assert(I < 2, "Index out of bounds for mystd::pair!");
        if constexpr (I == 0) return (p.first);
        else return (p.second);
    }

    template <std::size_t I, typename T1, typename T2>
    constexpr decltype(auto) get(pair<T1, T2>&& p) noexcept {
        static_assert(I < 2, "Index out of bounds for mystd::pair!");
        if constexpr (I == 0) return std::move(p.first);
        else return std::move(p.second);
    }

    template <std::size_t I, typename T1, typename T2>
    constexpr decltype(auto) get(const pair<T1, T2>&& p) noexcept {
        static_assert(I < 2, "Index out of bounds for mystd::pair!");
        if constexpr (I == 0) return std::move(p.first);
        else return std::move(p.second);
    }
} // namespace mystd

// ============================================================================
// 6. METAPROGRAMMING ADAPTERS FOR STD BINDINGS (Structured Binding Support)
// ============================================================================
namespace std {
    // 1. Structural Binding Size Mappings
    template <typename T1, typename T2>
    struct tuple_size<mystd::pair<T1, T2>> : std::integral_constant<std::size_t, 2> {};

    // 2. Core structural type extractors supporting full cv-qualification tracking
    template <std::size_t I, typename T1, typename T2>
    struct tuple_element<I, mystd::pair<T1, T2>> {
        static_assert(I < 2, "Index out of bounds for mystd::pair element!");
        using type = std::conditional_t<I == 0, T1, T2>;
    };

    template <std::size_t I, typename T1, typename T2>
    struct tuple_element<I, const mystd::pair<T1, T2>> {
        static_assert(I < 2, "Index out of bounds for mystd::pair element!");
        using type = std::add_const_t<std::conditional_t<I == 0, T1, T2>>;
    };

    template <std::size_t I, typename T1, typename T2>
    struct tuple_element<I, volatile mystd::pair<T1, T2>> {
        static_assert(I < 2, "Index out of bounds for mystd::pair element!");
        using type = std::add_volatile_t<std::conditional_t<I == 0, T1, T2>>;
    };

    template <std::size_t I, typename T1, typename T2>
    struct tuple_element<I, const volatile mystd::pair<T1, T2>> {
        static_assert(I < 2, "Index out of bounds for mystd::pair element!");
        using type = std::add_cv_t<std::conditional_t<I == 0, T1, T2>>;
    };

    // 3. C++23 std::formatter Specialization Override
    template <typename T1, typename T2, typename CharT>
    struct formatter<mystd::pair<T1, T2>, CharT> : formatter<basic_string<CharT>, CharT> {
        template <typename FormatContext>
        auto format(const mystd::pair<T1, T2>& p, FormatContext& ctx) const {
            return format_to(ctx.out(), "({}, {})", p.first, p.second);
        }
    };

    // 4. C++23 enable_nonlocking_formatter_optimization Specialized Trait
    template <typename T, typename U>
    constexpr bool enable_nonlocking_formatter_optimization<mystd::pair<T, U>> =
        enable_nonlocking_formatter_optimization<T> && enable_nonlocking_formatter_optimization<U>;

} // namespace std

// ============================================================================
// CONSOLE PRINT LOGGER ASSISTANT
// ============================================================================
void print_title(std::string_view title) {
    std::cout << "\n=======================================================\n"
              << " " << title << "\n"
              << "=======================================================\n";
}

// ============================================================================
// MAIN SYSTEM DIAGNOSTICS DRIVER
// ============================================================================
int main() {
    // 1. Initialization and Constructors Verification
    print_title("1. INITIALIZATION & CONVERSION CONSTRUCTORS");
    
    mystd::pair<int, std::string> p1(200, "OK");
    mystd::pair p2(404, std::string("Not Found")); // CTAD Deduction check
    
    // Converting element check (int -> double, string -> string)
    mystd::pair<double, std::string> p3 = p1; 
    
    std::cout << "p1 contents: [" << p1.first << ", " << p1.second << "]\n";
    std::cout << "p3 (Converted components): [" << p3.first << ", " << p3.second << "]\n";

    // 2. Modifiers & Assignment Testing
    print_title("2. MODIFIERS & ASSIGNMENT VALUES");
    
    mystd::pair<int, int> src(10, 20);
    mystd::pair<int, int> dst(99, 99);
    
    dst = src; // Copy assignment check
    std::cout << "dst values after basic copy assignment: (" << dst.first << ", " << dst.second << ")\n";

    return 0;
}
