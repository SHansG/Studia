//Spoj 2.1 Egocentryczny dyskretny ortogonalny świat N-oidów
#include <iostream>
#include <vector>

using namespace std;
bool vprostopadly(int wymiar, int v1[], int v2[]);
bool vzerowy(int wymiar, int v1[]);
void displayV(vector<int> v);


int main() {

	int dane; // <1-4>
	int przestrzenie; // <2-10>
	int vs; // <2-500>

	vector<vector<int>> vector1;

	cin >> dane;
	if (dane < 1 || dane > 4) {
		return 0;
	}
	for (int i = 0; i < dane; i++) {
		cin >> przestrzenie;

		if (przestrzenie < 2 || przestrzenie > 10) {
			return 0;
		}
		cin >> vs;

		if (vs < 2 || vs > 500) {
			return 0;
		}

		int* poczatek = new int[10];
		int* v = new int[10];
		int* wynikowy = new int[10];

		for (int k = 0; k < przestrzenie; k++) {
			int temp;
			cin >> temp;
			poczatek[k] = temp;
			wynikowy[k] = temp;
		}

		for (int m = 0; m < vs - 1; m++) {

			for (int j = 0; j < przestrzenie; j++) {
				int element;
				cin >> element;
				v[j] = element;
			}
			bool czyProstopadlyv = vprostopadly(przestrzenie, poczatek, v);

			if (czyProstopadlyv) {
				for (int j = 0; j < przestrzenie; j++) {
					wynikowy[j] = wynikowy[j] + v[j];
				}


				if (!vzerowy(przestrzenie, v)) {

					for (int k = 0; k < przestrzenie; k++) {
						poczatek[k] = v[k];
					}
				}
			}
		}
		vector<int> tmp;
		for (int l = 0; l < przestrzenie; l++) {
			tmp.push_back(wynikowy[l]);
		}
		vector1.push_back(tmp);

		delete[] wynikowy;
		delete[] poczatek;
		delete[] v;

	}
	for (int n = 0; n < vector1.size(); n++) {
		displayV(vector1.at(n));
	}

	return 0;
}
void displayV(vector<int> v) {
	for (int element : v) {
		cout << element << " ";
	}
	cout << "\n";
}
bool vzerowy(int wymiar, int v1[]) {
	int tmp = 0;
	for (int i = 0; i < wymiar; i++) {
		if (v1[i] == 0) {
			tmp++;
		}
	}
	if (tmp == wymiar) {
		return true;
	}
	return false;
}
bool vprostopadly(int wymiar, int v1[], int v2[]) {
	int check = 0;

	for (int i = 0; i < wymiar; i++) {
		check += v1[i] * v2[i];
	}
	if (check == 0) return true;
	return false;
}
