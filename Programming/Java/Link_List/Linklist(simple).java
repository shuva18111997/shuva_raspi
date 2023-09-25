class Node
{
	int data;
	Node next;
	
	public Node(int data)
	{
		this.data = data;
		next = null;
	}
}

class Linklist
{
	Node head;
	
	public static void main(String args[])
	{
		/* Start with the empty list. */
		Linklist list = new Linklist();
		
		list.head = new Node(10);
		Node SecondNode = new Node(20);
		Node ThirdNode = new Node(30);
		/* Three nodes have been allocated dynamically. 
          We have references to these three blocks as head,   
          second and third 
  
          llist.head        second              third 
             |                |                  | 
             |                |                  | 
         +----+------+     +----+------+     +----+------+ 
         | 1  | null |     | 2  | null |     |  3 | null | 
         +----+------+     +----+------+     +----+------+ */
		
		list.head.next = SecondNode;	// Link first node with the second node 
		
		/*  Now next of the first Node refers to the second.  So they 
            both are linked. 
  
         llist.head        second              third 
            |                |                  | 
            |                |                  | 
        +----+------+     +----+------+     +----+------+ 
        | 1  |  o-------->| 2  | null |     |  3 | null | 
        +----+------+     +----+------+     +----+------+ */
		
		SecondNode.next = ThirdNode;	// Link second node with the third node 
		
		/*  Now next of the second Node refers to third.  So all three 
            nodes are linked. 
  
         llist.head        second              third 
            |                |                  | 
            |                |                  | 
        +----+------+     +----+------+     +----+------+ 
        | 1  |  o-------->| 2  |  o-------->|  3 | null | 
        +----+------+     +----+------+     +----+------+ */
		
		//ThirdNode.next = null; --> this line is not required because the 'next' is null by the Node constructor.
		
		/*
		Linklist list = new Linklist();
		list.head = new Node(10);
		list.head.next = new Node(20);
		list.head.next.next = new Node(30);
		list.head.next.next.next = new Node(40);
		*/
		
		/*Now print the Link list*/
		print_the_List(list.head);
	}
	
	static void print_the_List(Node n)
	{
		while(n != null)
		{
			System.out.println(n.data);
			n = n.next;
		}
	}
}