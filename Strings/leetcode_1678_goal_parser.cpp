// You own a Goal Parser that can interpret a string command. 
// The command consists of an alphabet of "G", "()" and/or "(al)" in some order. 
// The Goal Parser will interpret "G" as the string "G", "()" as the string "o", 
// and "(al)" as the string "al". The interpreted strings are then concatenated 
// in the original order.

// Given the string command, return the Goal Parser's interpretation of command.


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string answer;
        
        for(int i = 0; i < command.size();){
            if(command[i] == 'G'){
                answer += 'G';
                i++;
            }
            else if(command[i+1] == ')'){
                answer += 'o';
                i += 2;
            }
            else{
                answer += "al";
                i += 4;
            }
        }
        
        return answer;        
    }
};