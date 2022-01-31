#include <iostream>
#include <ctime>
using namespace std;

void New_arr (int *arr, int size_x = 10) //функция создания нового поля. Принимает массив и его размер
{
	int size = size_x * size_x;
		for (int i = 0; i < size / 2; i++)// заполняем одномернный массив по строкам
		{
			arr[i] = rand() % 30; //половину  заполняем случайным значением
			arr[i+size/2] = arr[i]; // вторую половину заполняем таким же парным значением
		}
	//после парного заполнения нужно перемешать все значения во всем массиве
	for (int i = 0; i < size; i++)
	{
			int x_rand = rand() % size; // случайный и индекс массива в пределах его размера
			int temp = arr[i];
			arr[i] = arr[x_rand]; //помещаем текущий элемент в случайный
			arr[x_rand] = temp;
	}
}

template <typename T> void Show_arr(T arr, int size) //функция вывода ответов (массива) на экран
{
	for (int i = 0; i < size*size; ) 
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3d", arr[i]);
			cout << "|";
			i++;
		}
		cout << "\n";
		for (int k = 0; k < size; k++) { cout << "----"; } // рисуем подобие поля
		cout << "\n";
	}
}

int main()
{
	srand(time(0)); 
	setlocale(LC_ALL, "Russian");
	int size_x; //размер поля

	cout << "Ну здавствуй, мой юный друг!\nТы попал в увлекательный мир программирования!\nДавай сиграем в игру Память\n ";
	cout << "\n";
	cout << "Введи размер поля (четное число)\n";
	cin >> size_x;
	//необходимо, чтобы длина поля было с четным количество элементов, так как загадываем парные значения
	//проверим данные пользователя на соответствие этому. Если это не так - исправим
	if (size_x % 2 != 0) size_x++;

	//теперь создадим нужное поле
	int* arr = new int[size_x*size_x];
	New_arr(arr, size_x); // и заполним его значениями, которые нужно отгадывать

	//создадим маску - пустое поле и зполним его номерами по порядку, чтоб удобней было их указывать
	int* arr_mask = new int [size_x*size_x];
	int n = 1;
	for (int i = 0; i < size_x*size_x; i++)
	{
		arr_mask[i] = n; //заполняем по порядку
		n++;
	}

	Show_arr(arr, size_x);
	cout << "\n";
	Show_arr(arr_mask, size_x);
	/*
	int answer1;
	int answer2; //хранение ответов пользователя
	cout << "Ну что ж, посмотрим, насколько ты сообразительный...\n";
	
	cout << "Введи номер ячейки\n";
	cin >> answer1;
	
	cout << "Введи номер второй ячейки\n";
	cin >> answer2;

	*(arr_mask+answer2-1) = *(arr+answer2-1), *(arr_mask + answer1-1) = *(arr + answer1-1);
	*/
}


