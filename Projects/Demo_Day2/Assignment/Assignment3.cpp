// A complete working C++ program to delete
// a node in a linked list at a given position
#include <iostream>
using namespace std;

// A linked list node
class Node
{
	public:
	int data;
	Node *next;
};
int size = 0;
Node* getNode(int data)
{
    // allocating space
    Node* newNode = new Node();
 
    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


// Given a reference (pointer to pointer) to
// the head of a list and an int inserts a
// new node on the front of the list.
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Given a reference (pointer to pointer) to
// the head of a list and a position, deletes
// the node at the given position
void deleteNode(Node **head_ref, int position)
{
	
	// If linked list is empty
	if (*head_ref == NULL)
		return;
	
	// Store head node
	Node* temp = *head_ref;

	// If head needs to be removed
	if (position == 0)
	{
		
		// Change head
		*head_ref = temp->next;
		
		// Free old head
		free(temp);			
		return;
	}

	// Find previous node of the node to be deleted
	for(int i = 0; temp != NULL && i < position - 1; i++)
		temp = temp->next;

	// If position is more than number of nodes
	if (temp == NULL || temp->next == NULL)
		return;

	// Node temp->next is the node to be deleted
	// Store pointer to the next of node to be deleted
	Node *next = temp->next->next;

	// Unlink the node from linked list
	free(temp->next); // Free memory
	
	// Unlink the deleted node from list
	temp->next = next;
}

// This function prints contents of linked
// list starting from the given node
void printList( Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

/* Function to reverse the linked list */
    void reverse(Node** head_ref)
    {
        // Initialize current, previous and
        // next pointers
        Node* current = *head_ref;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        (*head_ref) = prev;
    }
void insertPos(Node** current, int pos, int data)
{
    // This condition to check whether the
    // position given is valid or not.
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else {
 
        // Keep looping until the pos is zero
        while (pos--) {
 
            if (pos == 0) {
 
                // adding Node at required position
                Node* temp = getNode(data);
 
                // Making the new Node to point to
                // the old Node at the same position
                temp->next = *current;
 
                // Changing the pointer of the Node previous
                // to the old Node to point to the new Node
                *current = temp;
            }
            else
              // Assign double pointer variable to point to the
              // pointer pointing to the address of next Node
              current = &(*current)->next;
        }
        size++;
    }
}
void deleteLL(Node *head){
	Node *temp = head;
	Node *temp2;
	while(temp !=nullptr)
	{
		temp2=temp->next;
		delete temp;
		temp=temp2;
	}
}
// Driver code
int main()
{
	
	// Start with the empty list
	Node* head = NULL;

	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);
	push(&head, 8);


	cout << "Created Linked List: ";
	printList(head);
	int data = 1, pos = 1;
    insertPos(&head, pos, data);
	cout << "\nLinked List after adding to an index : ";
	printList(head);
	deleteNode(&head, 5);
	cout << "\nLinked List after Deletion at position 4: ";
	printList(head);
    reverse(&head);
    cout << "\nLinked List after reverse: ";
    printList(head);
	cout << "\nLinked List deleted: ";
	deleteLL(head);
	printList(head);
	return 0;
}

