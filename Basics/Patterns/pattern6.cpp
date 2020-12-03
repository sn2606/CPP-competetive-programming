// *	*	*		*	*	*	
// *	*				*	*	
// *						*	
// *	*				*	*	
// *	*	*		*	*	*	

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{

    int n, i, j, r;
    cin >> n;

    for (i = 1; i <= n; i += 2)
    {
        r = (n - i) / 2;

        for (j = 1; j <= r + 1; j++)
        {
            cout << "*\t";
        }

        for (j = 1; j <= i; j++)
        {
            cout << "\t";
        }

        for (j = 1; j <= r + 1; j++)
        {
            cout << "*\t";
        }

        cout << "\n";
    }

    for (i = n - 2; i >= 1; i -= 2)
    {
        r = (n - i) / 2;

        for (j = 1; j <= r + 1; j++)
        {
            cout << "*\t";
        }

        for (j = 1; j <= i; j++)
        {
            cout << "\t";
        }

        for (j = 1; j <= r + 1; j++)
        {
            cout << "*\t";
        }

        cout << "\n";
    }

    return 0;
}