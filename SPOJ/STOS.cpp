//STOS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> tab = vector<int>();
	char znak;
	int x, k{ 0 };
	while (cin >> znak)
	{
		if (znak == '+')
		{
			if (tab.size() < 10)
			{
				cin >> x;
				cout << ":)" << endl;
				tab.push_back(x);
				k++;
			}
			else
			{
				cout << ":(" << endl;
			}
		}
		if (znak == '-')
		{
			if (tab.size() > 0)
			{
				cout << tab[tab.size() - 1] << endl;
				tab.pop_back();
				k--;
			}
			else {
				k--;
			}
			if (k < 0)
			{
				cout << ":(" << endl;
				k++;
			}
		}
	}
	return 0;
}
