//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 1 - Exercise 05
//Notes or Remarks:

#include <iostream>
using namespace std;

struct node {
    int data;
    node *link;
};

struct List {
    node *phead = NULL;
    node *ptail = NULL;

    void insertList(int data) {
        if (phead == NULL) {
            node *tmp = new node();
            tmp->data = data;
            tmp->link = NULL;
            phead = tmp;
            ptail = tmp;
        } else {
            node *temp = new node();
            temp->data = data;
            temp->link = NULL;
            ptail->link = temp;
            ptail = temp;
        }
    }

    
    void print() {
        node *tmp = phead;
        if (tmp == NULL) {
            cout << "Danh sach rong." << endl;
            return;
        }
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->link;
        }
        cout << endl; 
    }

    
    void reverse() {
        node *prev = NULL;
        node *current = phead;
        node *next = NULL;

        while (current != NULL) {
            next = current->link; 
            current->link = prev; 
            prev = current;       
            current = next;      
        }
        phead = prev; 
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

    cout << "Danh sach truoc khi dao nguoc: ";
    l.print();

    l.reverse();

    cout << "Danh sach sau khi dao nguoc: ";
    l.print();

    return 0;
}
