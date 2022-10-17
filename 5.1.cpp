#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string random_character(string characters){
	int n = characters.length();
	int r = rand() % n;

	return characters.substr(r, 1);
}

string insert_at_random(string str, string to_insert){
	int n = str.length();
	int r = rand() % (n + 1);

	return str.substr(0, r) + to_insert + str.substr(r);
}


string make_password(int length){
	string password;	
	for (int i = 0; i < length; i++){
		password += random_character("abcdefghijklmnopqrstuvwxyz");
	}

	string random_digit = random_character("0123456789");
	password = insert_at_random(password, random_digit);
	string random_symbol = random_character("+-*/?!@#$%&");
	password = insert_at_random(password, random_symbol);

	return password;
}

int main(){
	srand(time(0));
	for(int i = 1; i <= 10; i++){
		cout << random_character("abcdef");
	}
	cout << endl;
	
	srand(time(0));
	for (int i = 1; i <= 10; i++){
		cout << insert_at_random("arxcsw", "8") << endl; 
	}
	
	srand(time(0));
	string result = make_password(8);
	cout << result << endl;

	return 0;
}
