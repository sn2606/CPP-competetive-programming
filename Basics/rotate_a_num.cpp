# include <iostream> 
# include <cmath>

using namespace std;

int main() {
    long int n, k;
    int r;
    cin >> n >> k;
    int dig = 0;
    int m = n;
    while(m != 0)
    {
        m /= 10;
        dig++;
    }
    
    
    int arr[dig];

    //write your code here
    int i = dig;
    while(n != 0)
    {
        r = n%10;
        i--;
        arr[i] = r;
        n /= 10;
    }
    
    
    // for(i = 0; i < dig; i++)
    // {
    //     cout << arr[i] << "\n";
    // }
    
    
    int res = 0;
    int j = 0;
    if(k >= 0)
    {
       k = k % dig;

       for(i = (dig-k)%dig; j < dig; i = (i+1)%dig, j++)
       {
           res *= 10;
           res += arr[i];
           //cout << i << " " << j << " " << res << "\n";
       }
    }
    else
    {
        for(i = (-k)%dig; j < dig; i = (i+1)%dig, j++)
        {
           res *= 10;
           res += arr[i];
        }
    }
    
    cout << res;
    
    return 0;
}