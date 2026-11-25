#include <cstdio>       // std::fopen, std::fprintf, std::getc, std::fgets, std::fclose
#include <format>       // std::make_format_args
#include <fstream>      // basic_filebuf, basic_ifstream, basic_ofstream, basic_fstream (+ wchar_t)
#include <iomanip>      // std::boolalpha, std::hex, std::showbase, std::setw
#include <ios>          // ios_base, basic_ios, streamoff, streamsize, fpos, io_errc, iostream_category
#include <iosfwd>       // streampos, wstreampos, u8streampos, u16streampos, u32streampos
#include <iostream>     // cin, wcin, cout, wcout, cerr, wcerr, clog, wclog
#include <istream>      // basic_istream, basic_iostream (+ wchar_t)
#include <ostream>      // basic_ostream (+ wchar_t)
#include <span>         // std::span
#include <sstream>      // basic_stringbuf, basic_istringstream, basic_ostringstream, basic_stringstream (+ wchar_t)
#include <streambuf>    // basic_streambuf (+ wchar_t)
#include <string>       // std::string, std::wstring, std::getline
#include <system_error> // std::error_code
#include <version>      // Standard C++ feature-test macros (__cpp_lib_*)

#if __has_include(<spanstream>)
#include <spanstream>
#endif

#if __has_include(<syncstream>)
#include <syncstream>
#endif

#if __has_include(<print>)
#include <print>
#endif

