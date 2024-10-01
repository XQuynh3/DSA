//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 1 - Exercise 06
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


    void removeDuplicates() {
        node *current = phead;

        while (current != NULL && current->link != NULL) {
            if (current->data == current->link->data) {
                node *duplicate = current->link;
                current->link = current->link->link;  
                delete duplicate;                     
            } else {
                current = current->link; 
            }
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

    cout << "Nhap gia tri (da sorted): ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.insertList(x);
    }

    l.removeDuplicates();

    cout << "Danh sach sau khi xoa duplicate: ";
    l.print();

    return 0;
}
