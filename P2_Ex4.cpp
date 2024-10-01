//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 2 - Exercise 04
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

    void removeNthFromEnd(int n) {
        node *current = phead;
        node *prev = NULL;
        int length = 0;

        while (current != NULL) {
            length++;
            current = current->link;
        }

        if (n >= length) {
            node *temp = phead;
            phead = phead->link;
            delete temp;
            return;
        }

        current = phead;

        for (int i = 0; i < length - n; i++) {
            prev = current;
            current = current->link;
        }

        if (prev != NULL) {
            prev->link = current->link;
        }
        delete current;
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

int main() {
    List l;

    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    cout << "Nhap gia tri: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.insertList(x);
    }

    cout << "Danh sach truoc khi xoa: ";
    l.print();

    int removeN;
    cout << "Nhap gia tri N de xoa node thu N tu cuoi: ";
    cin >> removeN;

    l.removeNthFromEnd(removeN);

    cout << "Danh sach sau khi xoa: ";
    l.print();

    return 0;
}
