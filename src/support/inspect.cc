#include <sstream>
#include <ccspec/support/inspect.h>

namespace ccspec {
namespace support {

using std::ios;
using std::ios_base;
using std::stringstream;
using std::string;
using std::streambuf;
using std::ostream;

string inspect(bool val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(short val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(unsigned short val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(int val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(unsigned int val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(long val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(unsigned long val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(long long val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(unsigned long long val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(float val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(double val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(long double val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(void* val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string inspect(std::streambuf* sb) {
    stringstream ss;
    ss << sb;
    return ss.str();
}

string inspect(std::ostream& (*pf)(std::ostream&)) {
    stringstream ss;
    ss << pf;
    return ss.str();
}

string inspect(std::ios& (*pf)(std::ios&)) {
    stringstream ss;
    ss << pf;
    return ss.str();
}

string inspect(std::ios_base& (*pf)(std::ios_base&)) {
    stringstream ss;
    ss << pf;
    return ss.str();
}

} // namespace support
} // namespace ccspec
