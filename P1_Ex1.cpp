//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 1 - Exercise 01
//Notes or Remarks:

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

struct List
{
    node *phead = NULL;
    node * ptail = NULL;
    void insertList(int data) {
        if (phead == NULL) {
            node *tmp = new node();
            tmp -> data = data;
            tmp -> link = NULL;
            phead = tmp;
            ptail = tmp;
        } else {
            node *temp = new node();
            temp -> data = data;
            temp -> link = NULL;
            ptail -> link = temp;
            ptail = temp;
            
        }
    }

    void print() {
        node * tmp = phead;
        if (tmp == NULL) {
            cout << "Danh sach rong.";
            return;
        }
        cout << "Danh sach vua nhap la: ";
        while (tmp != NULL) {
            cout << tmp -> data << " ";
            tmp = tmp -> link;
        }
        
    }

    void printMiddle(int x) {
        node * tmp = phead;
        if (tmp == NULL) {
            cout << "Danh sach rong.";
            return;
        }
        int count = 0;
        while (tmp != NULL) {
            if (count == (x)) {
                cout << tmp -> data;
                return;
            } else {
                count = count + 1;
                tmp = tmp -> link;
            }
        }
        
    }

    void findMiddle(int n) {


        if (n == 1 || n == 2) {
            cout << "No middle node";
            return;
        } else if (n % 2 != 0) {
            int x = n / 2;
            cout << "Middle node la: ";
            printMiddle(x);
        } else {
            cout << "Middle node la: ";
            int x = (n / 2) - 1;
            printMiddle(x);
            cout << " và ";
            x = (n / 2);
            printMiddle(x);

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
    l.findMiddle(n);
    
}

