// 1. You are given n number of bulbs. They are all switched off. 
// A weird fluctuation in voltage hits the circuit n times. 
// In the 1st fluctuation all bulbs are toggled, in the 2nd fluctuation every 2nd bulb is toggled, 
// in the 3rd fluctuation every 3rd bulb is toggled and so on. 
// You've to find which bulbs will be switched on after n fluctuations.
// 2. Take as input a number n, representing the number of bulbs.
// 3. Print all the bulbs that will be on after the nth fluctuation in voltage.


# include<iostream>
using namespace std;

// unsigned int no_of_divisors(unsigned int n);

int main()
{
    unsigned int n, square = 1, odd = 3;
    cin >> n;
    
    //write your code here
    
    // for(unsigned int i = 1; i <= n; i++)
    // {
    //     divisors = no_of_divisors(i);
        
    //     if(divisors % 2 == 1)
    //     {
    //         cout << i << "\n";
    //     }
    // }
    
    while(square <= n)
    {
        cout << square << "\n";
        square += odd;
        odd += 2;
    }
    
    return 0;
}

// unsigned int no_of_divisors(unsigned int n)
// {
//     unsigned int i = 1;
//     unsigned int div = 0;

//     while(i*i <= n)
//     {
//         if(i*i != n && n % i == 0)
//         {
//             div += 2;
//         }
//         else if(i*i == n)
//         {
//             div++;
//         }
//         i++;
//     }
//     return div;
// }