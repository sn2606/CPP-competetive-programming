// 		    *
// 	    *		*
//  *				*
// 	    *		*
// 		    *

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n, i, j;
    cin >> n;

    //write your code here

    for (i = (n + 1) / 2 - 1; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == i || j == n - i - 1)
            {
                cout << "*\t";
            }
            else
            {
                cout << "\t";
            }
        }

        cout << "\n";
    }

    for (i = 1; i <= (n + 1) / 2 - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == i || j == n - i - 1)
            {
                cout << "*\t";
            }
            else
            {
                cout << "\t";
            }
        }

        cout << "\n";
    }

    return 0;
}