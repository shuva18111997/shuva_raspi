import java.io.*;
import java.util.*;
class Node{
	int data;
	Node next;
	Node(int d){
        data=d;
        next=null;
    }
	
}
class Solution
{
  
    public static Node removeDuplicates(Node head) {
    if (head == null || head.next == null){
        return head;
    }
    if (head.data == head.next.data){
        head.next = head.next.next;
        removeDuplicates(head);
    }else{
        removeDuplicates(head.next);
    }
    return head;
}

	 public static  Node insert(Node head,int data)