// -----------------------------------------------------------------------------
// 1. Custom Device inheriting from <streambuf> (std::basic_streambuf)
// -----------------------------------------------------------------------------
template <typename CharT>
class MemoryRingBuf : public std::basic_streambuf<CharT> {
    CharT buf_[128]{};
public:
    MemoryRingBuf() {
        this->setp(buf_, buf_ + 128);
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
    // A. ABSTRACTION LAYER (<ios>, <streambuf>, <istream>, <ostream>)
    // =========================================================================
    MemoryRingBuf<char> raw_dev;
    MemoryRingBuf<wchar_t> wraw_dev;

    std::iostream custom_io(&raw_dev);
    std::wiostream wcustom_io(&wraw_dev);

    custom_io.flags(std::ios_base::dec | std::ios_base::showbase | std::ios_base::boolalpha);
    custom_io.precision(4);
    custom_io.width(8);
    custom_io.fill('_');
    custom_io.exceptions(std::ios_base::badbit);
    std::streambuf* tied_buf = custom_io.rdbuf();
    (void)tied_buf;

    std::ostream& out_ref = custom_io;
    std::istream& in_ref = custom_io;
    out_ref << true << ' ' << 255 << '\n';
    out_ref.flush();

    bool b_val = false;
    int i_val = 0;
    in_ref >> b_val >> i_val;

    // =========================================================================
    // B. PREDEFINED STANDARD STREAM OBJECTS (<iostream>) & MANIPULATORS (<iomanip>)
    // =========================================================================
    std::cout << std::boolalpha << "Standard cout: " << b_val
              << " | hex: " << std::showbase << std::hex << i_val << std::dec << '\n';
    std::clog << "[std::clog] Buffered log message\n";
    std::cerr << "[std::cerr] Unbuffered error message\n";

    std::wcout << L"[std::wcout] Wide output active\n";
    std::wclog << L"[std::wclog] Wide log active\n";
    std::wcerr << L"[std::wcerr] Wide error active\n";
    auto* cin_buf = std::cin.rdbuf();
    auto* wcin_buf = std::wcin.rdbuf();
    (void)cin_buf; (void)wcin_buf;

    // =========================================================================
    // C. FILE I/O IMPLEMENTATION (<fstream>) - Narrow & Wide
    // =========================================================================
    std::filebuf fb;
    fb.open("raw_filebuf.txt", std::ios::out | std::ios::trunc);
    fb.sputn("Raw std::filebuf write\n", 23);
    fb.close();

    std::wfilebuf wfb;
    wfb.open("raw_wfilebuf.txt", std::ios::out | std::ios::trunc);
    wfb.sputn(L"Raw std::wfilebuf write\n", 24);
    wfb.close();

    {
        std::ofstream ofs("stream_file.txt");
        ofs << "LineOne 100\n";
    }
    {
        std::ifstream ifs("stream_file.txt");
        std::string token;
        int num = 0;
        ifs >> token >> num;
    }
    {
        std::fstream fs("stream_file.txt", std::ios::in | std::ios::out | std::ios::app);
        fs << "LineTwo 200\n";
        fs.seekg(0);
        std::string line;
        std::getline(fs, line);
    }

    {
        std::wofstream wofs("wstream_file.txt");
        wofs << L"WideLine 300\n";
    }
    {
        std::wifstream wifs("wstream_file.txt");
        std::wstring wtok;
        wifs >> wtok;
    }
    {
        std::wfstream wfs("wstream_file.txt", std::ios::in | std::ios::out | std::ios::app);
        wfs << L"WideAppend\n";
    }

    // =========================================================================
    // D. STRING I/O IMPLEMENTATION (<sstream>) - Narrow & Wide
    // =========================================================================
    std::stringbuf sbuf("InitialBuffer");
    std::wstringbuf wsbuf(L"InitialWideBuffer");

    std::ostringstream oss;
    oss << "Formatted " << 42;
    std::istringstream iss(oss.str());
    std::string s_word;
    int s_num = 0;
    iss >> s_word >> s_num;

    std::stringstream ss;
    ss << "Bidirectional 99";
    ss >> s_word >> s_num;

    std::wostringstream woss;
    woss << L"WideFormatted " << 77;
    std::wistringstream wiss(woss.str());
    std::wstring ws_word;
    wiss >> ws_word;
    std::wstringstream wss;
    wss << L"WideBidirectional";

    // =========================================================================
    // E. ARRAY / FIXED-BUFFER I/O (<spanstream>, C++23) - Narrow & Wide
    // =========================================================================
#if defined(__cpp_lib_spanstream) && __cpp_lib_spanstream >= 202106L
    char raw_arr[64]{};
    std::spanbuf sp_buf{std::span<char>(raw_arr)};

    std::ospanstream osp{std::span<char>(raw_arr)};
    osp << "SpanWrite " << 512;

    std::ispanstream isp{std::span<const char>(raw_arr)};
    std::string sp_tok;
    int sp_val = 0;
    isp >> sp_tok >> sp_val;

    char bidir_arr[64]{};
    std::spanstream sp_io{std::span<char>(bidir_arr)};
    sp_io << "InOutSpan 1024";
    sp_io >> sp_tok >> sp_val;

    wchar_t wraw_arr[64]{};
    std::wspanbuf wsp_buf{std::span<wchar_t>(wraw_arr)};
    std::wospanstream wosp{std::span<wchar_t>(wraw_arr)};
    wosp << L"WideSpan";
    std::wispanstream wisp{std::span<const wchar_t>(wraw_arr)};
    std::wspanstream wsp_io{std::span<wchar_t>(wraw_arr)};
#else
    std::cout << "[Note] <spanstream> skipped (not enabled in this libc++)\n";
#endif

    // =========================================================================
    // F. SYNCHRONIZED OUTPUT (<syncstream>, C++20) - Narrow & Wide
    // =========================================================================
#if defined(__cpp_lib_syncbuf) && __cpp_lib_syncbuf >= 201803L
    {
        std::syncbuf sb(std::cout.rdbuf());
        std::ostream sb_out(&sb);
        sb_out << "[std::syncbuf] Atomic buffer flush\n";
    }
    {
        std::osyncstream sync_out(std::cout);
        sync_out << "[std::osyncstream] Thread-safe wrapper flush\n";
        sync_out.emit();
    }
    {
        std::wsyncbuf wsb(std::wcout.rdbuf());
        std::wosyncstream wsync_out(std::wcout);
        wsync_out << L"[std::wosyncstream] Wide thread-safe flush\n";
    }
#else
    std::cout << "[Note] <syncstream> skipped (requires -fexperimental-library on Apple Clang)\n";
#endif

    // =========================================================================
    // G. AUXILIARY POSITION TYPES (<ios>, <iosfwd>) & ERROR CATEGORY (C++11)
    // =========================================================================
    std::streamoff offset = 10;
    std::streamsize transfer_size = 64;
    std::streampos pos = std::streampos(offset);
    std::wstreampos wpos = std::wstreampos(offset);
    std::u8streampos u8pos = std::u8streampos(offset);
    std::u16streampos u16pos = std::u16streampos(offset);
    std::u32streampos u32pos = std::u32streampos(offset);
    (void)transfer_size; (void)pos; (void)wpos; (void)u8pos; (void)u16pos; (void)u32pos;

    std::error_code ec = std::make_error_code(std::io_errc::stream);
    std::cout << "Error Category: " << std::iostream_category().name()
              << " | Message: " << ec.message() << '\n';

    // =========================================================================
    // H. PRINT FUNCTIONS (<print>, <ostream>, C++23)
    // =========================================================================
#if defined(__cpp_lib_print) && __cpp_lib_print >= 202207L
    std::print("std::print -> value: {}, ", 42);
    std::println("std::println -> hex: {:#x}", 42);

    std::print(std::cout, "std::print(ostream) -> {}, ", "stream");
    std::println(std::cout, "std::println(ostream) -> {}", "done");

    int arg1 = 7;
    auto fmt_args = std::make_format_args(arg1);
    std::vprint_unicode("vprint_unicode: {}\n", fmt_args);
    std::vprint_nonunicode("vprint_nonunicode: {}\n", fmt_args);
    #if __cpp_lib_print >= 202403L
    std::vprint_unicode_buffered("vprint_unicode_buffered: {}\n", fmt_args);
    std::vprint_nonunicode_buffered("vprint_nonunicode_buffered: {}\n", fmt_args);
    #endif
#else
    std::cout << "[Note] <print> skipped\n";
#endif

    // =========================================================================
    // I. C-STYLE I/O (<cstdio>)
    // =========================================================================
    if (std::FILE* fp = std::fopen("cstdio_demo.txt", "w+")) {
        std::fprintf(fp, "ABC\n");
        std::rewind(fp);
        int ch = std::getc(fp);
        char c_line[32]{};
        std::fgets(c_line, sizeof(c_line), fp);
        std::cout << "C-style std::getc: '" << static_cast<char>(ch)
                  << "' | rest: " << c_line;
        std::fclose(fp);
    }

    return 0;
}
