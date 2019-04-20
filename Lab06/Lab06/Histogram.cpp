#include"Histogram.h"
#include <iostream>

using namespace std;
/* Plot the histogram with a user-defined number of bins */

void performHistogram(int arr[], int size)
{
	system("cls");
	int bins;
	cout << "How many bins you want to use to group the data ? ";
	cin >> bins;
	double max = arr[0];
	double min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	cout << "min = " << min << endl;
	cout << "max = " << max << endl;
	double dataRange = max - min;
	double classRange = dataRange / bins;
	double lowerBound = min;
	double upperBound = min + classRange;
	for (int i = 0; i < bins; i++, upperBound += classRange, lowerBound += classRange)
	{
		bool last = i == (bins - 1);
		cout << "[" << lowerBound << ", " << upperBound << (last ? "]" : ")") << " : ";
		for (int j = 0; j < size; j++)
		{
			if (arr[j] >= lowerBound && (last || arr[j] < upperBound))
				cout << "*";
		}
		cout << endl;
	}
	system("pause");
}