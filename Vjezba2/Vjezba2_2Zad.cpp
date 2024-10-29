#include<iostream>
using namespace std;

void funkcija(int niz[], int& min, int&max, int n)
{
  int i;
  min = niz[0];
  max = niz[0];

  for(i = 0;i < n; i++)
  {
    if(niz[i]>max)
    {
     max = niz[i];
    }
    if(niz[i]<min)
    {
     min = niz[i];
    }
  }
}

int& drugi(int niz[], int t)
{
  return &niz[t];
}

int main(void)
{
 int niz[] = {1,2,3,4,5};
 int n = sizeof(niz) / sizeof(niz[0]);
 int min, max;
 funkcija(niz, min, max, n);
 cout<<"Najmanji je"<<min;
 cout<<"Najveci je"<<max;

 int t = 4;
 drugi(niz, t) += 1;
 
 return 0;
}