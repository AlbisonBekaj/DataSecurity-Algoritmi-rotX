#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <cstdlib>  
#include <string.h>

using namespace std;
class RotX{
    public:
    static void encrypt(std::string& text, int key) {
        for (int i = 0; i < text.length(); i++) {
            uint8_t byteData = static_cast<unsigned char>(text[i]); 
            byteData = (byteData + key) % 256; 
            text[i] = static_cast<unsigned char>(byteData); 
        }
    }

        static void print_bytes(string& data) {
            int length = data.length();
            for (int i = 0; i < length; i++) {
                cout << static_cast<int>(static_cast<unsigned char>(data[i])) << " ";
            }
            cout << endl;
        }

        static void encryptAll(vector<string>& list, vector<int>& keys) {
            for (int i = 0; i < list.size(); ++i) {
                encrypt(list[i], keys[i]);  
                cout << "KEY : "<<keys[i]<<" ->Encrypted Text : " << list[i] << std::endl;  
                print_bytes(list[i]);
            }
        }

        static void decrypt(string& text, int key) {
            for (int i = 0; i < text.length(); i++) {
                uint8_t data = static_cast<uint8_t>(text[i]);
                data = (data - key + 256) % 256; 
                text[i] = static_cast<char>(data);  
            }
        }

        static void decryptAll(vector<string>& list, vector<int>& keys) {
            for (int i = 0; i < list.size(); ++i) {
                decrypt(list[i], keys[i]); 
                cout << "KEY : "<<keys[i]<<" ->Decrypted Text : " << list[i] << std::endl;
                print_bytes(list[i]); 
            }
        }
        static void bruteForce(string & text){
            cout << "\n--- Brute Force Decryption ---\n";
            for (int key = 1; key <= 255; ++key) {
                string copy = text;
                decrypt(copy, key);
                cout << "Key " << key << " => " << copy <<"      ";
                print_bytes(copy);
            }
            cout << "--------------------------------\n";
        }

        static void bruteForceAll(vector<string>& list) {
            for (int i = 0; i < list.size(); ++i) {
                cout << "\nText #" << i + 1 << ":\n";
                bruteForce(list[i]);
            }
        }
};
class Key{
public:
static int generateKey(){    
    srand(time(NULL));    
    return rand()%255+1;
}



};

class Run{
    public:
        void static run(){
            system("cls");  
            int mode = 0;
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
            string data;
            int key;
            cout<< "\n(0 - RANDOM KEY ) Enter KEY to Encrypt :  ";
            cin>>key;
            cout<< "\nEnter TEXT to Encrypt :  ";
            cin.ignore(); 
            getline(cin, data);
            
            if(key==0){
                key=Key::generateKey();
            }
            else{
                key=static_cast<uint8_t>(key);
            }
            RotX::print_bytes(data);
            RotX::encrypt(data,key);
            cout << "KEY : "<<key<<" ->Encrypted Text :  " << data << std::endl; 
            RotX::print_bytes(data);
        }
        void static decryptAction(){
            string data;
            int key;
            cout<< "\n(0 - BRUTE FORCE ) Enter KEY to Decrypt :  ";
            cin>>key;
            cout<< "\nEnter TEXT to Decrypt :  ";
            cin.ignore(); 
            getline(cin, data);
            
            RotX::print_bytes(data);
            if(key==0){
                RotX::bruteForce(data);
            }else{
                RotX::decrypt(data,key);
                cout << "KEY : "<<key<<" ->Decrypted Text :  " << data << std::endl;  
                RotX::print_bytes(data);
            }
            
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
        void static getData(vector<string> &dataList , vector<int> &keys ,  string action , string info=""){
            int count;
            cout << "How many texts do you want to "<<action<<"? ";
            cin >> count;
            cin.ignore();
            dataList.resize(count);
            keys.resize(count);
            string text;
            int key;
            for (int i = 0; i < count; ++i) {
        
                cout << "\n"<<info<<"Enter KEY for TEXT #" << i + 1 << ": ";
                cin >> key;
                cin.ignore();

                cout << "Enter TEXT #" << i + 1 << " to "<<action<<" :   ";
                //cin.ignore();

                getline(cin, text);
        
                dataList[i]=text;

                if (key == 0) {
                    keys[i] = Key::generateKey();
                } else {
                    keys[i] = key;
                }
            }
            cout<<endl;
        }
        void static encryptActionMulti(){

            vector<string> dataList;
            vector<int> keys;
        
            getData(dataList, keys, "encrypt","(0 - RANDOM KEY)"); 
            RotX::encryptAll(dataList,keys);

        }
        void static decryptActionMulti(){
            
            int bf;
            cout << "Do you want to bruteforce ( 1 YES ) ( 0 NO )? : ";
            cin >> bf;

            vector<string> dataList;
            vector<int> keys;
            if(bf==1){
                int count;
                cout << "How many texts do you want to decrypt ? ";
                cin >> count;
                cin.ignore();
                dataList.resize(count);
                keys.resize(count);
                for (int i = 0; i < dataList.size(); ++i) {
                    string text;            
                    cout << "Enter TEXT #" << i + 1 << " to Decrypt :  ";
                    getline(cin, text);
                    dataList[i]=text;
                }
                RotX::bruteForceAll(dataList);
            }
            else{
                getData(dataList,keys,"Decrypt");
                    RotX::decryptAll(dataList,keys);

                }
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