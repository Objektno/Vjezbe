#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>   
using namespace std;

int main() 
{
    vector<int> vect{15, 2, 5, 8};
    
    int sum = accumulate(vect.begin(), vect.end(), 0);
    cout<<"Suma je:"<<sum;
    
    cout<<"\n";
    
    sort(vect.begin(), vect.end());
    cout<<vect[0]<<" "<<vect[1]<<" "<<vect[2]<<" "<<vect[3]<<endl;
    
    vect.begin() = 0;
    
    return 0;
}
