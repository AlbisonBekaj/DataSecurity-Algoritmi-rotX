#include<iostream>
#include <cstdint>
#include <cstring>
#include <vector>

using namespace std;
class RotX{
    public:
        static vector<uint8_t> encrypt(const string& input, uint8_t key) {
        vector<uint8_t> output;
            for (char ch : input)
            output.push_back((uint8_t(ch) + key) % 256);
        return output;
    }

// hellloo
};
class Run{


};

int main(){




    return 0;
}