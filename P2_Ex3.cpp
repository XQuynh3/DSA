//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 2 - Exercise 03
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

    void swapNodes(int x, int y) {
        if (x == y) return;

        node *prevX = NULL, *currX = phead;
        while (currX && currX->data != x) {
            prevX = currX;
            currX = currX->link;
        }

        node *prevY = NULL, *currY = phead;
        while (currY && currY->data != y) {
            prevY = currY;
            currY = currY->link;
        }

        if (!currX || !currY) return;

        if (prevX) {
            prevX->link = currY;
        } else {
            phead = currY;
        }

        if (prevY) {
            prevY->link = currX;
        } else {
            phead = currX;
        }

        node *temp = currX->link;
        currX->link = currY->link;
        currY->link = temp;
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

    cout << "Danh sach truoc khi swap: ";
    l.print();

    int x, y;
    cout << "Nhap gia tri node 1 de swap: ";
    cin >> x;
    cout << "Nhap gia tri node 2 de swap: ";
    cin >> y;

    l.swapNodes(x, y);

    cout << "Danh sach sau khi swap: ";
    l.print();

    return 0;
}
