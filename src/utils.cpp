#include "utils.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdexcept>

// Implement the StringException constructor
StringException::StringException(const std::string& message) 
    : std::runtime_error(message) {}

// Private class declaration - can be in the cpp file since it's only used internally
class StringBuilder {
private:
    std::vector<char> buffer;

public:
    void append(const char* data, size_t size) {
        buffer.insert(buffer.end(), data, data + size);
    }

    std::string build() const {
        return std::string(buffer.begin(), buffer.end());
    }

    size_t size() const {
        return buffer.size();
    }
};

int ds_io_read_binary(const std::string& filename, std::string& buffer) {
    try {
        constexpr size_t BUFFER_SIZE = 8192;
        char temp_buffer[BUFFER_SIZE];
        StringBuilder sb;

        std::istream* input_stream;
        std::ifstream file;

        if (!filename.empty()) {
            file.open(filename, std::ios::binary);
            if (!file) {
                throw StringException("Failed to open file: " + filename);
            }
            input_stream = &file;
        } else {
            input_stream = &std::cin;
        }

        while (input_stream->good()) {
            input_stream->read(temp_buffer, BUFFER_SIZE);
            std::streamsize bytes_read = input_stream->gcount();
            if (bytes_read > 0) {
                sb.append(temp_buffer, static_cast<size_t>(bytes_read));
            }
        }

        buffer = sb.build();
        return static_cast<int>(sb.size());

    } catch (const std::exception& e) {
        throw StringException(std::string("Error reading binary: ") + e.what());
    }
}