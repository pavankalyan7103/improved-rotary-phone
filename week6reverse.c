#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{ 
int data; 
struct Node *next; 
struct Node *prev;	 
}; 

void reverse(struct Node **head_ref) 
{ 
	struct Node *temp = NULL; 
	struct Node *current = *head_ref; 

	while (current != NULL) 
	{ 
	temp = current->prev; 
	current->prev = current->next; 
	current->next = temp;			 
	current = current->prev; 
	}	 

	if(temp != NULL ) 
		*head_ref = temp->prev; 
}	 

void push(struct Node** head_ref, int new_data) 
{ 
	
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
	new_node->data = new_data; 

	new_node->prev = NULL; 

	new_node->next = (*head_ref);	 

	if((*head_ref) != NULL) 
	(*head_ref)->prev = new_node ;	 

	(*head_ref) = new_node; 
} 


void printList(struct Node *node) 
{ 
while(node!=NULL) 
{ 
printf("%d ", node->data); 
node = node->next; 
} 
} 

int main() 
{ 

struct Node* head = NULL; 

	int i,n,data; 
	printf("enter number of nodes");
	scanf("%d",&n);
	

	for (i=0; i<n; i++) 
	{ 
	    printf("enter the data");
	    scanf("%d",&data);
		push(&head, data); 
	}

printf("\n before "); 
printList(head); 

reverse(&head); 

printf("\n after "); 
printList(head);		 

getchar(); 
} 

