#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void generateArrays(vector <int> a, vector <int> b, int c[], int i, int j, int m, int n, int len, bool flag);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n1, n2;
    vector <int> a1, a2;
    
    cin >> n1;
    
    for(int i = 0; i < n1; i++)
    {
        int r1;
        cin >> r1;
        a1.push_back(r1);
    }
    
    cin >> n2;
    
    for(int i = 0; i < n2; i++)
    {
        int r2;
        cin >> r2;
        a2.push_back(r2);
    }
    
    int len = 0;
    bool flag = true;
    int c[n1+n2];
    int i = 0, j = 0;
    
    generateArrays(a1, a2, c, i, j, n1, n2, len, flag);    
    
    return 0;
}


void generateArrays(vector <int> a, vector <int> b, int c[], int i, int j, int m, int n, int len, bool flag)
{
    if(flag)
    {
        if(len)
        {
            for(int x = 0; x <= len; x++)
            {
                cout << c[x] << " ";
            }
            
            cout << "\n";
        }
        
        for(int k = i; k < m; k++)
        {    
            if(!len)
            {
                c[len] = a[k];
                generateArrays(a, b, c, k+1, j, m, n, len, !flag);
            }
            else
            {
                if(a[k] > c[len])
                {
                    c[len+1] = a[k];
                    generateArrays(a, b, c, k+1, j, m, n, len+1, !flag);
                }
            }
        }
    }
    else
    {
        for(int p = j; p < n; p++)
        {
            if(b[p] > c[len])
            {
                c[len+1] = b[p];
                generateArrays(a, b, c, i, p+1, m, n, len+1, !flag);
            }
        }
    }    
    
}