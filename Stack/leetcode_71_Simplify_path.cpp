// Given a string path, which is an absolute path (starting with a slash '/') 
// to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
// In a Unix-style file system, a period '.' refers to the current directory, a double period '..' 
// refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') 
// are treated as a single slash '/'. For this problem, any other format of periods 
// such as '...' are treated as file/directory names.
// The canonical path should have the following format:

// The path starts with a single slash '/'.
// Any two directories are separated by a single slash '/'.
// The path does not end with a trailing '/'.
// The path only contains the directories on the path from the root directory 
// to the target file or directory (i.e., no period '.' or double period '..')

// Return the simplified canonical path.

# include <iostream>
# include <stack>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack <string> stck;
        vector <string> v;
        string dummy = "";
        int i;
        
        if(path == "/"){
            return "/";
        }
        
        for(i = 1; i < path.size(); i++){
            if(path[i] == '/'){
                v.push_back(dummy);
                dummy = "";
                continue;
            }else{
                dummy += path[i];
                if(i == path.size()-1)
                    v.push_back(dummy);
            }
        }
        
//         for(auto k : v){
//             cout << k << "~";
//         }
        
//         cout << "\n";
        
        for(i = 0; i < v.size(); i++){
            if(v[i] == "." || v[i] == ""){
                continue;
            }else if(v[i] == ".."){
                if(stck.empty()){
                    continue;
                }else{
                    stck.pop();
                }
            }else{
                stck.push(v[i]);
            }
        }
        
        stack <string> stck2;
        
        while(!stck.empty()){
            stck2.push(stck.top());
            stck.pop();
        }
        
        dummy = "";
        
        while(!stck2.empty()){
            dummy += '/';
            dummy += stck2.top();
            stck2.pop();
        }
        
        return (dummy == "") ? "/" : dummy;
        
    }
};