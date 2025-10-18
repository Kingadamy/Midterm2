#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


class DoublyLinkedList { //double linked list class
private:
    struct Node { // node structure
        string data; // store string data
        Node* prev; // points to previous node
        Node* next; // points to next node

Node(string val, Node* p = nullptr, Node* n = nullptr) { // here we make a constructor for the node
    data = val;
    prev = p;
    next = n;
    }
};


Node* head;  // pointer to head 
Node* tail;  // pointer to tail
int size;    // size of the list


public:
DoublyLinkedList() {
head = nullptr; 
tail = nullptr; 
size = 0; 
}

  void push_back(string v) {  // function to add a node at the end
        Node* newNode = new Node(v); // create a new node
        if (!tail) { // if the list is empty
            head = tail = newNode; // head and tail point to the new node
        } else {
            tail->next = newNode; // link the old tail to the new node
            newNode->prev = tail; // link the new node back to the old tail
            tail = newNode; // update tail to  new node
        }
        size++;
    }




void insert_after(int value, int position) {
if (position < 0) {
cout << "Position must be >= 0." << endl;
return;
}
Node* newNode = new Node(value);
if (!head) {
head = tail = newNode;
return;
}
Node* temp = head;
for (int i = 0; i < position && temp; ++i)
temp = temp->next;
if (!temp) {
cout << "Position exceeds list size. Node not inserted.\n";
delete newNode;
return;
}
newNode->next = temp->next;
newNode->prev = temp;
if (temp->next)
temp->next->prev = newNode;
else
tail = newNode;
temp->next = newNode;
}
void delete_val(int value) {
if (!head) return;
Node* temp = head;
while (temp && temp->data != value)
temp = temp->next;
if (!temp) return;
if (temp->prev)
temp->prev->next = temp->next;
else
head = temp->next;
if (temp->next)
temp->next->prev = temp->prev;
else
tail = temp->prev;
delete temp;
}
void delete_pos(int pos) {
if (!head) {
cout << "List is empty." << endl;
return;
}
if (pos == 1) {
pop_front();
return;
}
Node* temp = head;
for (int i = 1; i < pos; i++){
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
else
temp = temp->next;
}
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
if (!temp->next) {
pop_back();
return;
}
Node* tempPrev = temp->prev;
tempPrev->next = temp->next;
temp->next->prev = tempPrev;
delete temp;
}

void push_front(int v) {
Node* newNode = new Node(v);
if (!head)
head = tail = newNode;
else {
newNode->next = head;
head->prev = newNode;
head = newNode;
}
}
void pop_front() {
if (!head) {
cout << "List is empty." << endl;
return;
}
Node * temp = head;
if (head->next) {
head = head->next;
head->prev = nullptr;
}
else
head = tail = nullptr;
delete temp;
}
void pop_back() {
if (!tail) {
cout << "List is empty." << endl;
return;
}
Node * temp = tail;
if (tail->prev) {
tail = tail->prev;
tail->next = nullptr;
}
else
head = tail = nullptr;
delete temp;
}
~DoublyLinkedList() {
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
}
void print() {
Node* current = head;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}
void print_reverse() {
Node* current = tail;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->prev;
}
cout << endl;
}
};
int main() {
cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning

return 0;
}