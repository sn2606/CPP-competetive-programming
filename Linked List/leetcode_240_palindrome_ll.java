// Given the head of a singly linked list, return true if it is a palindrome.
//  * Definition for singly-linked list.

import java.util.ArrayList;


class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

// O(n) time O(n) space
class Solution {
    public boolean isPalindrome(ListNode head) {
        ArrayList<Integer> arr = new ArrayList<Integer>();

        while (head != null) {
            arr.add(head.val);
            head = head.next;
        }

        int i = 0, j = arr.size() - 1;

        while (i < j) {
            if (arr.get(i) != arr.get(j)) {
                return false;
            }
            i++;
            j--;
        }

        return true;

    }
}

// O(n) time O(1) space
class Solution2 {
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head, fast = head;
        
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode prev = null, next;        
        while(slow != null) {
            next = slow.next;
            slow.next = prev;
            prev = slow;
            slow = next;
        }
        slow = prev;
        
        while(slow != null && head != null) {
            if(slow.val != head.val) {
                return false;
            }
            
            slow = slow.next;
            head = head.next;
        }
        
        return true;
    }
}