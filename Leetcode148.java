import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Main {

    static class Solution {
        public ListNode sortList(ListNode head) {
            ListNode node = head;
            List<Integer> list = new ArrayList<>();

            while (node != null) {
                list.add(node.val);
                node = node.next;
            }

            Collections.sort(list);

            ListNode start = null;
            ListNode end = null;

            for (int i : list) {
                ListNode n = new ListNode(i);
                if (start == null) {
                    start = n;
                    end = n;
                } else {
                    end.next = n;
                    end = n;
                }
            }
            return start;
        }
    }

    public static ListNode createList(int n, Scanner sc) {
        ListNode head = null, tail = null;
        for (int i = 0; i < n; i++) {
            int v = sc.nextInt();
            ListNode newNode = new ListNode(v);
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
        ListNode sorted = sol.sortList(head);

        printList(sorted);
    }
}
