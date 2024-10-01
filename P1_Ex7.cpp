//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 1 - Exercise 07
//Notes or Remarks:

#include <iostream>
#include <stack>  
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


    bool isPalindrome() {
        stack<int> s;          
        node *current = phead;

        while (current != NULL) {
            s.push(current->data);
            current = current->link;
        }

        current = phead;
        while (current != NULL) {
            int top = s.top();  
            s.pop();           
            if (current->data != top) {
                return false;   
            }
            current = current->link;
        }

        return true;  
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

    cout << "Danh sach da nhap la: ";
    l.print();

    if (l.isPalindrome()) {
        cout << "Danh sach la palindrome." << endl;
    } else {
        cout << "Danh sach khong phai la palindrome." << endl;
    }

    return 0;
}
