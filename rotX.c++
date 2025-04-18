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
            cout << static_cast<int>(data[i]) << " ";
        }
        cout << endl;
    }
    static void encryptAll(uint8_t** dataList, const size_t* lengths, const uint8_t* keys, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        encrypt(dataList[i], lengths[i], keys[i]);  
        std::cout << "Encrypted " << i + 1 << ": ";
        print_bytes(dataList[i], lengths[i]);
    }
}



};
class Run{
    public:


};

int main(){




    return 0;
}