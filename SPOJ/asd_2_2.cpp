//Spoj 2.2 Wycieczka
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> getMatrix(int rows, int columns)
{
	vector<vector<int>> matrix;
	for (int i = 0; i < rows; i++)
	{
		vector<int>row;
		for (int j = 0; j < columns; j++)
		{
			row.push_back(0);
		}
		matrix.push_back(row);
	}
	return matrix;
}


vector<vector<int>> multiplay(vector<vector<int>> first, vector<vector<int>> second, int rows, int columns)
{
	vector<vector<int>> tmp;
	for (int i = 0; i < columns; i++)
	{
		vector<int> row;
		for (int j = 0; j < columns ;j++)
		{
			int sum{ 0 };
			for (int k = 0; k < rows;k++)
			{
				sum += first[i][k] * second[k][j];
			}
			row.push_back(sum);
		}
		tmp.push_back(row);
	}
	return tmp;
}

bool isTransitiv(vector<vector<int>> matrix, vector<vector<int>> sqrmatrix, int highest)
{
	for (int i{ 0 }; i < highest; i++)
	{
		for (int j{ 0 }; j < highest; j++)
		{
			if (sqrmatrix[i][j] == 1 && matrix[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int highest{ 0 };
	int x{ 0 };
	int y{ 0 };
	vector<vector<int>> matrix = getMatrix(101,101);
	while (cin >> x >> y)
	{
		matrix[x][y] = 1;
		if (x > highest) 
		{
			highest = x;
		}
		if (y > highest)
		{
			highest = y;
		}
	}
	vector<vector<int>> sqrmatrix = multiplay(matrix, matrix, highest, highest);
	if (isTransitiv(matrix, sqrmatrix, highest)) { cout << "TAK" << endl; }
	else { cout << "NIE" << endl; }
	return 0;
}
