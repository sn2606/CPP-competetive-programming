// 5742. Sorting the Sentence
// User Accepted:4780
// User Tried:4995
// Total Accepted:4898
// Total Submissions:6555
// Difficulty:Easy
// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

// A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

// For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".
// Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <sstream>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<pair<char, string>> vec;
        stringstream ss(s);
        
        string word;
        
        while(ss >> word){
            vec.push_back(make_pair(word[word.size()-1], word.substr(0, word.size()-1)));
        }
        
        sort(vec.begin(), vec.end());
        
        string res = "";
        
        for(int i = 0; i < vec.size(); i++){
            res += vec[i].second;
            if(i != vec.size()-1){
                res += " ";
            }
        }
        
        return res;
    }
};