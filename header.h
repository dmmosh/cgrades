#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <array>


class terminal{

    public:

    terminal();

    // PRINT INTO TERMINAL
    template<typename T>
    terminal operator<<(const T &output){
        std::system(output.c_str());

    }

    // INPUT FROM TERMINAL
    template<typename T>
    terminal operator>>(T& input){
        std::array<char, 128> buffer;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            if (typeid(T) == typeid(std::string))
            {
                input += buffer.data();
            } else {
            input = buffer.data();
            }
        }
    }

};