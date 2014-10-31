#include <ostream>
#include <ccspec/core/formatter.h>
#include <ccspec/core/formatters/text_formatter.h>

namespace ccspec {
namespace core {
namespace formatters {

using std::ostream;

TextFormatter::TextFormatter(ostream& output) : Formatter(output) {}

} // namespace formatters
} // namespace core
} // namespace ccspec
