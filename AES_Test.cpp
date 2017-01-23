#include <iostream>
void yield(){
};
#include "AES/AES.h"
#include "AES/AES.cpp"
using namespace std;

byte iv11[]  = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
byte key[] = "AhmedMustSleepnwAhmedMustSleepnw";
byte data[] = "AhmedMustSleepnw";
AES aes;

int main()
{
    aes.set_key( key , sizeof(key)-1);
    byte cipher[sizeof(data)+17];
    aes.set_IV_array(iv11);
    aes.do_aes_encrypt(data, sizeof(data)-1 , cipher);
    aes.printArray(cipher,aes.get_size());
    cout << endl;
    cout << aes.get_size() << endl;
    byte decipher[aes.get_size()];
    aes.set_IV_array(iv11);
    aes.do_aes_decrypt(cipher,aes.get_size(),decipher);
    aes.printArray(decipher,aes.get_size());
    cout << aes.get_size() << endl;

    cout << decipher << endl;
    //cout << cipher << endl;
    return 0;
}
