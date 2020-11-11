// Given a string, extract all integers words from it.
// Input : str = "geeksforgeeks 12 23 practice"
// Output : 12 13

// Input : str = "1: Prakhar Agrawal, 2: Manish Kumar Rai, 3: Rishabh Gupta"
// Output : 1 2 3

// Input : str = "Ankit sleeps at 4 am."
// Output : 4

// Cant copy my code from GFG editor :(

#include <iostream> 
#include <sstream> 
using namespace std; 
  
void extractIntegerWords(string str) 
{ 
    stringstream ss;     
  
    /* Storing the whole string into string stream */
    ss << str; 
  
    /* Running loop till the end of the stream */
    string temp; 
    int found; 
    while (!ss.eof()) { 
  
        /* extracting word by word from stream */
        ss >> temp; 
  
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found) 
            cout << found << " "; 
  
        /* To save from space at the end of string */
        temp = ""; 
    } 
} 
  
// Driver code 
int main() 
{ 
    string str = "1: 2 3 4 prakhar"; 
    extractIntegerWords(str); 
    return 0; 
} 