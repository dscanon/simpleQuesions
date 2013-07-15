#include<iostream>
using namespace std;

int sum(int *a, int i, int size)
{
	if (size>0)
	{
		i = sum(a, i, size-1)+a[size-1];
	}
	return i;
}

int max(int *a, int i, int size)
{
	if (size > 0)
	{
		return a[size - 1] > max(a, i, size - 1) ? a[size - 1] : max(a, i, size - 1);

	}
}

int main()
{
	int a[5] = { 4, 5, 2, 9, 7 };
	int b[3] = { 10, 50, 30 };
	cout << "sum a = " << sum(a, 0, 5) << endl;
	cout << "sum b = " << sum(b, 0, 3) << endl;
	cout << "max a = " << max(a, 0, 5) << endl;
	cout << "max b = " << max(b, 0, 3) << endl;
	return 0;
}