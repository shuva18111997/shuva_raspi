#include <stdlib.h>
#include <stdio.h>	
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* insert(Node *head,int data)
{
    struct Node *Temp;
    struct Node *currentNode;
    if(head == NULL)
    {
        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = data;
        head->next = NULL;
    }
    else 
    {
        currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        Temp = (struct Node*)malloc(sizeof(struct Node));
        Temp->data = data;
        Temp->next = NULL;
        currentNode->next = Temp;
    }
    return head;
}

void display(Node *head)
{
	Node *start=head;
	while(start)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
int main()
{
	int T,data;
    scanf("%d",&T);
    Node *head=NULL;	
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    }
  display(head);
		
}
