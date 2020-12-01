#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    //write your code here
    while (n % 2 == 0)
    {
        n /= 2;
        cout << 2 << " ";
    }

    for (int i = 3; i * i < n; i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            cout << i << " ";
        }
    }

    if (n > 2)
    {
        cout << n << " ";
    }

    return 0;
}