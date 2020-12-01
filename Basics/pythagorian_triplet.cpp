#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    int a, b, c;
    cin >> a >> b >> c;
    int arr[] = {a, b, c};
    //write your code here
    int m = a;
    int i = 0;

    if (b > m)
    {
        m = b;
        i = 1;
    }

    if (c > m)
    {
        m = c;
        i = 2;
    }

    int s = 0;

    for (int j = 0; j < 3; j++)
    {
        if (j != i)
        {
            s += arr[j] * arr[j];
        }
    }

    s -= arr[i] * arr[i];

    if (s)
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }

    return 0;
}
