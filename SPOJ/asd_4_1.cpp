//Spoj 4.1 Mnożenie transpozycji macierzy przez wektor
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double** getMatrix(int rows, int columns)
{
	double** matrix = new double* [rows];
	for (int i{ 0 }; i < rows; i++)
	{
		matrix[i] = new double[columns];
	}
	return matrix;
}

//trsmatrix(matrix to be transposed, columns of first matrix, rows of first matrix)
double** transposeMatrix(double** arr, int columns, int rows)
{
	double** trsMatrix = new double* [columns];
	for (int i{ 0 }; i < columns; i++)
	{
		trsMatrix[i] = new double[rows];
	}

	for (int i{ 0 }; i < columns; i++)
	{
		for (int j{ 0 }; j < rows; j++)
		{
			trsMatrix[i][j] = arr[j][i];
		}
	}
	return trsMatrix;
}

//multiplayByVector(transposed matrix, vector, columns of first matrix, rows of first matrix)
double* multiplayByVector(double** trsMatrix, double* vector, int columns, int rows)
{
	double* tmp = new double[columns];
	for (int i{ 0 }; i < columns; i++)
	{
		tmp[i] = 0;
	}
	for (int i{ 0 }; i < columns; i++)
	{
		for (int j{ 0 }; j < rows; j++)
		{
			tmp[i] += trsMatrix[i][j] * vector[j];
		}
	}
	return tmp;
}

int main()
{

	int matrixColumns;
	cin >> matrixColumns;
	int matrixRows;
	cin >> matrixRows;
		double** matrix = getMatrix(matrixRows, matrixColumns);
		double* vector = new double[matrixRows];
		for (int i{ 0 }; i < matrixRows; i++)
		{
			for (int j{ 0 }; j < matrixColumns; j++)
			{
				cin >> matrix[i][j];
			}
			cin >> vector[i];
		}
		double** trsMatrix = transposeMatrix(matrix, matrixColumns, matrixRows);
		double* result = multiplayByVector(trsMatrix, vector, matrixColumns, matrixRows);

		//wyswietla wynik
		for (int i{ 0 }; i < matrixColumns; i++)
		{
			cout << setprecision(7) << fixed << result[i] << " ";
		}


		for (int i = 0; i < matrixRows; i++)
		{
			delete[] matrix[i];
		}
		for (int i = 0; i < matrixColumns; i++)
		{
			delete[] trsMatrix[i];
		}

		delete[] matrix;
		delete[] trsMatrix;
		delete[] result;
		delete[] vector;
	
	return 0;
}
