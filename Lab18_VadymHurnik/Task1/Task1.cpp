#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node** head, int value) {
    if (*head == nullptr) {
        *head = createNode(value);
    }
    else {
        Node* currentNode = *head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(value);
    }
}

void switchAdjacentElements(Node** head) {
    Node* currentNode = *head;
    while (currentNode != nullptr && currentNode->next != nullptr) {
        if ((currentNode->data + currentNode->next->data) % 5 == 0) {
            int temp = currentNode->data;
            currentNode->data = currentNode->next->data;
            currentNode->next->data = temp;
        }
        currentNode = currentNode->next;
    }
}

int countSubstitutions(Node* head) {
    int count = 0;
    Node* currentNode = head;
    while (currentNode != nullptr && currentNode->next != nullptr) {
        if ((currentNode->data + currentNode->next->data) % 5 == 0) {
            count++;
        }
        currentNode = currentNode->next;
    }
    return count;
}

void displayList(Node* head) {
    Node* currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

void deleteList(Node** head) {
    Node* currentNode = *head;
    while (currentNode != nullptr) {
        Node* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    *head = nullptr;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    Node* head = nullptr;

    cout << "Enter the elements of the list:" << endl;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        insertNode(&head, value);
    }

    cout << "List before switching adjacent elements: ";
    displayList(head);

    switchAdjacentElements(&head);

    cout << "List after switching adjacent elements: ";
    displayList(head);

    int substitutions = countSubstitutions(head);
    cout << "Number of substitutions: " << substitutions << endl;

    deleteList(&head);

    return 0;
}
