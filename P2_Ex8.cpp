//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 2 - Exercise 08
//Notes or Remarks:

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node {
    int data;
    node *link;

    node(int val) {
        data = val;
        link = NULL;
    }
};

struct List {
    node *phead = NULL;
    node *ptail = NULL;

    void insertList(int data) {
        node *temp = new node(data);
        if (phead == NULL) {
            phead = ptail = temp;
        } else {
            ptail->link = temp;
            ptail = temp;
        }
    }

    void print() {
        node *current = phead;
        if (current == NULL) {
            cout << "Danh sach rong." << endl;
            return;
        }
        while (current != NULL) {
            cout << current->data << " ";
            current = current->link;
        }
        cout << endl; 
    }

    ~List() {
        node *current = phead;
        while (current != NULL) {
            node *next = current->link;
            delete current;
            current = next;
        }
    }
};

void generateRandomList(List &l) {
    srand(time(0));
    int numEntries = rand() % 21 + 39;

    for (int i = 0; i < numEntries; i++) {
        int randomValue = rand() % 199 - 99;
        l.insertList(randomValue);
    }
}

int main() {
    List l;

    generateRandomList(l);

    cout << "Danh sach duoc tao ngau nhien: ";
    l.print();

    return 0;
}
