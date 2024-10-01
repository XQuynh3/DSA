//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 1 - Exercise 04
//Notes or Remarks:

#include <iostream>
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

node* findIntersection(List& list1, List& list2) {
    node *current1 = list1.phead;
    while (current1 != NULL) {
        node *current2 = list2.phead;
        while (current2 != NULL) {
            if (current1 == current2) {
                return current1;
            }
            current2 = current2->link;
        }
        current1 = current1->link;
    }
    return NULL;
}

int main() {
    List list1, list2;

    list1.insertList(1);
    list1.insertList(2);
    list1.insertList(3);
    
    list2.insertList(4);
    list2.insertList(5);
    
    list2.phead->link = list1.phead->link;

    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();

    node* intersection = findIntersection(list1, list2);
    
    if (intersection != NULL) {
        cout << "Intersection found at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
