/*Implementation of Stack and Queue Operations using Ordered SLL */
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* link;
};

class Queuex {
private:
    struct qlist {
        Node* front;
        Node* rear;
        int count;

        qlist() {
            front = nullptr;
            rear = nullptr;
            count = 0;
        }
    };

    qlist queue;

public:
    Queuex() {
        queue = qlist();
    }

    bool isEmptyQueue() {
        return queue.count == 0;
    }

    void createQueue() {
        
        queue.front = nullptr;
        queue.rear = nullptr;
        queue.count = 0;
    }

    bool enqueue(int dataIn) {
        
        if (queue.count >= 10) { 
            return false;
        }

        Node* newNode = new Node;
        newNode->data = dataIn;
        newNode->link = nullptr;

        if (isEmptyQueue()) {
            queue.front = newNode;
        } else {
            queue.rear->link = newNode;
        }
        queue.rear = newNode;
        queue.count++;
        return true;
    }

    bool dequeue(int& item) {
        
        if (isEmptyQueue()) {
            return false; 
        }

        item = queue.front->data;
        Node* temp = queue.front;
        queue.front = queue.front->link;
        delete temp;
        queue.count--;

        if (isEmptyQueue()) {
            queue.rear = nullptr;
        }

        return true;
    }

    bool queueFront(int& dataOut) {
       
        if (isEmptyQueue()) {
            return false; 
        }

        dataOut = queue.front->data;
        return true;
    }

    bool queueRear(int& dataOut) {
       
        if (isEmptyQueue()) {
            return false; 
        }

        dataOut = queue.rear->data;
        return true;
    }

    int queueCount() {
       
        return queue.count;
    }

    void destroyQueue() {
        
        while (!isEmptyQueue()) {
            Node* temp = queue.front;
            queue.front = queue.front->link;
            delete temp;
            queue.count--;
        }
    }

    void displayQueue() {
    
        if (isEmptyQueue()) {
            cout << "Queue is empty." <<endl;
            return;
        }

        Node* current = queue.front;
        cout << "Queue elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->link;
        }
        cout <<endl;
    }
};

int main() {
    Queuex myQueue;
    int choice, data;

    do {
        cout << "1. Create Queue" <<endl;
        cout << "2. Enqueue" << endl;
        cout << "3. Dequeue" << endl;
        cout << "4. Queue Front" <<endl;
        cout << "5. Queue Rear" << endl;
        cout << "6. Is Empty Queue" <<endl;
        cout << "7. Count Queue" <<endl;
        cout << "8. Display Queue" <<endl;
        cout << "9. Destroy Queue" <<endl;
        cout << "10. Quit" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myQueue.createQueue();
                cout << "Queue created." <<endl;
                break;
            case 2:
                cout << "Enter data to enqueue: ";
                cin >> data;
                if (myQueue.enqueue(data)) {
                    cout << "Enqueued successfully." <<endl;
                } else {
                    cout << "Queue is full (Overflow)." <<endl;
                }
                break;
            case 3:
                if (myQueue.dequeue(data)) {
                    cout << "Dequeued data: " << data <<endl;
                } else {
                    std::cout << "Queue is empty (Underflow)." << std::endl;
                }
                break;
            case 4:
                if (myQueue.queueFront(data)) {
                    cout << "Front of the queue: " << data <<endl;
                } else {
                    cout << "Queue is empty." <<endl;
                }
                break;
            case 5:
                if (myQueue.queueRear(data)) {
                    std::cout << "Rear of the queue: " << data << std::endl;
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;
            case 6:
                if (myQueue.isEmptyQueue()) {
                    cout << "Queue is empty." <<endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 7:
                cout << "Queue count: " << myQueue.queueCount() << endl;
                break;
            case 8:
                myQueue.displayQueue();
                break;
            case 9:
                myQueue.destroyQueue();
                cout << "Queue destroyed." <<endl;
                break;
            case 10:
              cout << "Exiting program." <<endl;
                break;
            default:
                cout << "Invalid choice. Try again." <<endl;
        }
    } while (choice != 10);

    return 0;
}
