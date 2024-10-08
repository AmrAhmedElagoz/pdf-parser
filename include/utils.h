#ifndef DS_UTILS_HPP
#define DS_UTILS_HPP

#include <string>
#include <stdexcept>

class StringException : public std::runtime_error {
public:
    explicit StringException(const std::string& message);
};

int ds_io_read_binary(const std::string& filename, std::string& buffer);

#endif 