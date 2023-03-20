#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");

	int n;

	// Память - статическая (стэк)
	//			динамическая (куча)

	int* pointer = new int; //  Выделение динамической памяти размером 4 байта

	*pointer = 7;
	std::cout << "*pointer = " << *pointer << std::endl;












	return 0;
}