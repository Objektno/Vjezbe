#include <iostream>
#include <vector>
#include "Zad1.h"

void unos_v1(vector<int>& vektor, int broj_elemenata)
{
	int broj;
	for (int i = 0; i < broj_elemenata; i++)
	{
		cout << "Unesite broj:";
		cin >> broj;
		vektor.push_back(broj);
	}
}

void unos_v2(vector<int>& vektor, int donja_granica, int gornja_granica)
{
	int broj;
	cout << "Unesite donju i gornju granicu:" << endl;
	while (true)
	{
		cout << "Unesi broj:";
		cin >> broj;
		if (broj < donja_granica || broj > gornja_granica)
		{
			cout << "Broj nije u granicama." << endl;
			break;
		}
		vektor.push_back(broj);
	}
}

void ispis_v(vector<int>& vektor)
{
	cout << "Elementi vektora:";
	for (int i = 0; i < vektor.size(); i++)
	{
		cout << vektor[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vektor1, vektor2, rezultat;
	int broj_elemenata1, broj_elemenata2;

	cout << "Unesi broj elemenata u vektor1:";
	cin >> broj_elemenata1;
	unos_v1(vektor1, broj_elemenata1);

	cout << "Unesi broj elemenata u vektor2:";
	cin >> broj_elemenata2;
	unos_v2(vektor2, broj_elemenata2);

	for (int i = 0; i < vektor1.size(); i++)
	{
		bool postoji = false;
		for (int j = 0; j < vektor2.size(); j++)
		{
			if (vektor1[i] == vektor2[j])
			{
				postoji = true;
				break;
			}
		}
		if (!postoji)
		{
			rezultat.push_back(vektor1[i]);

		}
	}

	cout << "Novi vektor";
	ispis_v(rezultat);

	return 0;
}