// Given the head of a linked list and a value x, partition it such that all nodes less 
// than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.

// Definition for singly-linked list.
// class ListNode {
//      int val;
//      ListNode next;
//      ListNode() {}
//      ListNode(int val) { this.val = val; }
//      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
//  }

class Solution86 {
    public ListNode partition(ListNode head, int x) {

        if (head == null || head.next == null) {
            return head;
        }

        ListNode i = head, j = head.next;
        ListNode previ = null, prevj = head, nexti = i.next, nextj = j.next;
        ListNode temp;

        while (i != null && j != null) {
            if (i.val >= x && j.val < x) {
                if (previ != null) {
                    temp = previ.next;
                    previ.next = j;
                    j.next = temp;
                } else {
                    temp = head;
                    head = j;
                    j.next = temp;
                }

                previ = j;
                nexti = j.next;
                j = nextj;
                prevj.next = nextj;
                if (i == null || j == null) {
                    break;
                }
                nextj = nextj.next;
            }

            if (i.val < x) {
                previ = i;
                i = nexti;
                if (i == null || j == null) {
                    break;
                }
                nexti = i.next;
            }

            if (j.val >= x || i == j) {
                prevj = j;
                j = nextj;
                if (i == null || j == null) {
                    break;
                }
                nextj = j.next;
            }
        }

        return head;
    }
}