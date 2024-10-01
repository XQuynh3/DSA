//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 2 - Exercise 01
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
        node *temp = new node();
        temp->data = data;
        temp->link = NULL;
        if (phead == NULL) {
            phead = ptail = temp;
        } else {
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

    void addTwoNodes(int data1, int data2) {
        insertList(data1);
        insertList(data2);
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

    cout << "Danh sach truoc khi them node: ";
    l.print();


    int newData1, newData2;
    cout << "Nhap gia tri cho node moi 1: ";
    cin >> newData1;
    cout << "Nhap gia tri cho node moi 2: ";
    cin >> newData2;

    l.addTwoNodes(newData1, newData2);

    cout << "Danh sach sau khi them node: ";
    l.print();

    return 0;
}
