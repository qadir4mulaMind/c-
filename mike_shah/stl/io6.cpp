#include <cstdio>       // std::fopen, std::fprintf, std::getc, std::fgets, std::rewind, std::fclose
#include <ctime>        // std::tm
#include <format>       // std::make_format_args
#include <fstream>      // basic_filebuf, basic_ifstream, basic_ofstream, basic_fstream (+ wchar_t)
#include <iomanip>      // resetiosflags, setiosflags, setbase, setfill, setprecision, setw, get_money, put_money, get_time, put_time, quoted
#include <ios>          // ios_base, basic_ios, streamoff, streamsize, fpos, io_errc, iostream_category, boolalpha, showbase, fixed, scientific, hexfloat, etc.
#include <iosfwd>       // streampos, wstreampos, u8streampos, u16streampos, u32streampos
#include <iostream>     // cin, wcin, cout, wcout, cerr, wcerr, clog, wclog
#include <istream>      // basic_istream, basic_iostream, std::ws
#include <limits>       // std::numeric_limits
#include <locale>       // std::locale
#include <ostream>      // basic_ostream, std::endl, std::ends, std::flush
#include <span>         // std::span
#include <sstream>      // basic_stringbuf, basic_istringstream, basic_ostringstream, basic_stringstream (+ wchar_t)
#include <streambuf>    // basic_streambuf (+ wchar_t)
#include <string>       // std::string, std::wstring, std::getline
#include <system_error> // std::error_code
#include <version>      // __cpp_lib_spanstream, __cpp_lib_syncbuf, __cpp_lib_print

#if __has_include(<spanstream>)
#include <spanstream>   // basic_spanbuf, basic_ispanstream, basic_ospanstream, basic_spanstream (+ wchar_t)
#endif

#if __has_include(<syncstream>)
#include <syncstream>   // basic_syncbuf, basic_osyncstream, emit_on_flush, noemit_on_flush, flush_emit (+ wchar_t)
#endif

#if __has_include(<print>)
#include <print>        // std::print, std::println, vprint_unicode[_buffered], vprint_nonunicode[_buffered]
#endif

// -----------------------------------------------------------------------------
// Custom Device inheriting from <streambuf> (std::basic_streambuf)
// Exercises abstract <ios>, <streambuf>, <istream>, <ostream>, <iostream>
// -----------------------------------------------------------------------------
template <typename CharT>
class MemoryRingBuf : public std::basic_streambuf<CharT> {
    CharT buf_[256]{};
public:
    MemoryRingBuf() {
        this->setp(buf_, buf_ + 256);
        this->setg(buf_, buf_, buf_);
    }
protected:
    typename std::basic_streambuf<CharT>::int_type overflow(
        typename std::basic_streambuf<CharT>::int_type ch) override {
        if (ch != std::char_traits<CharT>::eof() && this->pptr() < this->epptr()) {
            *this->pptr() = std::char_traits<CharT>::to_char_type(ch);
            this->pbump(1);
            this->setg(buf_, this->gptr(), this->pptr());
            return ch;
        }
        return std::char_traits<CharT>::eof();
    }
    int sync() override {
        this->setg(buf_, this->gptr(), this->pptr());
        return 0;
    }
};

