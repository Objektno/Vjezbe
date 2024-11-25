#include <iostream>
#include <string>
using namespace std;

int ponavljanja(string& str, string&podstr)
{
	int s = str.length();
	int S = podstr.length();
	int brojac = 0;

	for (int i = 0; i <= S - s; i++)
	{
		int j;
		for (j = 0; j < s; j++)
			if (podstr[i + j] != str[j])
				break;
		if (j == s)
		{
			brojac++;
		}
	}
	return brojac;
}

int main343443()
{
	string podstr = "mamamam";
	string str = "ma";
	cout << "Ponavlja se:" << ponavljanja(str, podstr) << endl;
	return 0;
}
