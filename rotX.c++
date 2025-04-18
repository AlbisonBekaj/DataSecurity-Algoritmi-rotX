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


};
class Run{


};

int main(){




    return 0;
}