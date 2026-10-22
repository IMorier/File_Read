#include <iostream>
#include <fstream>
#include <string>

int** create2darr(const int rows, const int columns);
void delete2darr(int** arr, const int rows);
void fill2darr(int** arr, const int rows, const int columns, std::ifstream& fout);
void show2darr(int** arr, const int rows, const int columns);

int main() {
	

	std::ifstream fout{ "in_3.txt" };
	if (!fout.is_open()) {
		std::cout << "ERROR: Something went wrong! File couldn't be opened.\n";
		return 1;
	}

	
	int rows{}, columns{};
	fout >> rows >> columns;
	int** arr{ create2darr(rows, columns) };
	fill2darr(arr, rows, columns, fout);
	show2darr(arr, rows, columns);

	fout.close();
	delete2darr(arr, rows);
	std::cout << "\n\n\n";
	return 0;
}


int** create2darr(const int rows, const int columns) {
	int** arr{ new int* [rows] };
	for (int i{ 0 }; i < rows; ++i) {
		arr[i] = new int[columns];
	}
	return arr;
}

void delete2darr(int** arr, const int rows) {
	for (int i{ 0 }; i < rows; ++i) {
		delete[] arr[i];
	}

	delete[] arr;
}


void fill2darr(int** arr, const int rows, const int columns, std::ifstream& fout) {
	for (int i{ 0 }; i < rows; ++i) {
		for (int j{ 0 }; j < columns; ++j) {
			fout >> arr[i][j];
		}
	}
}

void show2darr(int** arr, const int rows, const int columns) {
	for (int i{ 0 }; i < rows; ++i) {
		for (int j{ columns - 1 }; j >= 0; --j) {
			std::cout << arr[i][j] << (j > 0 ? ' ' : '\n');
		}
	}
}