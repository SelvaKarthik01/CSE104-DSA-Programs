/*Hash Search using DSA */
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* link;
};

struct Hash {
    int count;
    Node* head;
};


Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->data = key;
    newNode->link = nullptr;
    return newNode;
}

void insertToHash(Hash hashTable[], int size, int key) {
    int hashIndex = key % size;
    Node* newNode = createNode(key);
    newNode->link = hashTable[hashIndex].head;
    hashTable[hashIndex].head = newNode;
    hashTable[hashIndex].count++;
}

void deleteFromHash(Hash hashTable[], int size, int key) {
    int hashIndex = key % size;
    Node* delNode = hashTable[hashIndex].head;
    Node* temp = nullptr;

    while (delNode != nullptr) {
        if (delNode->data == key) {
            if (temp == nullptr) {
                hashTable[hashIndex].head = delNode->link;
            } else {
                temp->link = delNode->link;
            }
            delete delNode;
            hashTable[hashIndex].count--;
            return;
        }
        temp = delNode;
        delNode = delNode->link;
    }

    cout << "Given key is not present in hash table" << endl;
}

void searchInHash(Hash hashTable[], int size, int key) {
    int hashIndex = key % size;
    Node* searchNode = hashTable[hashIndex].head;

    while (searchNode != nullptr) {
        if (searchNode->data == key) {
            cout << "Key found: " << searchNode->data << endl;
            return;
        }
        searchNode = searchNode->link;
    }

    cout << "Search element not found in hash table" << endl;
}


void display(Hash hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        Node* temp = hashTable[i].head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    Hash hashTable[size];

    int choice, key;

    while (true) {
        cout << "1. Insert key\n2. Delete key\n3. Search key\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insertToHash(hashTable, size, key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                deleteFromHash(hashTable, size, key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                searchInHash(hashTable, size, key);
                break;
            case 4:
                display(hashTable, size);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
