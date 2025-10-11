
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] ans = new ListNode[k];
        int len = 0;
        for (ListNode current = head; current != null; current = current.next)
            len++;
        int base = len / k, extra = len % k;
        ListNode current = head;

        for (int i = 0; i < k && current != null; i++) {
            ans[i] = current;
            int partlength = base + (extra-- > 0 ? 1 : 0);
            for (int j = 1; j < partlength; j++) current = current.next;
            ListNode next = current.next;
            current.next = null;
            current = next;
        }
        return ans;
    }
}

public class Main {
    public static void printParts(ListNode[] parts) {
        for (ListNode head : parts) {
            ListNode cur = head;
            while (cur != null) {
                System.out.print(cur.val + " ");
                cur = cur.next;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Create linked list: 1->2->3->4->5->6->7
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(6);
        head.next.next.next.next.next.next = new ListNode(7);

        int k = 3;
        Solution sol = new Solution();
        ListNode[] parts = sol.splitListToParts(head, k);
        printParts(parts);
    }
}
