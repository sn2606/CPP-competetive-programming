// Given head which is a reference node to a singly-linked list. 
// The value of each node in the linked list is either 0 or 1. 
// The linked list holds the binary representation of a number.
// Return the decimal value of the number in the linked list.

# include <iostream>
# include <cmath>
# include <vector>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n = 0;
        vector <int> bin;
        
        while(head){
            bin.push_back(head->val);
            n++;
            head = head->next;
        }
        
        int i = 0;
        int res = 0;
        
        for(i = 0; i < n; i++){
            res += bin[i]*(pow(2, n-i-1));
        }
        
        return res;
        
    }
};