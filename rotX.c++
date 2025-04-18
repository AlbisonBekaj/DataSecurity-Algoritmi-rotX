#include<iostream>
#include <cstdint>
#include <cstring>
#include <vector>

using namespace std;
class RotX{
    public:
        static void encrypt(uint8_t* data, size_t length, uint8_t key) {
        for (size_t i = 0; i < length; i++) {
            data[i] = (data[i] + key) % 256;
        }
    }
     static void print_bytes(const uint8_t* data, size_t length) {
        for (size_t i = 0; i < length; i++) {
            std::cout << static_cast<int>(data[i]) << " ";
        }
        std::cout << std::endl;
    }
//test

};
class Run{
    public:


};

int main(){




    return 0;
}