//в текстовом файле, что содержит программу на языке с++ почитать количество комментариев 

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int ROW = 500;
	const int COL = 500;
	const char ch = '\n';
void find_comment(char arr[][COL], int &i, int&j,int &count)
{
	if ((arr[i][j] == '*') && (arr[i][j + 1] == '/'))
	{
		count++;
		i++;
		j = 0;
	}
	else
	{
		i++;
		j++;
		find_comment(arr, i, j, count);
	}
}


int main()
{
	fstream fs;
	string path = "my_file.txt";
	fs.open(path, fstream::in);//открытие файла для чтения
	
	 char arr[ROW][COL];
	if (!fs.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		for (int i = 0; i < ROW; i++) 
		{
			fs.getline(arr[COL], ROW - 1, ch);// что-то не работает
		}
	
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				cout << arr[i][j]<<"\t";
			}
			cout << "\n";
		}
		int count = 0;//счетчик комментариев 
		int i = 0;
		int j = 0;
		bool need_to_increase = true;
		while (i < ROW)
		{
			while (j < COL)
			{
				if ((arr[i][j] == '/') && (arr[i][j + 1] == '/'))
				{
					count++;
					i++;
					j = 0;
					need_to_increase = false;
				}
				else if ((arr[i][j] == '/') && (arr[i][j + 1] == '*'))
				{
					find_comment(arr, i, j, count);
					need_to_increase = false;
				}
				else
				{
					need_to_increase = true;
				}
				j++;
			}
			if (need_to_increase = true)
			{
				i++; 
				j = 0;
			}
		}


	/*	for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				if ((arr[i][j] == '/') && (arr[i][j + 1] == '/'))
				{
					count++;
					i++;
				}
				else if ((arr[i][j] == '/') && (arr[i][j + 1] == '*'))
				{
					count++;
					i++;
				}
			}
		}*/
		cout << "всего комментариев:" << count;
		fs.close();
	}
}

