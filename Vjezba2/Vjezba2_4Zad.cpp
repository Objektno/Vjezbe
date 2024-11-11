#include <iostream>
#include <vector>
using namespace std;

struct Matrica {
    vector<vector<float>> data;  
    int n; 

 
    Matrica(int n) : n(n), data(n, vector<float>(n, 0)) {}

    void inputMatrica() 
    {
        cout << "Unesite elemente matrice (" << n << " x " << n << "):" << endl;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                cin >> data[i][j];
            }
        }
    }

    void displayMatrica() const 
    {
        for (const auto& row : data) 
        {
            for (float val : row)
            {
                cout << setw(10) << fixed << setprecision(4) << val << " ";
            }
            cout << endl;
        }
    }

    Matrica zbroji(const Matrica& other) const 
    {
        Matrica result(n);
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrica oduzmi(const Matrica& other) const 
    {
        Matrix result(n);
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrica pomnoži(const Matrica& other) const 
    {
        Matrix result(n);
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                for (int k = 0; k < n; ++k) 
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrica transponirana() const 
    {
        Matrix result(n);
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

int main() 
{
    int n;

    cout << "Unesite dimenziju matrica (n x n): ";
    cin >> n;

    Matrica matricaA(n), matricaB(n);

    cout << "Unesite elemente matrice A:" << endl;
    matricaA.inputMatrica();
    cout << "Unesite elemente matrice B:" << endl;
    matricaB.inputMatrica();

    cout << "\nMatrica A:" << endl;
    matricaA.displayMatrica();

    cout << "\nMatrica B:" << endl;
    matricaB.displayMatrica();

    cout << "\nZbroj matrica A i B:" << endl;
    Matrica sum = matricaA.zbroji(matricaB);
    sum.displayMatrica();

    cout << "\nRazlika matrica A i B (A - B):" << endl;
    Matrica diff = matricaA.oduzmi(matricaB);
    diff.displayMatrix();

    cout << "\nUmnožak matrica A i B:" << endl;
    Matrica product = matricaA.pomnoži(matricaB);
    product.displayMatrix();

    cout << "\nTransponirana matrica A:" << endl;
    Matrica transposeA = matricaA.transponirana();
    transposeA.displayMatrix();

    cout << "\nTransponirana matrica B:" << endl;
    Matrica transposeB = matricaB.transponirana();
    transposeB.displayMatrix();

    return 0;
}
