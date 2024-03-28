#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

void write_to_file(int** matrix, int size, string filename)
{
	ofstream fout(filename);
	if (!fout.is_open()) return;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fout << matrix[i][j] << "  ";
		}
		fout << endl;
	}
	fout.close();
	return;
}

void write_to_file(int** matrix, int size, string filename, unsigned int time)
{
	ofstream fout(filename);
	if (!fout.is_open()) return;
	fout << "Size: " << size << endl;
	fout << "Time: " << time << " milliseconds" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fout << matrix[i][j] << "  ";
		}
		fout << endl;
	}
	fout.close();
	return;
}

void write_to_file(const int* sizes, string filename, unsigned int* times)
{
	ofstream fout(filename);
	if (!fout.is_open()) return;
	for (int i = 0; i < 5; i++)
	{
		fout << "Size: " << sizes[i] << "\t Time: " << times[i] << " milliseconds" << endl;
	}
	fout.close();
	return;
}

int** read_matrix(string filename)
{
	ifstream fin;
	fin.open(filename);

	// получаем размер из названия файла

	smatch res;
	regex reg("[1-9]\\d*");
	int size = 0;
	if (regex_search(filename, res, reg))
		size = stoi(res[0]);

	// считываем матрицу

	int** matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fin >> matrix[i][j];
	}
	fin.close();
	return matrix;
}

int main()
{

	return 0;
}