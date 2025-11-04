#include <iostream>
#include <cctype>
using namespace std;

const string BOLD = "\033[1m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string RESET = "\033[0m";

bool is_valid_input(const string &isbn_input, size_t &isbn_len, string &isbn);
bool is_valid_isbn_10(const string &isbn_10);
bool is_valid_isbn_13(const string &isbn_13);
int generate_check_digit_isbn_10(const string &incomplete_isbn_10);
int generate_check_digit_isbn_13(const string &incomplete_isbn_13);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Please, enter isbn" << endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		string isbn = "";
		size_t isbn_len = 0;
		if (!is_valid_input(argv[i], isbn_len, isbn)) {
			cerr << argv[i] << " is not a valid ISBN." << endl;
			return 1;
		}
		if (isbn_len == 10 || isbn_len == 13) {
			bool is_valid_isbn = false;
			if (isbn_len == 10) is_valid_isbn = is_valid_isbn_10(isbn);
			if (isbn_len == 13) is_valid_isbn = is_valid_isbn_13(isbn);
			string success_msg = string(is_valid_isbn ? BLUE : RED)
				+ BOLD
				+ (is_valid_isbn ? "valid" : "not valid")
				+ RESET;
			cout << "The entered ISBN-" << isbn_len << ": " 
				<< YELLOW << isbn << RESET << " is "
				<< success_msg << "." << endl;
		} else if (isbn_len == 9 || isbn_len == 12) {
			int check_digit = 0;
			if (isbn_len == 9) check_digit = generate_check_digit_isbn_10(isbn);
			if (isbn_len == 12) check_digit = generate_check_digit_isbn_13(isbn);
			cout << "The check digit for incomplete ISBN-" << isbn_len + 1
				<< ": " << YELLOW << isbn << RESET << " is " 
				<< GREEN << BOLD << check_digit << RESET << "." << endl;
		}
	}
}

bool is_valid_input(const string &isbn_input, size_t &isbn_len, string &isbn) {
	for (char c: isbn_input) {
		if (isdigit(static_cast<unsigned char>(c))) {
			isbn_len++;
			isbn += c;
			continue;
		}
		if (isbn_len == 9 && c == 'X') {
			isbn_len++;
			isbn += c;
			continue;
		}
		if (isspace(static_cast<unsigned char>(c))) continue;
		if (c == '-') continue;
		return false;
	}
	if (isbn_len != 9 && isbn_len != 10 && isbn_len != 12 && isbn_len != 13) return false;
	return true;
}

bool is_valid_isbn_10(const string &isbn_10) {
	int sum = 0;
	int weight = 10;
	int digit;
	for (char c: isbn_10) {
		if (weight == 1 && c == 'X') {
			digit = 10;
		} else {
			digit = c - '0';
		}
		sum += digit * (weight--);
	}
	return (sum % 11 == 0);
}

bool is_valid_isbn_13(const string &isbn_13) {
	int sum = 0;
	for (size_t i = 0; i < 12; i++) {
		sum += (isbn_13[i] - '0') * ((i % 2) ? 3 : 1);
	}
	int check_digit = (10 - sum % 10) % 10;
	return check_digit == (isbn_13[12] - '0');
}

int generate_check_digit_isbn_10(const string &incomplete_isbn_10) {
	int sum = 0;
	int weight = 10;
	int digit;
	for (char c: incomplete_isbn_10) {
		digit = c - '0';
		sum += digit * (weight--);
	}
	return 11 - sum % 11;
}

int generate_check_digit_isbn_13(const string &incomplete_isbn_13) {
	int sum = 0;
	int digit;
	for (size_t i = 0; i < incomplete_isbn_13.length(); i++) {
		digit = incomplete_isbn_13[i] - '0';
		sum += digit * ((i % 2) ? 3 : 1);
	}
	int check_digit = (10 - sum % 10) % 10;
	return check_digit;
}
