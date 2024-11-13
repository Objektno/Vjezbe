#include<bits/stdc++.h>
using namespace std;

void funkcija(vector<int>& vect) { vect.push_back(30); }

int main()
{
 vector<int> vect;
 vect.push_back(10);
 vect.push_back(20);
 
 funkcija(vect);

 for(int i= 0; i < vect.size();i++)
   cout<<vect[i]<<" ";

 
 return 0;
}