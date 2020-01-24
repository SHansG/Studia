//Spoj 1.3 Najmniejsza i największa liczba w ciągu
#include <iostream>

using namespace std;

int main()
{
	int num;
	int lowest = 500;
	int lowestIndex = 0;
	int highest = -500;
	int highestIndex = 0;
	int counter = 0;
	while (cin >> num)
	{
		counter++;
		if (num >= highest)
		{
			highest = num;
			highestIndex = counter;
		}
		if (num < lowest)
		{
			lowest = num;
			lowestIndex = counter;
		}
	}
	cout << lowest << endl << lowestIndex << endl << highest << endl << highestIndex;

	return 0;
}
