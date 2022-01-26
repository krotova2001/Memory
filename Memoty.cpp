#include <iostream>
#include <ctime>
using namespace std;



void New_arr (int arr[][10], int size_x = 10, int size_y = 10) //функция создания нового поля. Принимает массив и его размеры
{
	
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y/2; j++) {
			arr[i][j] = rand()%30; //половину строки заполняем случайным значением
			arr[i][j + size_y / 2] = arr[i][j]; // вторую половину строки заполняем таким же парным значением
		}
	}
}

void Show_arr(int arr[][10], int size_x, int size_y) //функция вывода ответов на экран
{
	for (int i = 0; i < size_x; i++) 
	{
		for (int j = 0; j < size_y; j++)
		{
			printf("%3d", arr[i][j]);
			cout << "|";
		}
		cout << "\n";
		for (int k = 0; k < size_y; k++) { cout << "----"; }
		cout << "\n";
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int size_x;
	int size_y;
	
	cout << "Ну здавствуй, мой юный друг!\nТы попал в увлекательный мир программирования!\nДавай сиграем в игру Память\n ";
	cout << "\n";
	cout << "Введи количество строк поля\n";
	cin >> size_x;
	cout << "Введи количество столбцов поля\n";
	cin >> size_y;
	int** arr = new int*[size_x];
	for (int i = 0; i < size_x; i++) {
		arr[i] = new int[i + 1];
	}

	New_arr(arr, size_x, size_y);
	Show_arr(arr, size_x, size_y);
}


