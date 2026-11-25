#include <iostream> // std::cout, std::wcout, std::cerr, std::wcerr, std::clog, std::wclog
#include <ostream>  // std::basic_ostream, std::ostream, std::wostream, std::endl, std::ends, std::flush
#include <sstream>  // std::ostringstream, std::wostringstream
#include <string>   // std::string, std::wstring
#include <version>  // __cpp_lib_print, __cpp_lib_syncbuf

#if __has_include(<print>)
#include <print>    // std::print(ostream), std::println(ostream)
#endif

#if __has_include(<syncstream>)
#include <syncstream> // std::osyncstream, std::emit_on_flush, std::noemit_on_flush, std::flush_emit
#endif

int main() {
    // 1. Typedefs & Six Global Objects (<ostream>, <iostream>)
    std::cout << "--- 1. Six Global Objects ---\n";
    std::cout << "[std::cout] Standard output\n";
    std::clog << "[std::clog] Buffered log stream\n";
    std::cerr << "[std::cerr] Unbuffered error stream\n";

    std::wcout << L"[std::wcout] Wide standard output\n";
    std::wclog << L"[std::wclog] Wide buffered log stream\n";
    std::wcerr << L"[std::wcerr] Wide unbuffered error stream\n";

    // 2. Member Types (char_type, traits_type, int_type, pos_type, off_type)
    using OStream = std::ostream;
    using CharT   = OStream::char_type;
    using Traits  = OStream::traits_type;
    using IntT    = OStream::int_type;
    using PosT    = OStream::pos_type;
    using OffT    = OStream::off_type;
    (void)sizeof(Traits); (void)sizeof(IntT);

    // 3. Formatted Output: operator<< & Manipulators (endl, ends, flush)
    std::cout << "\n--- 2. Formatted Output & Manipulators ---\n";
    std::ostringstream fmt_out;
    fmt_out << true << ' ' << 42 << ' ' << 3.14159 << ' ' << "Text" << std::endl; // '\n' + flush()
    fmt_out.flush(); // Explicit flush()

    std::ostringstream null_out;
    null_out << "NullTerminated" << std::ends; // Inserts '\0'
    std::cout << "Formatted: " << fmt_out.str()
              << "Null-terminated length: " << null_out.str().size() << '\n';

    // 4. Unformatted Output Methods: put() & write()
    std::cout << "\n--- 3. Unformatted Output (put & write) ---\n";
    std::ostringstream raw_out;
    raw_out.put('A');
    raw_out.put('B');
    const CharT block[] = "CDEFG";
    raw_out.write(block, 5);
    std::cout << "put() + write(): " << raw_out.str() << '\n';

    // 5. Positioning: tellp() & seekp()
    std::cout << "\n--- 4. Positioning (tellp & seekp) ---\n";
    std::ostringstream pos_out("0123456789");
    pos_out.seekp(4, std::ios_base::beg); // Move put pointer to index 4
    PosT current_pos = pos_out.tellp();   // Record position
    pos_out.put('X');                     // Overwrite '4' with 'X'
    pos_out.seekp(OffT(2), std::ios_base::cur); // Advance 2 bytes to index 7
    pos_out.put('Y');                     // Overwrite '7' with 'Y'
    std::cout << "tellp() was " << current_pos << " -> result: " << pos_out.str() << '\n';

    // 6. Helper Class: std::basic_ostream::sentry
    std::cout << "\n--- 5. std::basic_ostream::sentry ---\n";
    std::ostringstream sentry_out;
    {
        OStream::sentry ok(sentry_out); // Flushes tied stream & checks good()
        if (ok) {
            sentry_out << "Written safely inside sentry scope";
        }
    } // Destructor flushes if unitbuf is set
    std::cout << sentry_out.str() << '\n';

    // 7. C++20 Syncstream Manipulators (emit_on_flush, noemit_on_flush, flush_emit)
    std::cout << "\n--- 6. C++20 Syncstream Manipulators ---\n";
#if defined(__cpp_lib_syncbuf) && __cpp_lib_syncbuf >= 201803L
    {
        std::osyncstream sync_out(std::cout);
        sync_out << std::noemit_on_flush << "Held in syncbuf..." << std::flush;
        sync_out << std::emit_on_flush << "Emitted via flush_emit!\n" << std::flush_emit;
    }
#else
    std::cout << "[Skipped C++20 syncstream manipulators: not enabled in this libc++]\n";
#endif

    // 8. C++23 Non-Member Functions: std::print(ostream) & std::println(ostream)
    std::cout << "\n--- 7. C++23 std::print / std::println (<ostream>) ---\n";
#if defined(__cpp_lib_print) && __cpp_lib_print >= 202207L
    std::print(std::cout, "std::print(ostream): {} + {} = ", 20, 22);
    std::println(std::cout, "{}", 42);
#else
    std::cout << "[Skipped C++23 std::print(ostream): not enabled in this libc++]\n";
#endif

    return 0;
}
