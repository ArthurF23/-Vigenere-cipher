#include <iostream>
#include <string>
#include "Cypher_.h"
using namespace std;
void encrypt() {
    string msg;
    cout << "Please type the sentence you want to encrypt" << endl;
    cin >> msg;
    string key_yn;
    cout << "auto generate key? y/n" << endl;
    cin >> key_yn;
    cout << "yn: " << key_yn << endl;
    string k;
    if (key_yn == "y") {
        k = CYPHER::generate_key(msg.length());
    }
    else {
        cout << "Input your key (do not use spaces):" << endl;
        std::cin >> k;
        k = CYPHER::check_and_correct_key(k, msg.length());
    }

    string res = CYPHER::encrypt(msg, k);
    cout << "Input: " << msg << endl << "Result: " << res << endl << "Key: " << k << endl;
}
void decrypt() {
    cout << "Please type your encrypted message" << endl;
    string emsg;
    cin >> emsg;
    cout << "Please type ther key... Key must be all uppercase with no spaces and be the exact same length as the message " << endl
        << "(" << emsg.length() << " characters long)" << endl;
    string k;
    cin >> k;
    cout << "Decrypted: " << CYPHER::decrypt(emsg, k) << endl;
}
int main()
{
    cout << "Would you like to encrypt (e) or decrypt (d)?" << endl;
    string input;
    cin >> input;
    if (input[0] == 'e') {
        encrypt();
    }
    else if (input[0] == 'd') {
        decrypt();
    }
    return main();
}