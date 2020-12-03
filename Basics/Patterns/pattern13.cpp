// 1
// 1	1
// 1	2	1
// 1	3	3	1
// 1	4	6	4	1

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    //write your code here
    for (int line = 1; line <= n; line++)
    {
        int C = 1; // used to represent C(line, i)
        for (int i = 1; i <= line; i++)
        {

            // The first value in a line is always 1
            cout << C << "\t";
            C = C * (line - i) / i;
        }
        cout << "\n";
    }

    return 0;
}
