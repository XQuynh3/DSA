//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 2 - Exercise 05
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

    void separateOddEven() {
        if (phead == NULL) return;

        node *oddHead = NULL;
        node *oddTail = NULL;
        node *evenHead = NULL;
        node *evenTail = NULL;

        node *current = phead;
        while (current != NULL) {
            if (current->data % 2 == 0) {
                if (evenHead == NULL) {
                    evenHead = evenTail = current;
                } else {
                    evenTail->link = current;
                    evenTail = evenTail->link;
                }
            } else {
                if (oddHead == NULL) {
                    oddHead = oddTail = current;
                } else {
                    oddTail->link = current;
                    oddTail = oddTail->link;
                }
            }
            current = current->link;
        }

        if (oddTail) {
            oddTail->link = evenHead;
            if (evenTail) {
                evenTail->link = NULL;
            }
            phead = oddHead;
        } else {
            phead = evenHead;
        }
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

    cout << "Danh sach truoc khi phan tach: ";
    l.print();

    l.separateOddEven();

    cout << "Danh sach sau khi phan tach: ";
    l.print();

    return 0;
}
