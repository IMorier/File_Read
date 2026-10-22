#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	std::ifstream fout{ "in_1.txt" };
	if (!fout.is_open()) {
		std::cout << "ERROR: Something went wrong! File couldn't be opened.\n";
		return 1;
	}


	std::string str{};
	while (fout >> str) {
		std::cout << str << '\n';
	}


	fout.close();

	std::cout << "\n\n\n";
	return 0;
}