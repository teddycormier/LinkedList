#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to traverse the linked list
void traverse(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to add a node before the third node
void addBeforeThird(Node* head, int newData) {
    Node* current = head;
    int count = 1;
    while (count < 3 && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        cout << "List does not have three nodes." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = current->next;
    current->next = newNode;
}

// Function to add a node before the first node
void addBeforeFirst(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end
void addAtEnd(Node* head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete the node after the first node
void deleteAfterFirst(Node* head) {
    if (head->next == NULL) {
        cout << "List has only one node." << endl;
        return;
    }
    Node* nodeToDelete = head->next;
    head->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Function to delete the first node
void deleteFirst(Node** head) {
    if (*head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* nodeToDelete = *head;
    *head = (*head)->next;
    delete nodeToDelete;
}

// Function to delete the last node
void deleteLast(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
}

// Main function
int main() {
    Node* head = NULL;
    Node* temp = NULL;
    Node* new_node = NULL;

    int num_nodes, value;

    cout << "\nEnter the number of nodes: ";
    cin >> num_nodes;

    for (int i = 0; i < num_nodes; i++) {
        new_node = new Node();

        cout << "Enter the value for node " << i + 1 << ": ";
        cin >> value;

        new_node->data = value;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }

    int choice;
    do {
        cout << "\n---------------------------------------" << endl;
        cout << "| Linked List Menu:                   |" << endl;
        cout << "| 1. Traverse                         |" << endl;
        cout << "| 2. Add node before the third node   |" << endl;
        cout << "| 3. Add node before the first node   |" << endl;
        cout << "| 4. Add node at the end              |" << endl;
        cout << "| 5. Delete node after the first node |" << endl;
        cout << "| 6. Delete the first node            |" << endl;
        cout << "| 7. Delete the last node             |" << endl;
        cout << "| 0. Exit                             |" << endl;
        cout << "---------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1:
                traverse(head);
                break;
            case 2:
                int newData;
                cout << "Enter data for new node: ";
                cin >> newData;
                addBeforeThird(head, newData);
                traverse(head);
                break;
            case 3:
                cout << "Enter data for new node: ";
                cin >> newData;
                addBeforeFirst(&head, newData);
                traverse(head);
                break;
            case 4:
                cout << "Enter data for new node: ";
                cin >> newData;
                addAtEnd(head, newData);
                traverse(head);
                break;
            case 5:
                deleteAfterFirst(head);
                traverse(head);
                break;
            case 6:
                deleteFirst(&head);
                traverse(head);
                break;
            case 7:
                deleteLast(head);
                traverse(head);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);
}
