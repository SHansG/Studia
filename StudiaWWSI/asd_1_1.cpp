//Maksymalna liczba w ciągu
#include <iostream>
using namespace std;

int main()
{

	int liczba = 1;
	int maxliczba = 0;
	while (liczba != 0)
	{
		cin >> liczba;
		if (maxliczba < liczba)
		{
			maxliczba = liczba;
		}
	}
	cout << maxliczba << endl;

	return 0;
}
