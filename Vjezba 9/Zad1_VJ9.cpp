#include <iostream>
#include<string>
using namespace std;

template <typename T>
T MYmin(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

int main32()
{
	int x = 5, y = 10;
	cout << "Manji broj je:" << MYmin(x, y) << endl;
	return 0;
}