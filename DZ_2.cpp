#include <iostream>
#include <fstream>
#include <string>


int main() {
	

	std::ifstream fout{ "in_2.txt" };
	if (!fout.is_open()) {
		std::cout << "ERROR: Something went wrong! File couldn't be opened.\n";
		return 1;
	}

	int size{};
	fout >> size;
	int* arr{ new int[size] };
	for (int i{ 0 }; i < size && !fout.eof(); ++i) {
		fout >> arr[i];
	}
	for (int i{ size - 1 }; i >= 0; --i) {
		std::cout << arr[i] << (i > 0 ? ' ' : '\n');
	}


	fout.close();

	std::cout << "\n\n\n";
	return 0;
}