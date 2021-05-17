#include "Array.h"
#include <iostream>
#include <time.h>
#include <stdexcept>
#include <exception>
#include <cmath>

using namespace std;

typedef Array::value_type* TArray;

Array func(double arr[], const int size)
{
	//First Array
	Array res = Array(size);

	//Fill array with random values (-50..50)
	srand((unsigned)time(NULL));
	Array::value_type A = -50;
	Array::value_type B = 50;
	for (int i = 0; i < size; i++)
	{
		res[i] = A + rand() % int(B - A + 1);
	}
	cout << "Array with random values : { " << res << " }" << endl;

	//Add Sum & Mean to result array
	res.commonPart();
	cout << "Array plus two additional elements : { " << res << " }" << endl;

	res.individualPart();
	//cout << res;

	return res;
}

int main()
{
	const int size = 5;
	double arr[size];

	Array taskArray = func(arr, size);
	cout << "Result array : { " << taskArray << " }" << endl;

	return 0;
}