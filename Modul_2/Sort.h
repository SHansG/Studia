#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void merge(int* tab, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int* L = new int[n1];
	int* R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = tab[l + i];
	for (j = 0; j < n2; j++)
		R[j] = tab[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			tab[k] = L[i];
			i++;
		}
		else
		{
			tab[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		tab[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		tab[k] = R[j];
		j++;
		k++;
	}
	delete[] R;
	delete[] L;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
int* mergeSort(int* tab, int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(tab, l, m);
		mergeSort(tab, m + 1, r);

		merge(tab, l, m, r);
	}
	return tab;
}



int* bubbleSort(int* tab, int size)
{
	int i, j, counter{ 0 };
	for (i = 0; i < size - 1; i++) {

		// Last i elements are already in place  
		for (j = 0; j < size - i - 1; j++) {
			if (tab[j] > tab[j + 1]) {
				swap(&tab[j], &tab[j + 1]);
				//	cout << endl;
				counter++;
				//	cout << "przesuniecie/zamiana: " << counter << endl;
			}
		}
	}
	cout << "przesuniecie/zamiana: " << counter << endl;
	return tab;
}

int* selectionSort(int* tab, int size)
{
	int i, j, min_idx, counter{ 0 };

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < size - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (tab[j] < tab[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element  
		swap(&tab[min_idx], &tab[i]);
		//cout << endl;
		counter++;
		//cout << "przesuniecie/zamiana: " << counter << endl;
	}
	return tab;
}

int* insertSort(int* tab, int size)
{
	int i, key, j, counter{ 0 };
	for (i = 1; i < size; i++)
	{
		key = tab[i];
		j = i - 1;

		/* Move elements of tab[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && tab[j] > key)
		{
			tab[j + 1] = tab[j];
			j = j - 1;
			//	cout << endl;
			counter++;
			//	cout << "przesuniecie/zamiana: " << counter << endl;
		}
		tab[j + 1] = key;
	}
	return tab;
}



/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int* tab, int low, int high)
{
	int pivot = tab[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j < high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (tab[j] < pivot)
		{
			i++; // increment index of smaller element  
			swap(&tab[i], &tab[j]);
		}
	}
	swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
*tab --> Array to be sorted,
low --> Starting index,
high --> Ending index */
int* quickSort(int* tab, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, tab[p] is now
		at right place */
		int pi = partition(tab, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(tab, low, pi - 1);
		quickSort(tab, pi + 1, high);
	}
	return tab;
}