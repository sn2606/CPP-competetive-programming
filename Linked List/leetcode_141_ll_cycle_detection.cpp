// Given head, the head of a linked list, 
// determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list 
// that can be reached again by continuously following the next pointer. 
// Internally, pos is used to denote the index of the node that tail's 
// next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

# include <iostream>
# include <cmath>
# include <vector>
# include <unordered_set>
using namespace std;

// Using hashing technique
// Where there is unique, there can be unordered set


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set <ListNode *>s;
        
        while(head){
            
            if(s.find(head) != s.end()){
                return true;
            }
                
            s.insert(head);            
            head = head->next;
        }
        
        return false;        
    }
};

// Using Floyd's cycle finding algorithm
// Traverse linked list using two pointers.
// Move one pointer(slow_p) by one and another pointer(fast_p) by two.
// If these pointers meet at the same node then there is a loop. 
// If pointers do not meet then linked list doesn’t have a loop.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        
        while(p && q && q->next){
            p = p->next;
            q = q->next->next;
            
            if(p == q){
                return true;
            }
        }
        
        return false;        
    }
};