// ============================================================================
// SYSTEM REGISTRY HEADERS
// ============================================================================
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <compare>
#include <format>
#include <tuple> // Provides primary definition of std::tuple_size

// ============================================================================
// 1. CORE STRUCTURAL LAYOUT: PAIR FROM SCRATCH
// ============================================================================
namespace mystd {

    template <typename T1, typename T2>
    struct pair {
        // Member Types
        using first_type  = T1;
        using second_type = T2;

        // Member Objects
        T1 first;
        T2 second;

        // Rule of Zero Constructor Setups
        constexpr pair() = default;
        constexpr pair(const T1& x, const T2& y) : first(x), second(y) {}
        
        // Universal forwarding constructor matching standard library design
        template <typename U1, typename U2>
        constexpr pair(U1&& x, U2&& y) 
            : first(std::forward<U1>(x)), second(std::forward<U2>(y)) {}

        // Custom Member Swap Implementation (Since C++11)
        constexpr void swap(pair& other) noexcept(
            noexcept(std::swap(first, other.first)) && noexcept(std::swap(second, other.second))
        ) {
            using std::swap;
            swap(first, other.first);
            swap(second, other.second);
        }
    };

    // ============================================================================
    // 2. MODERN C++17 DEDUCTION GUIDES
    // ============================================================================
    template <typename T1, typename T2>
    pair(T1, T2) -> pair<T1, T2>;

    // ============================================================================
    // 3. FACTORY AND NON-MEMBER ALGORITHMS
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
    // 4. MODERN C++20 LEXICOGRAPHICAL COMPARISONS
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
    // 1. Map type size
    template <typename T1, typename T2>
    struct tuple_size<mystd::pair<T1, T2>> : std::integral_constant<std::size_t, 2> {};

    // 2. Map type elements with full cv-qualification passthrough support
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

    // Note: No duplicate std::get overloads are written here. 
    // Structured bindings will find mystd::get via ADL cleanly without any ambiguity!

    // C++23 std::formatter Specialization Override
    template <typename T1, typename T2, typename CharT>
    struct formatter<mystd::pair<T1, T2>, CharT> : formatter<basic_string<CharT>, CharT> {
        template <typename FormatContext>
        auto format(const mystd::pair<T1, T2>& p, FormatContext& ctx) const {
            return format_to(ctx.out(), "({}, {})", p.first, p.second);
        }
    };
} // namespace std

// ============================================================================
// HELPER LOOKUP: CONSOLE LOGGER FORMATTER
// ============================================================================
void print_title(std::string_view title) {
    std::cout << "\n=======================================================\n"
              << " " << title << "\n"
              << "=======================================================\n";
}

// ============================================================================
// SYSTEM REGISTRY DIAGNOSTICS DRIVER
// ============================================================================
int main() {
    // 1. Initialization and Deduction Guides Verification
    print_title("1. INITIALIZATION & DEDUCTION GUIDES");
    
    mystd::pair<int, std::string> p1(404, "Not Found"); 
    auto p2 = mystd::make_pair(200, std::string("OK")); 
    mystd::pair p3(302, std::string("Redirect"));        

    std::cout << "p1 contents: [" << p1.first << " -> " << p1.second << "]\n";
    std::cout << "p2 contents: [" << p2.first << " -> " << p2.second << "]\n";

    // 2. Structured Bindings and Metaprogramming Analysis
    print_title("2. C++11 STRUCTURED BINDINGS & DATA ADAPTERS");
    
    // Unpacking runs perfectly via ADL matching on mystd::get. 
    // CV qualifiers match exactly because of our const tuple_element specialization.
    auto [code, status] = p1;
    std::cout << "Unpacked via Structured Bindings -> Code: " << code << " | Status: " << status << "\n";
    
    const mystd::pair<int, std::string> const_p(500, "Internal Error");
    auto [c_code, c_status] = const_p; // Verifies const tracking binding compilation safely
    std::cout << "Unpacked Const -> Code: " << c_code << " | Status: " << c_status << "\n";

    std::cout << "Accessing via mystd::get<0>: " << mystd::get<0>(p1) << "\n";
    std::cout << "Compile-time Size Signature: " << std::tuple_size<decltype(p1)>::value << "\n";

    // 3. Three-Way Lexicographical Comparisons (C++20)
    print_title("3. C++20 THREE-WAY COMPARISONS (<=>)");
    
    mystd::pair alpha(10, 20);
    mystd::pair beta(10, 30);
    
    std::cout << std::boolalpha;
    std::cout << "Is alpha equal to beta? " << (alpha == beta) << "\n";
    std::cout << "Is alpha less than beta? " << ((alpha <=> beta) < 0) << "\n";

    // 4. Formatting Engine Support (C++23)
    print_title("4. C++23 STD::FORMAT REGISTRY PRINTING");
    
    std::cout << std::format("Formatted Pair Output Block: {}\n", p3);

    return 0;
}

