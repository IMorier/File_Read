#include <iostream>
#include <fstream>
#include <string>


int main() {

	int size{};
	std::cout << "Write size of array: ";
	std::cin >> size;

	int* arr{ new int[size] };
	for (int i{ 0 }; i < size; ++i) {
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
	}
	
	std::ofstream fin("out.txt");
	if (!fin.is_open()) {
		std::cout << "ERROR: Something went wrong! File couldn't be opened.\n";
		return 1;
	}
	fin << size << '\n';
	for (int i{ size - 1 }; i >= 0; --i) {
		fin << arr[i] << (i > 0 ? ' ' : arr[0]);
	}



	fin.close();
	std::cout << "\n\n\n";
	return 0;
}