//STT: 22521234
//Full Name: Nguyen Thi Xuan Quynh
//Session 04 - Part 2 - Exercise 07
//Notes or Remarks:

#include <iostream>
#include <unordered_map>
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

    void removeZeroSumConsecutiveNodes() {
        unordered_map<int, node*> prefixSumMap;
        node *dummy = new node(0);
        dummy->link = phead;
        node *current = dummy;
        int prefixSum = 0;

        while (current != NULL) {
            prefixSum += current->data;
            prefixSumMap[prefixSum] = current;
            current = current->link;
        }

        current = dummy;
        prefixSum = 0;
        while (current != NULL) {
            prefixSum += current->data;
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                current->link = prefixSumMap[prefixSum]->link;
            }
            current = current->link;
        }

        phead = dummy->link;
        delete dummy;
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

    l.insertList(1);
    l.insertList(2);
    l.insertList(-3);
    l.insertList(3);
    l.insertList(1);
    l.insertList(-2);
    l.insertList(-1);

    cout << "Danh sach ban dau: ";
    l.print();

    l.removeZeroSumConsecutiveNodes();

    cout << "Danh sach sau khi xoa node co tong = 0: ";
    l.print();

    return 0;
}
