#include <stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void makeloop(struct Node** head_ref, int k)
{
	struct Node* temp = *head_ref;
	int count = 1;
	while (count < k) {  //from kth node loop start
		temp = temp->next;
		count++;
	}
	struct Node* joint_point = temp;
    while (temp->next != NULL)
	temp = temp->next;
	temp->next = joint_point;//last node to kth elemnt
}
void push(struct Node** head_ref, int new_data)
{
struct Node* new_node =	(struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(struct Node* head, int total_nodes)
{
	struct Node* curr = head;
	int count = 0;
	while (count < total_nodes) {
		count++;
		printf("%d",curr->data);
		curr = curr->next;
	}
}
int countNodes(struct Node *ptr)
{
	int count = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return count;
}
int main()
{
	struct Node* head = NULL;
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	int k = 4;
	int total_nodes = countNodes(head);

	printf("given list");
	printList(head, total_nodes);
	makeloop(&head, k);
        printf("modified list");
	printList(head, total_nodes);
	return 0;
}

