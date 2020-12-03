// 1
// 2	3
// 4	5	6
// 7	8	9	10
// 11	12	13	14	15

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int rows, f = 0;

    //cout << "Enter number of rows: ";
    cin >> rows;

    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            f++;
            cout << f << "\t";
        }
        cout << "\n";
    }
    return 0;
}