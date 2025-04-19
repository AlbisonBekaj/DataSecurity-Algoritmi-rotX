#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <cstdlib>  
#include <string.h>

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
class Key{
public:
static uint8_t generateKey(){
    return static_cast<uint8_t>(rand()%255+1);
}
static vector<uint8_t>generateKeys(size_t count){
    vector<uint8_t>keys;
    for(size_t i=0;i<count;i++){
        keys.push_back(generateKey());
    }
    return keys;

}
static void print(const uint8_t*data, size_t length, const string& label="Data" ){
    cout<<label<<":";
    for( size_t i=0; i<length;++i){
        cout<<static_cast<int>(data[i])<<"  ";

    }
    cout<<endl;

}
static void printAll(uint8_t**dataList, const size_t* lengths, size_t count, const string&label="Batch"){
    for(size_t i=0; i<count;++i){
        cout<<label<<"  "<<i+1<<":";
        print(dataList[i], lengths[i]);

    }

}

};

class Run{
    public:
        void static run(){
            system("cls");  
            int mode;
            while(true){
            cout<<"\n-------------------------------------------  HOME  ------------------------------------------------------\n";
            cout<<"--------------------- 1 encrypt/decrypt ---------------- 2 encrypt/decrypt multiple ---------------------\n Mode ? : ";
            cin>> mode;
                if(mode==1){
                    system("cls");  
                    Run::EnDnOne();
                }
                else if(mode==2){
                    system("cls");  
                    Run::EnDnMultiple();
                }
                else{
                    system("cls");  
                    cout << "Invalid option. Please select a valid mode.\n";

                }
            }
        }
    private:
        void static encryptAction(){
            string text;
            int key;
            cout<< "\n(0 - RANDOM KEY ) Enter KEY to Encrypt :  ";
            cin>>key;
            cout<< "\nEnter TEXT to Encrypt :  ";
            cin.ignore(); 
            getline(cin, text);
            
            uint8_t* data = new uint8_t[text.length()];
            for (size_t i = 0; i < text.length(); i++) {
                data[i] = static_cast<uint8_t>(text[i]);
            }
            if(key==0){
                key=Key::generateKey();
            }
            else{
                key=static_cast<uint8_t>(key);
            }
            RotX::print_bytes(data,text.length());
            RotX::encrypt(data,text.length(),key);
            cout<<"\nKEY : "<<key<<endl;
            RotX::print_bytes(data,text.length());

        }
        void static decryptAction(){
            string text;
            int key;
            cout<< "\nEnter TEXT to Decrypt :";
            cin.ignore(); 
            getline(cin, text);
            cout<< "\n(0 - BRUTE FORCE ) Enter KEY to Decrypt :";
            cin>>key;
            uint8_t* data = new uint8_t[text.length()];
            for (size_t i = 0; i < text.length(); i++) {
                data[i] = static_cast<uint8_t>(text[i]);
            }
            if(key==0){
                
            }
            else{
                key=static_cast<uint8_t>(key);
            }
           // RotX::encrypt(data,text.length(),key);
           // RotX::print_bytes(data,text.length());

        }
        void static EnDnOne(){
            int action;
            while(true){
                cout<<"\n----------------------------------------  MODE encrypt/decrypt  -----------------------------------------\n";
                cout<<  "---------------------------- 1 encrypt ------------------------- 2 decrypt --------------------- 0 Exit -\n Action ? : ";
                cin>>action;
                if(action==1){
                    encryptAction(); 
                }
                else if(action==2){
                    decryptAction() ; 
                }
                else if(action ==0){
                    system("cls");
                    return;
                }
                else{
                    system("cls");  
                    cout << "Invalid option. Please select a valid action.\n";

                }

            }
        }
        void static encryptActionMulti(){
            size_t count;
            cout << "How many texts do you want to encrypt? ";
            cin >> count;
            cin.ignore();
        
            uint8_t** dataList = new uint8_t*[count];
            size_t* lengths = new size_t[count];
            uint8_t* keys = new uint8_t[count];
        
            for (size_t i = 0; i < count; ++i) {
                string text;
                int key;
        
                cout << "(0 - RANDOM KEY) Enter KEY for TEXT #" << i + 1 << ": ";
                cin >> key;
                cin.ignore();

                cout << "\nEnter TEXT #" << i + 1 << " to Encrypt: ";
                getline(cin, text);
        
                lengths[i] = text.length();
                dataList[i] = new uint8_t[lengths[i]];
        
                for (size_t j = 0; j < lengths[i]; ++j) {
                    dataList[i][j] = static_cast<uint8_t>(text[j]);
                }
        
                if (key == 0) {
                    keys[i] = Key::generateKey();
                } else {
                    keys[i] = static_cast<uint8_t>(key);
                }
            }

        }
        void static decryptActionMulti(){
            
        }
        void static EnDnMultiple(){
            int action;
            while(true){
                cout<<"\n------------------------------------  MODE encrypt/decrypt Multiple -------------------------------------\n";
                cout<<  "---------------------------- 1 encrypt ------------------------- 2 decrypt --------------------- 0 Exit -\n Action ? : ";
                cin>>action;
                if(action==1){
                    encryptActionMulti(); 
                }
                else if(action==2){
                    decryptActionMulti() ; 
                }
                else if(action ==0){
                    system("cls");
                    return;
                }
                else{
                    system("cls");  
                    cout << "Invalid option. Please select a valid action.\n";

                }

            }
            
        }


};

int main(){


Run::run();

    return 0;
}