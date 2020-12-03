// 0
// 1	1
// 2	3	5
// 8	13	21	34
// 55	89	144	233	377

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int rows, f1 = 0, f2 = 1, f = 0;
    cin >> rows;

    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            // f++;
            cout << f << "\t";
            f = f1 + f2;
            f2 = f1;
            f1 = f;
        }
        cout << "\n";
    }
    return 0;
}