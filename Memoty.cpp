#include <iostream>
#include <ctime>
using namespace std;



void New_arr (int **arr, int size_x = 10, int size_y = 10) //функция создания нового поля. Принимает массив и его размеры
{
	for (int i = 0; i < size_x; i++) 
	{
		for (int j = 0; j < size_y/2; j++) 
		{
			arr[i][j] = rand()%30; //половину строки заполняем случайным значением
			arr[i][j + size_y / 2] = arr[i][j]; // вторую половину строки заполняем таким же парным значением
		}
	}
	//после парного заполнения нужно перемешать все значения во всем массиве
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
		{
			int x_rand = rand() % size_x;
			int y_rand = rand() % size_y; // создаем два случайных значения - случайный элемент массива
			int temp = arr[i][j];
			arr[i][j] = arr[x_rand][y_rand]; //помещаем текущий элемент в случайный
			arr[x_rand][y_rand] = temp;
		}
	}
}

void Show_arr(int **arr, int size_x, int size_y) //функция вывода ответов (массива) на экран
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
	int size_x; //размер массива по вертикали
	int size_y; //размер по горизонтали
	
	cout << "Ну здавствуй, мой юный друг!\nТы попал в увлекательный мир программирования!\nДавай сиграем в игру Память\n ";
	cout << "\n";
	cout << "Введи количество строк поля (четное число)\n";
	cin >> size_x;
	cout << "Введи количество столбцов поля (четной число)\n";
	cin >> size_y;
	//необходимо, чтобы матрица была с четным количество элементов, так как загадываем парные значения
	//проверим данные пользователя на соответствие этому. Если это не так - исправим
	if (size_x % 2 != 0) size_x++;
	if (size_y % 2 != 0) size_y++;

	int** arr = new int*[size_x];
	for (int i = 0; i < size_x; i++) {
		arr[i] = new int[size_y];
	}

	New_arr(arr, size_x, size_y);
	Show_arr(arr, size_x, size_y);
}


