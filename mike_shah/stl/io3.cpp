#include <ctime>        // std::tm
#include <iomanip>      // resetiosflags, setiosflags, setbase, setfill, setprecision, setw, get_money, put_money, get_time, put_time, quoted
#include <ios>          // boolalpha, showbase, showpoint, showpos, skipws, uppercase, unitbuf, internal, left, right, dec, hex, oct, fixed, scientific, hexfloat, defaultfloat
#include <iostream>     // std::cout, std::endl, std::flush, std::ends, std::ws
#include <locale>       // std::locale
#include <sstream>      // std::stringstream
#include <string>       // std::string
#include <version>      // __cpp_lib_syncbuf

#if __has_include(<syncstream>)
#include <syncstream>   // std::osyncstream, emit_on_flush, noemit_on_flush, flush_emit
#endif

int main() {
    // 1. Boolean, Base, Sign & Case Manipulators (<ios>)
    std::cout << "--- 1. <ios> Flags & Bases ---\n";
    std::cout << std::boolalpha << true << " | " << std::noboolalpha << true << '\n';
    std::cout << std::showbase << std::uppercase
              << "dec: " << std::dec << 255
              << " | hex: " << std::hex << 255
              << " | oct: " << std::oct << 255
              << std::noshowbase << std::nouppercase << std::dec << '\n';
    std::cout << std::showpos << 42 << " | " << std::noshowpos << 42 << '\n';

    // 2. Floating-Point Formatting (<ios> & <iomanip>)
    std::cout << "\n--- 2. Floating-Point Manipulators ---\n";
    double pi = 3.1415926535;
    std::cout << std::setprecision(4)
              << "defaultfloat: " << std::defaultfloat << pi << '\n'
              << "fixed:        " << std::fixed << pi << '\n'
              << "scientific:   " << std::scientific << pi << '\n'
              << "hexfloat:     " << std::hexfloat << pi << '\n'
              << std::defaultfloat << std::showpoint << "showpoint:    " << 5.0
              << std::noshowpoint << '\n';

    // 3. Field Width, Fill & Alignment (<ios> & <iomanip>)
    std::cout << "\n--- 3. Width, Fill & Alignment ---\n";
    std::cout << std::setfill('.')
              << "left:     [" << std::left << std::setw(10) << -42 << "]\n"
              << "right:    [" << std::right << std::setw(10) << -42 << "]\n"
              << "internal: [" << std::internal << std::setw(10) << -42 << "]\n"
              << std::setfill(' ');

    // 4. Flag Masks & Base Helper (<iomanip>)
    std::cout << "\n--- 4. setiosflags / resetiosflags / setbase ---\n";
    std::cout << std::setiosflags(std::ios_base::hex | std::ios_base::showbase)
              << 255 << ' '
              << std::resetiosflags(std::ios_base::showbase) << 255 << '\n'
              << "setbase(10): " << std::setbase(10) << 255 << '\n';

    // 5. Stream Control & Whitespace (<istream>, <ostream>, <ios>)
    std::cout << "\n--- 5. ws, ends, flush, endl, unitbuf ---\n";
    std::istringstream ws_in("   hello");
    std::string word;
    ws_in >> std::ws >> word; // Consumes leading whitespace
    std::cout << "After std::ws: '" << word << "'" << std::endl; // '\n' + flush

    std::ostringstream null_out;
    null_out << "C-string" << std::ends; // Appends '\0'
    std::cout << "Null-terminated size: " << null_out.str().size() << '\n';

    std::cout << std::unitbuf << "Auto-flushed via unitbuf\n" << std::nounitbuf << std::flush;

    // 6. C++20 Syncstream Manipulators (<ostream> / <syncstream>)
    std::cout << "\n--- 6. C++20 emit_on_flush / noemit_on_flush / flush_emit ---\n";
#if defined(__cpp_lib_syncbuf) && __cpp_lib_syncbuf >= 201803L
    {
        std::osyncstream sync_out(std::cout);
        sync_out << std::noemit_on_flush << "Buffered in syncbuf...\n" << std::flush;
        sync_out << std::emit_on_flush << "Emitted on flush_emit!\n" << std::flush_emit;
    }
#else
    std::cout << "[Skipped C++20 syncstream manipulators: not enabled in this libc++]\n";
#endif

    // 7. C++11 Monetary & Date/Time & C++14 Quoted Manipulators (<iomanip>)
    std::cout << "\n--- 7. put_money/get_money, put_time/get_time, quoted ---\n";
    std::stringstream ss;
    ss.imbue(std::locale("en_US.UTF-8"));

    // Monetary (value in cents: 123456 -> $1,234.56)
    ss << std::showbase << std::put_money(123456) << '\n';
    long double cents = 0;
    ss >> std::get_money(cents);
    std::cout << "Parsed money (cents): " << cents << '\n';

    // Date / Time
    ss.clear();
    std::tm tm_val{};
    tm_val.tm_year = 126; // 2026
    tm_val.tm_mon = 10;   // November (0-based)
    tm_val.tm_mday = 23;
    ss << std::put_time(&tm_val, "%Y-%m-%d") << '\n';
    std::tm parsed_tm{};
    ss >> std::get_time(&parsed_tm, "%Y-%m-%d");
    std::cout << "Parsed year: " << (parsed_tm.tm_year + 1900) << '\n';

    // Quoted strings (C++14)
    ss.clear();
    std::string original = R"(Hello "C++14" world)";
    std::string roundtrip;
    ss << std::quoted(original);
    std::cout << "Serialized quoted: " << ss.str() << '\n';
    ss >> std::quoted(roundtrip);
    std::cout << "Extracted unquoted: " << roundtrip << '\n';

    return 0;
}
