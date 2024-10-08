#include <iostream>
#include <zlib.h>
#include "utils.h"


int main() {
    try {
        std::string content;
        int size = ds_io_read_binary("AmrElAgoz.pdf", content);
        std::cout << "Read " << size << " bytes\n";
    } catch (const StringException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}