//Spoj 1.4 Iloczyn macierzy
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getMatrix(int rows, int columns)
{
	vector<vector<int>> matrix;
	for (int i = 0; i < rows; i++)
	{
		vector<int> row;
		for (int j = 0; j < columns; j++)
		{
			int num;
			cin >> num;
			row.push_back(num);
		}
		matrix.push_back(row);
	}
	return matrix;
}
vector<vector<int>> transpose(vector<vector<int>> matrix, int rows, int columns)
{
	vector<vector<int>> transposedMatrix;
	for (int i = 0; i < columns; i++)
	{
		vector<int> row;
		for (int j = 0; j < rows; j++)
		{
			row.push_back(matrix[j][i]);
		}
		transposedMatrix.push_back(row);
	}
	return transposedMatrix;
}
vector<vector<int>> multiply(vector<vector<int>> first, vector<vector<int>> second, int rows, int columns)
{
	vector<vector<int>> result;


	for (int i = 0; i < columns; i++)
	{
		vector<int> row;

		for (int j = 0; j < columns; j++)
		{
			int sum = 0;
			for (int k = 0; k < rows; k++)
			{
				sum += first[i][k] * second[k][j];

			}
			row.push_back(sum);
		}
		result.push_back(row);
	}
	return result;
}
void display(vector<vector<int>> matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
			if (j == columns - 1)
			{
				cout << "\n";
			}
		}
	}
}

int main() {
	int x, y;

	cin >> x;
	cin >> y;

	vector<vector<int>> first = getMatrix(x, y);
	vector<vector<int>> second = transpose(first, x, y);
	vector<vector<int>> result = multiply(second, first, x, y);
	display(result, y, y);
	return 0;
}
