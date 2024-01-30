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
        std::system(std::to_string(T).c_str());

    }

    // INPUT FROM TERMINAL
    template<typename T>
    terminal operator>>(T& input){
        std::array<char, 128> buffer;
        T result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            if (typeid(T) == typeid(std::string))
            {
                result += buffer.data();
            } else {
            result = buffer.data();
            }
        }
        return result;
    }

}