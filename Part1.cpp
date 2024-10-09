
#include <iostream>
#include <string>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
public:
    node *phead = NULL;

    void push(int data) {
        node* tmp = new node(data);
        if (phead == NULL) {
            phead = tmp;
        } else {
            tmp->next = phead;
            phead = tmp;
        }
    }

    void pop() {
        if (phead == NULL) {
            cout << "Stack is empty, cannot pop.\n";
            return;
        } else {
            node* tmp = phead;
            phead = phead->next;
            delete tmp;
        }
    }

    bool isEmpty() {
        return phead == NULL;
    }

    bool isFull() {
        return false;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        } else {
            node* tmp = phead;
            while (tmp != NULL) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    bool isValidBracketSequence(string s) {
        Stack stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (stack.isEmpty()) return false;
                char top = stack.phead->data;
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    string reverseWords(string str) {
        Stack stack;
        string result = "", word = "";
        for (char c : str) {
            if (c == ' ') {
                while (!stack.isEmpty()) {
                    result += stack.phead->data;
                    stack.pop();
                }
                result += ' ';
            } else {
                stack.push(c);
            }
        }

        while (!stack.isEmpty()) {
            result += stack.phead->data;
            stack.pop();
        }
        return result;
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Push several numbers onto the stack\n";
    cout << "2. Check if the stack is empty\n";
    cout << "3. Check if the stack is full\n";
    cout << "4. Check if a bracket sequence is valid\n";
    cout << "5. Reverse words in a string\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Stack A;
    int choice, a;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter several integers to push onto the stack (0 to stop): ";
                while (true) {
                    cin >> a;
                    if (a == 0) break;
                    A.push(a);
                }
                A.print();
                break;
            }
            case 2:
                if (A.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;

            case 3:
                if (A.isFull())
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                break;

            case 4: {
                cout << "Enter a bracket sequence: ";
                string bracketSequence;
                cin >> bracketSequence;
                if (A.isValidBracketSequence(bracketSequence)) {
                    cout << "The bracket sequence is valid.\n";
                } else {
                    cout << "The bracket sequence is invalid.\n";
                }
                break;
            }

            case 5: {
                cin.ignore();
                cout << "Enter a string to reverse words: ";
                string inputString;
                getline(cin, inputString);
                cout << A.reverseWords(inputString) << endl;
                break;
            }

            case 6:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
