//Spoj 5.3 Nieziemska szkoła
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
public:
	int sortedNr{ 0 };
	int nr{ 0 };
	float id{ 0 };
	string name, surname;

	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, const Student&);
	friend bool operator<(const Student&, const Student&);
	friend bool operator>(const Student&, const Student&);
};

bool operator<(const Student& l, const Student& r)
{
	bool status = false;

	if (l.surname < r.surname)
	{
		status = true;
	}
	if (l.surname == r.surname && l.name < r.name)
	{
		status = true;
	}
	if (l.surname == r.surname && l.name == r.name && l.id < r.id)
	{
		status = true;
	}
	if (l.surname == r.surname && l.name == r.name && l.id == r.id)
	{
		status = true;
	}
	return status;
}

bool operator>(const Student& l, const Student& r)
{
	bool status = false;

	if (l.surname > r.surname)
	{
		status = true;
	}
	if (l.surname == r.surname && l.name > r.name)
	{
		status = true;
	}
	if (l.surname == r.surname && l.name == r.name && l.id > r.id)
	{
		status = true;
	}
	if (l.surname == r.surname && l.name == r.name && l.id == r.id)
	{
		status = true;
	}

	return status;
}

ostream& operator<<(ostream& os, Student& obj)
{
	os << obj.sortedNr << " " << obj.surname << " " << obj.name << " " <<  obj.id << " " << obj.nr;
	return os;
}

istream& operator>>(istream& is, Student& obj)
{
	//ogranicz name( <= 5 znakow) surname( <= 10 znakow), id( id < 10 )
	is >> obj.nr >> obj.id >> obj.name >> obj.surname;
	return is;
}

void sort(vector<Student>& bar);
void mergeSort(vector<Student>& left, vector<Student>& right, vector<Student>& bars);


void sort(vector<Student>& bar) {
	if (bar.size() <= 1) return;

	int mid = bar.size() / 2;
	vector<Student> left;
	vector<Student> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
		right.push_back(bar[mid + j]);

	sort(left);
	sort(right);
	mergeSort(left, right, bar);
}
void mergeSort(vector<Student>& left, vector<Student>& right, vector<Student>& bars)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j] < right[k]) {
			bars[i] = left[j];
			j++;
		}
		else {
			bars[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		bars[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		bars[i] = right[k];
		k++; i++;
	}
}


int main()
{
	vector<Student> tab;
	int counter{ 0 };
	Student nStudent;
	while (cin >> nStudent) {
		tab.push_back(nStudent);
	}

	sort(tab);

	for (int i = 0, j = 1; i < tab.size(); i++)
	{
		tab[i].sortedNr = j;
		j++;
	}
	for (int i = 0; i < tab.size(); i++)
	{
		cout << tab[i] << endl;
	}
	return 0;
}
