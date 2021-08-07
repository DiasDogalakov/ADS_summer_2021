#include <iostream>
using namespace std;

struct Node {
    string word;
    Node* next;

    Node() {}

    Node(string word) {
        this->word = word;
        this->next = NULL;
    }
};

// your code goes here

Node* cyclicShift(Node* head, int k) {
    Node* pointer = head;
    Node* to_concatanate = head;
    while (k > 1) {
        pointer = pointer->next;
        k--;
    }
    Node* new_head = pointer->next;
    pointer->next = NULL;
    Node* pointer2 = new_head;
    while (pointer2->next != NULL) {
        pointer2 = pointer2->next;
    }
    pointer2->next = to_concatanate;
    return new_head;
}

void print(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->word << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    int k; cin >> k;
    Node* head;
    Node* cur;
    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        if (i == 0) {
            head = new Node(word);
            cur = head;
        } else {
            cur->next = new Node(word);
            cur = cur->next;
        }
    }

    head = cyclicShift(head, k);
    print(head);
}