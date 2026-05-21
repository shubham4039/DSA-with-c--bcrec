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
class Solution {
    public ListNode deleteMiddle(ListNode head) {
      ListNode DummyNode = new ListNode(0);
      DummyNode.next = head;
      ListNode Slow = DummyNode;
      ListNode Fast = head;
      while(Fast != null && Fast.next != null){
        Slow = Slow.next;
        Fast = Fast.next.next;
      }
      Slow.next = Slow.next.next;
      return DummyNode.next;
    }
      }  