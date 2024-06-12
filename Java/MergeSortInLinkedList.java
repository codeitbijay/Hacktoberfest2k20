import java.util.List;
import java.util.Scanner;

class MergeSortInLinkedList {
    public Node mergeSort(Node h) {
        if (h == null || h.next == null) {
            return h;
        }
        Node middle = getMiddle(h);
        Node nextOfMiddle = middle.next;
        middle.next = null;
        Node left = mergeSort(h);
        Node right = mergeSort(nextOfMiddle);
        Node sortedList = sortedMerge(left, right);
        return sortedList;
    }

    public Node getMiddle(Node head) {
        if (head == null) {
            return head;
        }
        Node slow = head, fast = head;
        while (slow.next != null || fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public Node sortedMerge(Node left, Node right) {
        Node result = null;
        if (left == null) {
            return right;
        } else if (right == null) {
            return left;
        } else {
            if (left.data <= right.data) {
                result = left;
                result.next = sortedMerge(left.next, right);
            } else {
                result = right;
                result.next = sortedMerge(left, right.next);
            }
        }
        return result;
    }

    public void print(Node head) {
        while (head != null) {
            System.out.println(head.data);
            head = head.next;
        }
    }
}

class Node {
    int data;
    Node next;

    public Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
