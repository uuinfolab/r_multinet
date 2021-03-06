#ifndef UU_CORE_EXCEPTIONS_OPERATIONNOTSUPPORTEDEXCEPTION_H_
#define UU_CORE_EXCEPTIONS_OPERATIONNOTSUPPORTEDEXCEPTION_H_

#include <exception>
#include <string>

namespace uu {
namespace core {

/**
 * Exception thrown when a function is called with parameters that exist but cannot be handled by the function.
 */
class
    OperationNotSupportedException: public std::exception
{

  public:

    /**
     * @param value name of the unsupported operation
     */
    OperationNotSupportedException(
        std::string value
    );

    ~OperationNotSupportedException(
    )
    throw ();

    /**
     * Information about the exception.
     * @return an error message describing the occurred problem
     */
    virtual
    const char*
    what(
    ) const
    throw();

  private:

    std::string value;

};

}
}

#endif
