#include <iostream>

using namespace std;

int main()
{

    unsigned int n(0);
    unsigned int i(1);
    unsigned int j(0);

    cout << "choisir 'n' : " << endl;
    cin >> n;

    unsigned int triangle[n][n];

    triangle[0][0] = 1;
    triangle[0][1] = 1;

    cout << "1" << endl;

    for (i=0; i<n; i++)
    {
        triangle[i][0] = 1;

        cout << triangle[i][0] << "\t";

        for (j = 1; j<i+1; j++)
        {
            triangle[i][j+1] = 1;
            triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j];
            cout << triangle[i][j] << "\t";
        }
        triangle[i][j+1] = 1;

        cout << triangle[i][j+1]<< endl;
    }

    return 0;
}
