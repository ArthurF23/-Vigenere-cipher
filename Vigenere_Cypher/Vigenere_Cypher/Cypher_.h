#pragma once
#include <string>


namespace std {
	class CYPHER {
	public:
		static string check_and_correct_key(string key, int msg_length);
		static string generate_key(int message_length);
		static string encrypt(string message, string key);

		static string decrypt(string message, string key);
	};
}