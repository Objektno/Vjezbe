#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void funkcija(vector<int>& v) 
{
    sort(v.begin(), v.end());
    v.insert(v.begin(), 0);
    v.push_back(accumulate(v.begin(), v.end(), 0));
}

int main() 
{
    vector<int> v = { 5, 3, 8, 1, 4 };
    funkcija(v);

    for (int elem : v) 
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
