//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 2 - Exercise 06
//Notes or Remarks:

#include <iostream>
#include <vector>
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

    vector<List*> divide(int k) {
        vector<List*> parts(k, nullptr);
        int len = 0;

        node *current = phead;
        while (current != NULL) {
            len++;
            current = current->link;
        }

        int partSize = len / k;
        int extra = len % k;

        current = phead;
        for (int i = 0; i < k; i++) {
            parts[i] = new List();
            for (int j = 0; j < partSize + (i < extra ? 1 : 0); j++) {
                if (current != NULL) {
                    parts[i]->insertList(current->data);
                    current = current->link;
                }
            }
        }

        return parts;
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

    int k;
    cout << "Nhap so phan: ";
    cin >> k;

    cout << "Danh sach ban dau: ";
    l.print();

    vector<List*> parts = l.divide(k);

    for (int i = 0; i < k; i++) {
        cout << "Part " << i + 1 << ": ";
        parts[i]->print();
    }

    for (List* part : parts) {
        delete part;
    }

    return 0;
}
