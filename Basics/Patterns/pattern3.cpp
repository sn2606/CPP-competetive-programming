//                 *
//             *   *
//         *   *   *
//     *   *   *   *
// *   *   *   *   *

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int rows;
    cin >> rows;

    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= rows - i; ++j)
        {
            cout << "\t";
        }

        for (int j = 1; j <= i; ++j)
        {
            cout << "*\t";
        }
        cout << "\n";
    }
    return 0;
}