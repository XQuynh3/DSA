/*
MSSV: 22521234
Full name: Nguyen Thi Xuan Quynh
Lab2 - In-Class Part 2
*/

#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node *next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node *head, *tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    bool isFull() {
        return false;
    }

    void enqueue(int val) {
        Node *newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
    }

    int front() {
        if (isEmpty()) throw runtime_error("Queue is empty.");
        return head->value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            Node *temp = head;
            while (temp != nullptr) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

void simulateBankQueue() {
    Queue bankQueue;

    for (int i = 1; i <= 10; ++i) {
        bankQueue.enqueue(i);
    }

    cout << "Initial queue: ";
    bankQueue.display();

    for (int i = 0; i < 10; ++i) {
        int customer = bankQueue.front();
        bankQueue.dequeue();

        if (i % 4 == 0) {
            cout << "Customer " << customer << " has insufficient paperwork, returning to the end of the queue.\n";
            bankQueue.enqueue(customer);
        } else {
            cout << "Customer " << customer << " is being assisted.\n";
        }
    }

    cout << "Final queue: ";
    bankQueue.display();
}

void enterDancers(Queue &q) {
    string s;
    while (true) {
        cin >> s;
        if (s == "0") break;
        q.enqueue(s[0]); 
    }
}

void dancePairing() {
    Queue maleQueue, femaleQueue;
    
    cout << "Enter the male's name (0 to stop): \n";
    enterDancers(maleQueue);
    
    cout << "Enter the female's name (0 to stop): \n";
    enterDancers(femaleQueue);

    while (!maleQueue.isEmpty() && !femaleQueue.isEmpty()) {
        cout << "Pairing: Male " << char(maleQueue.front()) << " with Female " << char(femaleQueue.front()) << '\n';
        maleQueue.dequeue();
        femaleQueue.dequeue();
    }

    // Handling the "spares"
    if (!maleQueue.isEmpty()) cout << "Spare males: ";
    while (!maleQueue.isEmpty()) {
        cout << char(maleQueue.front()) << " ";
        maleQueue.dequeue();
    }

    if (!femaleQueue.isEmpty()) cout << "Spare females: ";
    while (!femaleQueue.isEmpty()) {
        cout << char(femaleQueue.front()) << " ";
        femaleQueue.dequeue();
    }
    cout << '\n';
}


void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Enqueue numbers into the queue\n";
    cout << "2. Input and display the queue\n";
    cout << "3. Check if the queue is empty\n";
    cout << "4. Check if the queue is full\n";
    cout << "5. Simulate Bank Queue scenario\n";
    cout << "6. Simulate Dance Floor pairing\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Queue myQueue;
    int choice, n;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Queue initialized.\n";
                break;

            case 2: {
                cout << "Enter integers to enqueue (0 to stop): ";
                cin >> n;
                while (n != 0) {
                    myQueue.enqueue(n);
                    cin >> n;
                }
                cout << "Queue elements: ";
                myQueue.display();
                break;
            }

            case 3:
                cout << (myQueue.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;

            case 4:
                cout << (myQueue.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;

            case 5:
                simulateBankQueue();
                break;

            case 6:
                dancePairing();
                break;

            case 7:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
