// We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  
// Then, we removed all commas, decimal points, and spaces, and ended up with the string s.  
// Return a list of strings representing all possibilities for what our original coordinates could have been.

// Our original representation never had extraneous zeroes, so we never started with numbers like 
// "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  
// Also, a decimal point within a number never occurs without at least one digit occuring before it, 
// so we never started with numbers like ".1".

// The final answer list can be returned in any order.  Also note that all coordinates in the 
// final answer have exactly one space between them (occurring after the comma.)

import java.util.List;
import java.util.ArrayList;

class Solution816 {
    public List<String> ambiguousCoordinates(String s) {
        String S = s.substring(1, s.length()-1);     // s[0] = "(", s[s.length - 1] = ")", and the other elements in s are digits.
        List<String> coord = new ArrayList<String>();
        
        String left = "", right = "";
        List<String> leftOk, rightOk; 
        
        for(int i = 1; i < S.length(); i++){
            left = S.substring(0, i);          // empty coordinates are not a thing in this world
            right = S.substring(i, S.length()); // code faster pls i want to die
            
            // System.out.println(left + " " + right);
            
            leftOk = possible(left);
            rightOk = possible(right);
            
            for(String l : leftOk){           // if possible returns an empty list, it wont go in loop
                for(String r : rightOk){
                    coord.add("(" + l + ", " + r + ")");
                }
            }
            
        }
        
        return coord;
        
    }
    
    private List<String> possible(String sub) {
        List<String> res = new ArrayList<String>();
        char[] subarr = sub.toCharArray();
        int len = sub.length();
         
        if(len == 1){ // k -> k where k = 0, 1, ... , 9
            res.add(sub);
        }else if(subarr[0] == '0' && subarr[len-1] == '0'){ // 0kkkkk0 -> invalid
            // if(len == 1){
            //     res.add("0");
            // }
        }else if(subarr[0] == '0'){ // 0kkkkX -> 0.kkkkX where X = 1, 2, ..., 9 and k = 0, 1, ..., 9
            res.add("0." + sub.substring(1, len));
        }else if(subarr[len-1] == '0'){ //Xkkk0 -> itself, where X = 1, 2, ..., 9 and k = 0, 1, ..., 9
            res.add(sub);
        }else{
            res.add(sub); // XkkX -> XkkX, X.kkX, Xk.kX, Xkk.X where X, k as defined before
            for(int i = 1; i < len; i++){
                res.add(sub.substring(0, i) + "." + sub.substring(i, len));
            }
        }
        
        
        return res;
    }
}