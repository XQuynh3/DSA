//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 1 - Exercise 03
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

    static List mergeSorted(List &l1, List &l2) {
        List result;
        node *p1 = l1.phead;
        node *p2 = l2.phead;

        while (p1 != NULL && p2 != NULL) {
            if (p1->data < p2->data) {
                result.insertList(p1->data);
                p1 = p1->link;
            } else {
                result.insertList(p2->data);
                p2 = p2->link;
            }
        }

        while (p1 != NULL) {
            result.insertList(p1->data);
            p1 = p1->link;
        }

        while (p2 != NULL) {
            result.insertList(p2->data);
            p2 = p2->link;
        }

        return result;
    }
};

int main() {
    List l1, l2;

    int n1, n2;
    cout << "Nhap so phan tu cho danh sach 1: ";
    cin >> n1;
    cout << "Nhap gia tri danh sach 1 (sorted): ";
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        l1.insertList(x);
    }

    cout << "Nhap so phan tu cho danh sach 2: ";
    cin >> n2;
    cout << "Nhap gia tri danh sach 2 (sorted): ";
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        l2.insertList(x);
    }

    cout << "Danh sach 1: ";
    l1.print();

    cout << "Danh sach 2: ";
    l2.print();

    List mergedList = List::mergeSorted(l1, l2);

    cout << "Danh sach sau khi tron: ";
    mergedList.print();

    return 0;
}
