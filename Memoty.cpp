#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

void Show_rules() //����������� ������ ����
{
	cout << "\n";
	cout << "1. ������������ ������ ������ ������� ��������� ����� (��� ���������� ������ �����)\n";
	cout << "2. ��������� ���������� ����, ��� ������ ������� ��������� ��������� ����� �� 0 �� 30 (2 � 2, 23 � 23)\n";
	cout << "3. ��� ����� ������ ��� ���������� ������� �����.\n";
	cout << "4. ������ ������������ ������� ������� ��� ������. ��������, ���� ������ ������ ����������� � ��� - 2, �� ����� ������� � ����� ������ ������ �� 2\n";
	cout << "5. �������� ����� ������ ������� ������ ���������� �� ������ ������ ������ ����������� ������ ������\n";
	cout << "6. ����� ��� ������ �������, ���� �������������. ���������� ���� ������������ � ���� results.txt\n\n";
	cout << "���� ��������, ����� ��������� - ������ �������, ������������� - ��������� �����\n";

	system("pause"); // �������� ���� ������������ �������
};
template <typename T> void New_arr (T *arr, int size_x = 10) //������� �������� ������ ����. ��������� ������ � ��� ������
{
	int size = size_x * size_x;
		for (int i = 0; i < size / 2; i++)// ��������� ����������� ������ �� �������
		{
			arr[i] = rand() % 30; //��������  ��������� ��������� ���������
			arr[i+size/2] = arr[i]; // ������ �������� ��������� ����� �� ������ ���������
		}
	//����� ������� ���������� ����� ���������� ��� �������� �� ���� �������
	for (int i = 0; i < size; i++)
	{
			int x_rand = rand() % size; // ��������� � ������ ������� � �������� ��� �������
			T temp = arr[i];
			arr[i] = arr[x_rand]; //�������� ������� ������� � ���������
			arr[x_rand] = temp;
	}
}

template <typename T> void Show_arr(T arr, int size) //������� ������ ������� (�������) �� �����
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
		for (int k = 0; k < size; k++) { cout << "----"; } // ������ ������� ����
		cout << "\n";
	}
}

template <typename T> void Show_element(T arr, T arr_mask, int size, int element) //������� �������������� �����
{
	for (int i = 0; i < size * size; )
	{
		for (int j = 0; j < size; j++)
		{
			if (i == element) // ��������� ��������� ��������
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
		for (int k = 0; k < size; k++) { cout << "----"; } // ������ ������� ����
		cout << "\n";
	}
}

template <typename T> bool Win(T *arr1, T *arr2, int size) // ������� �������� ��������
{
	for (int i = 0; i < size * size; i++) 
	{
		if (arr1[i] != arr2[i]) 
		{
			return false;
		}
	}
	return true; // ���� ���������� � ���������� ������ ����� - �������
}

void Write_results(char name[50], int step) // ������� ������ ����������� � ����
{
	FILE* file = fopen("results.txt", "a"); // ������� ��� ������ � ���������� � ��������� ������
	if (file != nullptr) // �������� �������� �� ����
	{
		fprintf(file, "\n%s-%i", name, step);
		fclose(file);
	}
	else { cout << "\n�� ���� �������� ���� ����������"; };
}

void Show_results() // ������� ������ ����������� �� �����
{
	FILE* file = fopen("results.txt", "r"); // ������� ��� ������ � ���������� � ��������� ������
	if (file != nullptr) // �������� �������� �� ����
	{
		
		//������� 1
		//char c;	do {c = getc(file); cout << c; } while (c != EOF);
		
		//������� 2
		
		while (!feof(file)) // ���� �� �������� ����
		{
			char str[50];
			fscanf(file, "%s", str); // ������ ������ �������
			cout << str <<" �����\n"; // ������� �� �����
		}
		
		
		fclose(file);
		system("pause");
	}
	else { cout << "\n�� ���� �������� ���� ����������"; };
}

int main()
{
	srand(time(0)); 
	//system("chcp 65001");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "rus"); // �� ������ ������ ������� ��� ������� ������� � ������������
	//������ � ����. ��� ������� ���� ����
	int size_x; //������ ����
	cout << "�� ���������, ��� ���� ����!\n �� ����� � ������������� ��� ����������������!\n ����� ������� � ���� ������\n ";
	cout << "\n";
	cout << "****************************\n";
	cout << "������� ���� - 1\n";
	cout << "������ - 2\n";
	cout << "�������� ������ ����������� - 3\n";
	cout << "****************************\n";

	int choise; // ���� �������� �� �������� ����
	cin >> choise;
	switch (choise)
	{
	case 1: Show_rules(); // ���������� �������, � ������ ������ ����
		break;
	case 2:
		goto start_again; // ������ ���� �� ����� � ������� ����
		break;
	case 3: Show_results(); // ������� ������� ����������
		break;
	default:
		break;
	}
	
start_again: //������ ����� ����
	char name[50];
	cout << "��� ��������� � ��� ����������?\n";
	cin >> name;
	cout << "����� ������ ���� (������ �����)\n";
	cin >> size_x;
	//����������, ����� ����� ���� ���� � ������ ���������� ���������, ��� ��� ���������� ������ ��������
	//�������� ������ ������������ �� ������������ �����. ���� ��� �� ��� - ��������
	if (size_x % 2 != 0) size_x++;

	//������ �������� ������ ����
	int* arr = new int[size_x*size_x];
	New_arr(arr, size_x); // � �������� ��� ����������, ������� ����� ����������

	//�������� ����� - ������ ���� � ������� ��� �������� �� �������, ���� ������� ���� �� ���������
	int* arr_mask = new int [size_x*size_x];
	int n = 1;
	for (int i = 0; i < size_x*size_x; i++)
	{
		arr_mask[i] = n; //��������� �� �������
		n++;
	}

	//Show_arr(arr, size_x); // ��������� ������� ��� �������
	cout << "\n";
	
	int step = 0; // ���������� ����� �� ��������
	int answer1;
	int answer2; //�������� ������� ������������
	cout << "�� ��� �, ���������, ��������� �� ���������������...\n";
	
	while (!(Win(arr, arr_mask, size_x))) 
	{
		system("cls");
		Show_arr(arr_mask, size_x);
		cout << "����� ����� ������\n";
		cin >> answer1;
		answer1--; // �������� �������� ���� ��� ������� � �������� �������
		system("cls"); //������� �����
		Show_element(arr, arr_mask, size_x, answer1);
		
		cout << "����� �� ����\n";
		cin >> answer2;
		answer2--;// �������� �������� ���� ��� ������� � �������� �������
		step++;
		
		if (arr[answer1] == arr[answer2]) // ���� ������� - ��������� �����
		{
			arr_mask[answer1] = arr[answer1];
			arr_mask[answer2] = arr[answer2];
			Beep(5523, 400);
			Beep(5523, 400);
			Show_arr(arr_mask, size_x);
		}
		
		else //���� �� ������ - ���������� ��, ��� �������� �� �����
		{
			Beep(523, 500);
			system("cls"); //������� �����
			Show_element(arr, arr_mask, size_x, answer2);
			system("pause");
		}
	}
	cout << "�� �������� �� " << step << " �����\n";
	Write_results(name, step); // ������� ���������� � ����

	int again; // ��������� ����������� ������� ��� �����
	cout << "������� ���?\n 1 - ��. ����� ������ ������ - �����\n";
	cin >> again;
	if (again == 1) goto start_again;
	//Show_results(); // ����� ���� ���������� ����������
}