int main() {
    // =========================================================================
    // 1. ABSTRACTION LAYER (<ios>, <streambuf>, <istream>, <ostream>, <iostream>)
    // =========================================================================
    std::cout << "=== 1. Abstraction Layer & Custom Streambuf ===\n";
    MemoryRingBuf<char> raw_dev;
    MemoryRingBuf<wchar_t> wraw_dev;

    std::iostream custom_io(&raw_dev);
    std::wiostream wcustom_io(&wraw_dev);

    // Properties & state of ios_base / basic_ios
    custom_io.flags(std::ios_base::dec | std::ios_base::showbase | std::ios_base::boolalpha);
    custom_io.precision(4);
    custom_io.width(6);
    custom_io.fill('_');
    custom_io.exceptions(std::ios_base::badbit);
    std::streambuf* tied_buf = custom_io.rdbuf();
    (void)tied_buf; (void)wcustom_io;

    // basic_ostream::sentry & formatted/unformatted writes
    {
        std::ostream::sentry os_ok(custom_io);
        if (os_ok) {
            custom_io << true << ' ';
            custom_io.put('4');
            custom_io.write("2\n", 2);
            custom_io.flush();
        }
    }

    // basic_istream::sentry, peek, get, putback, unget, tellg, seekg
    {
        std::istream::sentry is_ok(custom_io);
        if (is_ok) {
            bool b_val = false;
            int i_val = 0;
            custom_io >> b_val;
            custom_io.ignore(1); // skip space
            char peeked = static_cast<char>(custom_io.peek());
            custom_io >> i_val;
            std::cout << "Custom streambuf read -> bool: " << std::boolalpha << b_val
                      << ", peeked: '" << peeked << "', int: " << i_val << '\n';
        }
    }

    // =========================================================================
    // 2. PREDEFINED STANDARD STREAM OBJECTS (<iostream>)
    // =========================================================================
    std::cout << "\n=== 2. Standard Stream Objects ===\n";
    std::cout  << "[cout]  Standard narrow output\n";
    std::clog  << "[clog]  Buffered narrow log\n";
    std::cerr  << "[cerr]  Unbuffered narrow error\n";
    std::wcout << L"[wcout] Standard wide output\n";
    std::wclog << L"[wclog] Buffered wide log\n";
    std::wcerr << L"[wcerr] Unbuffered wide error\n";
    (void)std::cin.rdbuf();
    (void)std::wcin.rdbuf();

    // =========================================================================
    // 3. ALL MANIPULATORS (<ios>, <istream>, <ostream>, <iomanip>)
    // =========================================================================
    std::cout << "\n=== 3. I/O Manipulators ===\n";
    double pi = 3.1415926535;
    std::cout << std::showbase << std::uppercase
              << "Bases -> dec: " << std::dec << 255
              << " | hex: " << std::hex << 255
              << " | oct: " << std::oct << 255
              << std::noshowbase << std::nouppercase << std::dec << '\n';

    std::cout << std::setprecision(4)
              << "Float -> default: " << std::defaultfloat << pi
              << " | fixed: " << std::fixed << pi
              << " | scientific: " << std::scientific << pi
              << " | hexfloat: " << std::hexfloat << pi
              << std::defaultfloat << '\n';

    std::cout << "Align -> [" << std::setfill('.') << std::left << std::setw(8) << -42 << "] ["
              << std::right << std::setw(8) << -42 << "] ["
              << std::internal << std::setw(8) << -42 << "]" << std::setfill(' ') << '\n';

    std::cout << std::setiosflags(std::ios_base::showpos) << "showpos: " << 99
              << std::resetiosflags(std::ios_base::showpos) << " | reset: " << 99
              << " | setbase(16): " << std::setbase(16) << 255 << std::dec << '\n';

    // ws, ends, flush, endl, unitbuf
    std::istringstream ws_in("   Trimmed");
    std::string trimmed;
    ws_in >> std::ws >> trimmed;
    std::ostringstream null_ss;
    null_ss << "ABC" << std::ends;
    std::cout << std::unitbuf << "ws: '" << trimmed << "', ends size: " << null_ss.str().size()
              << std::nounitbuf << std::endl;

    // put_money / get_money, put_time / get_time, quoted
    std::stringstream loc_ss;
    loc_ss.imbue(std::locale("en_US.UTF-8"));
    loc_ss << std::showbase << std::put_money(123456) << '\n';
    long double cents = 0;
    loc_ss >> std::get_money(cents);

    loc_ss.clear();
    std::tm tm_in{};
    tm_in.tm_year = 126; // 2026
    tm_in.tm_mon = 10;   // Nov
    tm_in.tm_mday = 23;
    loc_ss << std::put_time(&tm_in, "%Y-%m-%d") << '\n';
    std::tm tm_out{};
    loc_ss >> std::get_time(&tm_out, "%Y-%m-%d");

    loc_ss.clear();
    std::string raw_quote = R"(Text with "quotes")";
    std::string unquoted;
    loc_ss << std::quoted(raw_quote);
    loc_ss >> std::quoted(unquoted);
    std::cout << "Money: " << cents << " cents | Year: " << (tm_out.tm_year + 1900)
              << " | Quoted: " << unquoted << '\n';

    // =========================================================================
    // 4. FILE I/O (<fstream>) - Narrow & Wide Buffers and Streams
    // =========================================================================
    std::cout << "\n=== 4. File Streams & Buffers ===\n";
    std::filebuf fb;
    fb.open("demo_filebuf.txt", std::ios::out | std::ios::trunc);
    fb.sputn("Raw filebuf line\n", 17);
    fb.close();

    std::wfilebuf wfb;
    wfb.open("demo_wfilebuf.txt", std::ios::out | std::ios::trunc);
    wfb.sputn(L"Raw wfilebuf line\n", 18);
    wfb.close();

    {
        std::ofstream ofs("demo_stream.txt");
        ofs << "Line1\n";
    }
    {
        std::fstream fs("demo_stream.txt", std::ios::in | std::ios::out | std::ios::app);
        fs << "Line2\n";
        fs.seekg(0);
        std::string f_line;
        std::getline(fs, f_line);
        std::cout << "Read from fstream -> " << f_line << '\n';
    }
    {
        std::ifstream ifs("demo_stream.txt");
        std::wofstream wofs("demo_wstream.txt");
        wofs << L"WideFileLine\n";
        wofs.close();
        std::wifstream wifs("demo_wstream.txt");
        std::wfstream wfs("demo_wstream.txt", std::ios::in | std::ios::out);
        (void)ifs; (void)wifs; (void)wfs;
    }

    // =========================================================================
    // 5. STRING I/O (<sstream>) - Narrow & Wide
    // =========================================================================
    std::cout << "\n=== 5. String Streams & Buffers ===\n";
    std::stringbuf sbuf("Init");
    std::wstringbuf wsbuf(L"WInit");

    std::ostringstream oss;
    oss << "Item " << 7;
    std::istringstream iss(oss.str());
    std::stringstream ss;
    ss << iss.str() << " -> Bidirectional";
    std::cout << "stringstream -> " << ss.str() << '\n';

    std::wostringstream woss;
    woss << L"WItem " << 7;
    std::wistringstream wiss(woss.str());
    std::wstringstream wss;
    wss << wiss.str();

    // =========================================================================
    // 6. ARRAY / FIXED-BUFFER I/O (<spanstream>, C++23) - Narrow & Wide
    // =========================================================================
    std::cout << "\n=== 6. Span Streams (C++23) ===\n";
#if defined(__cpp_lib_spanstream) && __cpp_lib_spanstream >= 202106L
    char span_buf[64]{};
    std::spanbuf sp_b{std::span<char>(span_buf)};
    std::ospanstream osp{std::span<char>(span_buf)};
    osp << "ZeroAllocSpan 123";
    std::ispanstream isp{std::span<const char>(span_buf)};
    std::spanstream sp_io{std::span<char>(span_buf)};
    std::cout << "spanstream -> " << span_buf << '\n';

    wchar_t wspan_buf[64]{};
    std::wspanbuf wsp_b{std::span<wchar_t>(wspan_buf)};
    std::wospanstream wosp{std::span<wchar_t>(wspan_buf)};
    std::wispanstream wisp{std::span<const wchar_t>(wspan_buf)};
    std::wspanstream wsp_io{std::span<wchar_t>(wspan_buf)};
#else
    std::cout << "[Note] <spanstream> not enabled in this libc++\n";
#endif

    // =========================================================================
    // 7. SYNCHRONIZED OUTPUT (<syncstream>, C++20) - Narrow & Wide
    // =========================================================================
    std::cout << "\n=== 7. Synchronized Output (C++20) ===\n";
#if defined(__cpp_lib_syncbuf) && __cpp_lib_syncbuf >= 201803L
    {
        std::syncbuf sb(std::cout.rdbuf());
        std::ostream sb_out(&sb);
        sb_out << "Atomic flush via std::syncbuf\n";
    }
    {
        std::osyncstream sync_out(std::cout);
        sync_out << std::noemit_on_flush << "Buffered... " << std::flush
                 << std::emit_on_flush << "Emitted via std::osyncstream!\n" << std::flush_emit;
    }
    {
        std::wsyncbuf wsb(std::wcout.rdbuf());
        std::wosyncstream wsync_out(std::wcout);
        wsync_out << L"Wide sync flush\n";
    }
#else
    std::cout << "[Note] <syncstream> not enabled in this libc++\n";
#endif

    // =========================================================================
    // 8. POSITION TYPES (<ios>, <iosfwd>) & ERROR CATEGORY (C++11)
    // =========================================================================
    std::cout << "\n=== 8. Position Types & Error Category ===\n";
    std::streamoff off = 16;
    std::streamsize sz = 32;
    std::streampos p1(off);
    std::wstreampos p2(off);
    std::u8streampos p3(off);
    std::u16streampos p4(off);
    std::u32streampos p5(off);
    (void)sz; (void)p1; (void)p2; (void)p3; (void)p4; (void)p5;

    std::error_code ec = std::make_error_code(std::io_errc::stream);
    std::cout << "Category: " << std::iostream_category().name()
              << " | Error: " << ec.message() << '\n';

    // =========================================================================
    // 9. C++23 PRINT FAMILY (<print>, <ostream>)
    // =========================================================================
    std::cout << "\n=== 9. C++23 std::print / std::println ===\n";
#if defined(__cpp_lib_print) && __cpp_lib_print >= 202207L
    std::print("std::print -> {}, ", 2026);
    std::println("std::println -> {:#x}", 2026);
    std::print(std::cout, "std::print(ostream) -> {}, ", "ok");
    std::println(std::cout, "std::println(ostream) -> {}", "done");

    int v = 99;
    auto args = std::make_format_args(v);
    std::vprint_unicode("vprint_unicode -> {}\n", args);
    std::vprint_nonunicode("vprint_nonunicode -> {}\n", args);
    #if __cpp_lib_print >= 202403L
    std::vprint_unicode_buffered("vprint_unicode_buffered -> {}\n", args);
    std::vprint_nonunicode_buffered("vprint_nonunicode_buffered -> {}\n", args);
    #endif
#else
    std::cout << "[Note] <print> not enabled in this libc++\n";
#endif

    // =========================================================================
    // 10. C-STYLE I/O (<cstdio>)
    // =========================================================================
    std::cout << "\n=== 10. C-Style I/O (<cstdio>) ===\n";
    if (std::FILE* fp = std::fopen("demo_cstdio.txt", "w+")) {
        std::fprintf(fp, "Z-CStyleLine\n");
        std::rewind(fp);
        int first_char = std::getc(fp);
        char rest[32]{};
        std::fgets(rest, sizeof(rest), fp);
        std::cout << "getc: '" << static_cast<char>(first_char) << "' | fgets: " << rest;
        std::fclose(fp);
    }

    return 0;
}
