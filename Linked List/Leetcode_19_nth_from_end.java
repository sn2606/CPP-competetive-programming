// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Follow up: Could you do this in one pass?
 /**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

public class Leetcode_19_nth_from_end {

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode start = new ListNode();
        start.next = head;
        ListNode slow = start, fast = start;
        
        // n+1 because n counting starts from head (for fixing fast)
        // start is at one step behind head
        for(int i = 0; i < n+1; i++) {
            fast = fast.next;
        }
        
        while(fast != null) {
            slow = slow.next;
            fast = fast.next;
        }
        
        ListNode temp;
        
        temp = slow.next;
        slow.next = slow.next.next;
        temp = null;
        
        return start.next;
    }

}
