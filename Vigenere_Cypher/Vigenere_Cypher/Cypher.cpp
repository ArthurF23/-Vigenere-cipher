#include <string>
#include <iostream>
#include <sstream>
#include <random>
#include <locale>
using namespace std;
constexpr char table[26][26] = { 
	{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
	{'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A'},
	{'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B'},
	{'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C'},
	{'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D'},
	{'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E'},
	{'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F'},
	{'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G'},
	{'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
	{'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'},
	{'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'},
	{'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'},
	{'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'},
	{'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'},
	{'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'},
	{'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'},
	{'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
	{'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q'},
	{'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'},
	{'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'},
	{'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'},
	{'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'},
	{'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'},
	{'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W'},
	{'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
	{'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'}
};

template <class T>
T translate(char message) {
	switch (message) {
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	case 'I':
		return 8;
	case 'J':
		return 9;
	case 'K':
		return 10;
	case 'L':
		return 11;
	case 'M':
		return 12;
	case 'N':
		return 13;
	case 'O':
		return 14;
	case 'P':
		return 15;
	case 'Q':
		return 16;
	case 'R':
		return 17;
	case 'S':
		return 18;
	case 'T':
		return 19;
	case 'U':
		return 20;
	case 'V':
		return 21;
	case 'W':
		return 22;
	case 'X':
		return 23;
	case 'Y':
		return 24;
	case 'Z':
		return 25;


	case 'a':
		return 0;
	case 'b':
		return 1;
	case 'c':
		return 2;
	case 'd':
		return 3;
	case 'e':
		return 4;
	case 'f':
		return 5;
	case 'g':
		return 6;
	case 'h':
		return 7;
	case 'i':
		return 8;
	case 'j':
		return 9;
	case 'k':
		return 10;
	case 'l':
		return 11;
	case 'm':
		return 12;
	case 'n':
		return 13;
	case 'o':
		return 14;
	case 'p':
		return 15;
	case 'q':
		return 16;
	case 'r':
		return 17;
	case 's':
		return 18;
	case 't':
		return 19;
	case 'u':
		return 20;
	case 'v':
		return 21;
	case 'w':
		return 22;
	case 'x':
		return 23;
	case 'y':
		return 24;
	case 'z':
		return 25;
	default:
		return -1; //exclude char
	}
}
template <class T>
T translate(char message, char key) {
	int key_row;
	int letter_num;
	//Find Key Row
	for (int i = 0; i < 26; i++) {
		if (key == table[i][0]) {
			key_row = i;
			break;
		}
	}
	//Find Letter In Key Row
	for (int i = 0; i < 26; i++) {
		if (table[key_row][i] == message) {
			letter_num = i;
		}
	}

	switch (letter_num) {
	case 0:
		return 'A';
	case 1:
		return 'B';
	case 2:
		return 'C';
	case 3:
		return 'D';
	case 4:
		return 'E';
	case 5:
		return 'F';
	case 6:
		return 'G';
	case 7:
		return 'H';
	case 8:
		return 'I';
	case 9:
		return 'J';
	case 10:
		return 'K';
	case 11:
		return 'L';
	case 12:
		return 'M';
	case 13:
		return 'N';
	case 14:
		return 'O';
	case 15:
		return 'P';
	case 16:
		return 'Q';
	case 17:
		return 'R';
	case 18:
		return 'S';
	case 19:
		return 'T';
	case 20:
		return 'U';
	case 21:
		return 'V';
	case 22:
		return 'W';
	case 23:
		return 'X';
	case 24:
		return'Y';
	case 25:
		return 'Z';
	}
}

string remove_spaces(string inp) {
	inp.erase(remove(inp.begin(), inp.end(), ' '), inp.end());
	return inp;
}

#include "Cypher_.h"
namespace std {
	string CYPHER::check_and_correct_key(string key, int msg_length) {
		locale loc;
		//remove spaces
		key = remove_spaces(key);
		//Change to upper-case
		for (int i = 0; i < key.length(); i++) {
			key[i] = toupper(key[i], loc);
		}		
		//Make sure all chars in key are upper-case letters
		for (int i = 0; i < key.length(); i++) {
			if (key[i] < 65 || key[i] > 90) {
				key = key.substr(0, i) + key.substr(i + 1, key.length());
				i--;
			}
		}
		//Make sure the key and message are the same length
		if (key.length() > msg_length) {
			key = key.substr(0, msg_length);
		}
		else if (key.length() < msg_length) {
			key = key + key.substr(0, (msg_length - key.length()));
		}
 		return key;
	}
	string CYPHER::generate_key(int message_length) {
		string key = "";
		for (int i = 0; i != message_length; i++) {
			std::random_device rd;     // only used once to initialise (seed) engine
			std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
			//Generate a random number that has the int of a Capital ASCII Char
			std::uniform_int_distribution<int> uni(65, 90); // guaranteed unbiased
			char letter = uni(rng);
			key = key + letter;
		}
		return key;
	}
	string CYPHER::encrypt(string message, string key) {
		string result = "";
		for (int i = 0; i < message.length(); i++) {
			int x = translate<int>(message[i]); // message
			int y = translate<int>(key[i]); // key
			if (x != -1 && y != -1) {
				stringstream ss;
				ss << table[y][x];
				string s;
				ss >> s;
				result = result + s;
			}
		}
		return result;
	}

	string CYPHER::decrypt(string message, string key) {
		string result = "";
		for (int i = 0; i < message.length(); i++) {
			result = result + translate<char>(message[i], key[i]);
		}
		return result;
	}
}