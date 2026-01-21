import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}

public class Main {

    static class Solution {
        public void reorderList(ListNode head) {

            if (head == null) return;

            ListNode slow = head, fast = head;
            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
            }

            ListNode second = slow.next;
            slow.next = null;

            ListNode node = null;
            while (second != null) {
                ListNode temp = second.next;
                second.next = node;
                node = second;
                second = temp;
            }

            ListNode first = head;
            second = node;

            while (second != null) {
                ListNode temp1 = first.next, temp2 = second.next;
                first.next = second;
                second.next = temp1;
                first = temp1;
                second = temp2;
            }
        }
    }

    public static ListNode createList(int n, Scanner sc) {
        ListNode head = null, tail = null;
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            ListNode newNode = new ListNode(val);
            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }
        return head;
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) System.out.print(" ");
            head = head.next;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        ListNode head = createList(n, sc);

        Solution sol = new Solution();
        sol.reorderList(head);

        printList(head);
    }
}
