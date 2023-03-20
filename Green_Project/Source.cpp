#include <iostream>
#include <cstdlib>
#include <ctime>

// Кодировка UTF-8
// move-семантика

void arr_add(int*& arr, int l, int num) {
	if (num <= 0)
		return;
	int* tmp = new int[l + num]{};
	for (int i{}; i < l; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n;

	// Динамичексие переменные
	/*
	// Память - статическая (стэк) - выделяется до запуска программы. Обладает фиксированным размером.
	//			динамическая (куча) - выделяется во время выполнения программы. Размер элементов непостоянный.

	int* pointer = new int; //  Выделение динамической памяти размером 4 байта

	*pointer = 7; // Запись значения в выделенную область памяти
	std::cout << "*pointer = " << *pointer << std::endl;

	delete pointer; // Освобождение выделенной памяти

	// *pointer = 100; - ОШИБКА! 



	pointer = new int;
	*pointer = 15;
	std::cout << "*pointer = " << *pointer << std::endl;

	delete pointer;
	*/

	// Динамический массив
	/*
	// Отличия динамического массива от статического:
	//	1) у статического - длина константа, у динамического - переменная;
	//	2) с помощью специальных проограмных конструкций, размер динамического массива может быть изменен;
	//	3) т.к. статический массив находится в стеке, работа с ним происходит в разы быстрее;
	//	4) элементы динамического массива необходимо очищать, чтобы не допускать утечки памяти.

	int d_size;
	std::cout << "Введите длину массива -> ";
	std::cin >> d_size;

	int* d_arr = new int[d_size];
	
	std::cout << "Ввод данных в массив\n";
	for (int i{}; i < d_size; i++) {
		std::cout << "Введите " << i + 1 << "-й элемент -> ";
		std::cin >> d_arr[i];
	}

	std::cout << "Получившийся массив:\n[";
	for (int i{}; i < d_size; i++)
		std::cout << d_arr[i] << ", ";
	std::cout << "\b\b]\n";

	delete[] d_arr;
	*/

	// Двумерные динамические массивы
	/*	int rows, cols;
	std::cout << "Введите высоту массива ->";
	std::cin >> rows;
	std::cout << "Введите ширину массива -> ";
	std::cin >> cols;

	// int* mx = new int[rows][cols]; - ОШИБКА! данный синтаксис не подходит
	int** mx = new int* [rows];

	// Выделение памяти
	for (int i{}; i < rows; i++)
		mx[i] = new int[cols];

	// Использование массива (так же, как и с обычными)
	mx[0][0] = 10;

	// Освобождение памяти
	for (int i{}; i < rows; i++)
		delete[] mx[i];
	delete[] mx;
	*/

	// Задача 1. Увеличение размера массива.
	

	std::cout << "Задача 1.\nВведите размер массива -> ";
	int s1;
	std::cin >> s1;
	int* arr1 = new int[s1];
	
	srand(time(NULL));
	std::cout << "Изначальный массив:\n";
	for (int i{}; i < s1; i++) {
		arr1[i] = rand() % 10 + 1;
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Введите кол-во доп. элементов -> ";
	std::cin >> n;

	arr_add(arr1, s1, n);
	s1 += n;

	std::cout << "Итоговый массив:\n";
	for (int i{}; i < s1; i++)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;


	return 0;
}