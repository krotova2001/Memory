#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

void Show_rules() //отображение правил игры
{
	cout << "\n";
	cout << "1. Пользователь вводит размер стороны игральной доски (это обяательно четное число)\n";
	cout << "2. Компьютер показывает поле, где скрыты попарно созданные случайные цифры от 0 до 30 (2 и 2, 23 и 23)\n";
	cout << "3. Эти цифры сркыты под порядковым номером ячеек.\n";
	cout << "4. Задача пользователя открыть попарно все ячейки. Например, если первая ячейка открывается и там - 2, то нужно угадать в какой ячейке парная ей 2\n";
	cout << "5. Указание какую ячейку открыть дается компьютеру от игрока просто вводом порядкового номера ячейки\n";
	cout << "6. Когда все ячейки угаданы, игра заканчивается. Результаты игры записываются в файл results.txt\n\n";
	cout << "Игра народная, автор программы - Кротов Георгий, преподаватель - Давлетшин Роман\n";

	system("pause"); // подождем чтоб пользователь дочитал
};
template <typename T> void New_arr (T *arr, int size_x = 10) //функция создания нового поля. Принимает массив и его размер
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
			T temp = arr[i];
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

template <typename T> void Show_element(T arr, T arr_mask, int size, int element) //функция подсматривания карты
{
	for (int i = 0; i < size * size; )
	{
		for (int j = 0; j < size; j++)
		{
			if (i == element) // открываем отдельный эелемент
			{
				printf("%3d", arr[i]);
				cout << "|";
				i++;
			}
			else 
			{
				printf("%3d", arr_mask[i]);
				cout << "|";
				i++;
			}
		}
		cout << "\n";
		for (int k = 0; k < size; k++) { cout << "----"; } // рисуем подобие поля
		cout << "\n";
	}
}

template <typename T> bool Win(T *arr1, T *arr2, int size) // функция проверки выйгрыша
{
	for (int i = 0; i < size * size; i++) 
	{
		if (arr1[i] != arr2[i]) 
		{
			return false;
		}
	}
	return true; // если показанный и загаданный массив равны - выйгрыш
}

void Write_results(char name[50], int step) // функция записи результатов в файл
{
	FILE* file = fopen("results.txt", "a"); // открыть для записи и добавления в текстовом режиме
	if (file != nullptr) // проверка открылся ли файл
	{
		fprintf(file, "\n%s-%i", name, step);
		fclose(file);
	}
	else { cout << "\nНе могу записать ваши результаты"; };
}

void Show_results() // функция чтения результатов из файла
{
	FILE* file = fopen("results.txt", "r"); // открыть для записи и добавления в текстовом режиме
	if (file != nullptr) // проверка открылся ли файл
	{
		
		//Вариант 1
		//char c;	do {c = getc(file); cout << c; } while (c != EOF);
		
		//Вариант 2
		
		while (!feof(file)) // пока не кончился файл
		{
			char str[50];
			fscanf(file, "%s", str); // читаем единой строкой
			cout << str <<" шагов\n"; // выводим на экран
		}
		
		
		fclose(file);
		system("pause");
	}
	else { cout << "\nНе могу записать ваши результаты"; };
}

int main()
{
	srand(time(0)); 
	//system("chcp 65001");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "rus"); // на всякйи случай оставим для решение проблем с отображением
	//Начнем с меню. Это главное меню игры
	int size_x; //размер поля
	cout << "Ну здавствуй, мой юный друг!\n Ты попал в увлекательный мир программирования!\n Давай сиграем в игру Память\n ";
	cout << "\n";
	cout << "****************************\n";
	cout << "Правила игры - 1\n";
	cout << "Запуск - 2\n";
	cout << "Просмотр лучших результатов - 3\n";
	cout << "****************************\n";

	int choise; // меню работает на функциях ниже
	cin >> choise;
	switch (choise)
	{
	case 1: Show_rules(); // показываем правила, и дальше пойдет игра
		break;
	case 2:
		goto start_again; // укажем явно на метку с началом игры
		break;
	case 3: Show_results(); // считаем текущие результаты
		break;
	default:
		break;
	}
	
start_again: //Начало самой игры
	char name[50];
	cout << "Как пожелаете к вам обращаться?\n";
	cin >> name;
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

	//Show_arr(arr, size_x); // служебная функция для отладки
	cout << "\n";
	
	int step = 0; // количество шагов до выйгрыша
	int answer1;
	int answer2; //хранение ответов пользователя
	cout << "Ну что ж, посмотрим, насколько ты сообразительный...\n";
	
	while (!(Win(arr, arr_mask, size_x))) 
	{
		system("cls");
		Show_arr(arr_mask, size_x);
		cout << "Введи номер ячейки\n";
		cin >> answer1;
		answer1--; // уменьшим значения чтоб оно совпало с индексом массива
		system("cls"); //очистим экран
		Show_element(arr, arr_mask, size_x, answer1);
		
		cout << "Найди ей пару\n";
		cin >> answer2;
		answer2--;// уменьшим значения чтоб оно совпало с индексом массива
		step++;
		
		if (arr[answer1] == arr[answer2]) // если совпало - открываем карту
		{
			arr_mask[answer1] = arr[answer1];
			arr_mask[answer2] = arr[answer2];
			Beep(5523, 400);
			Beep(5523, 400);
			Show_arr(arr_mask, size_x);
		}
		
		else //если не сопало - позазываем то, что угаданно до этого
		{
			Beep(523, 500);
			system("cls"); //очистим экран
			Show_element(arr, arr_mask, size_x, answer2);
			system("pause");
		}
	}
	cout << "Вы выйграли за " << step << " шагов\n";
	Write_results(name, step); // запишем результаты в файл

	int again; // добавляем возможность сыграть еще разок
	cout << "Сыграем еще?\n 1 - да. Любой другой символ - выход\n";
	cin >> again;
	if (again == 1) goto start_again;
	//Show_results(); // после игры показываем результаты
}


