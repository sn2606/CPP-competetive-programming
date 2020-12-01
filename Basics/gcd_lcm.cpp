#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int num1, num2;
    cin >> num1 >> num2;

    int a = num1, b = num2;
    int g, l, r = 99;

    //write your code here

    while (r != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    g = a;

    l = num1 * num2 / g;

    cout << g << "\n"
         << l;

    return 0;
}
