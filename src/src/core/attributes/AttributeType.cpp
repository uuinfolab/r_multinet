#include "core/attributes/AttributeType.hpp"

namespace uu {
namespace core {

std::string
to_string(
    const AttributeType& t
)
{
    switch (t)
    {
    case AttributeType::STRING:
        return "string";

    case AttributeType::NUMERIC:
        return "double";

    case AttributeType::INTEGER:
        return "int";

    case AttributeType::DOUBLE:
        return "double";

    case AttributeType::TIME:
        return "time";

    case AttributeType::TEXT:
        return "text";

    case AttributeType::STRINGSET:
        return "string_set";

    case AttributeType::INTEGERSET:
        return "int_set";

    case AttributeType::DOUBLESET:
        return "double_set";

    case AttributeType::TIMESET:
        return "time_set";


    default:
        return ""; // cannot get here
    }

    return "";
}


std::ostream&
operator<<(
    std::ostream& os,
    const AttributeType& t
)
{
    os << to_string(t);
    return os;
}



} // namespace "core"
} // namespace "uu"

