#include <endian.h>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdio>



int main(int argc, char** argv){
    if(argc == 1){
        throw std::runtime_error("expected file path to be passed in as an argument");
        return -1;
    }

    // grab first argument
    char* filePath = argv[1];
    std::ifstream fStream(filePath, std::ios::binary);

    if(!fStream.is_open()){
        throw std::runtime_error("argument file path is wrong");
        return -2;
    }

    char buffer[4096];

    while(fStream.read(buffer, sizeof(buffer)) || fStream.gcount() > 0){
        std::fwrite(buffer, 1, static_cast<std::size_t>(fStream.gcount()), stdout);
        return 0;
    }

    return 0;
}
