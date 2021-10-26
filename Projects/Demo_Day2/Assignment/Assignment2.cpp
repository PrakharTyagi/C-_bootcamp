#include <iostream>
using namespace std;
struct Node
{
    int data;
	Node* next;
};
struct Node* head = NULL;

void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}
void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }}

void del(){
//Find the previous node of the node to be deleted. 
//Change the next of the previous node. 
//Free memory for the node to be deleted.
   	//Node* temp = *head_ref;

    *head->Node::next;
    // Change head
		//*head_ref = temp->next;
		
		// Free old head
		free(head);			
		return;
}


int main() {
    struct Node* head = NULL;
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The linked list is: ";
   display();
    del();
    cout<<"The linked list is: ";
   display();
   return 0;
}