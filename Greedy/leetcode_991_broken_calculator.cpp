// On a broken calculator that has a number showing on its display, we can perform two operations:

// Double: Multiply the number on the display by 2, or;
// Decrement: Subtract 1 from the number on the display.
// Initially, the calculator is displaying the number X.

// Return the minimum number of operations needed to display the number Y.

# include <iostream>
using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        
        if(X == Y){
            return 0;
        }
        
        if(X > Y){
            return X-Y;
        }
        
        int res = 0;
        
        while(X < Y) {
            
            if(Y % 2 == 0){
                Y /= 2;
                res++;
            }else{
                Y = (Y+1)/2;
                res += 2;
            }          
            
        }
        
        res += (X - Y);
        
        return res;
    }
};