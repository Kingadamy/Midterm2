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

   void push_front(string v) { // function to add a node at the front
        Node* newNode = new Node(v); // create a new node
        if (!head) { // check if the list is empty
            head = tail = newNode; // if it is empty head and tail will point to new node
        } else { 
            newNode->next = head; // link new node to the old head
            head->prev = newNode; // link old head back to new node
            head = newNode;  // update head to new node
        }
        size++; 
    }

        void pop_front() { // function for removing a node from the front
        if (!head) { // check if the list is empty
            return; 
        }
        Node* temp = head;  // stores current head
        if (head->next) {  // if theres more than one node
            head = head->next; // we will update head to next node
            head->prev = nullptr;  // prev will be set to null
        } else {
            head = tail = nullptr; // eles head and tail will be null
        }
        delete temp; // free memory for the old head
        size--; 
    } 

     void pop_back() {  // function for removing a node from the back
        if (!tail) { // check if the list is empty
            return;
        }
        Node* temp = tail; // store current tail
        if (tail->prev) { // if theres more than one node
            tail = tail->prev; // update tail to previous node
            tail->next = nullptr; // next will be set to null
        } else {
            head = tail = nullptr; // else head and tail will be null
        }
        delete temp; // free memory for the old tail
        size--;
    }

    string get_front() { // gets data from the front node
        if (head) return head->data; // if head exists return its data
        return ""; // 
    }
    
    string get_back() {  // gets data from the back node
        if (tail) return tail->data; // if tail exists return its data
        return "";
    }
    
    bool is_empty() { // this will check if the list is empty
        return head == nullptr; // returns true if head is null
    }
    
    int get_size() { // this will return the size of the list
        return size;
    }

     void delete_customer(string name) { //this allows us to delete a customer by name
        if (!head) return; // check if the list is empty 
        Node* temp = head; // start from the head
        while (temp && temp->data != name) { //traverses list to find node with the name we want to delete
            temp = temp->next; // move to the next node
        }
        if (!temp) return; // if we dont find the name then we exit 
        
        if (temp->prev) {  // if node is not head
            temp->prev->next = temp->next; // the previous node will point to the next node
        } else {
            head = temp->next; // if it is head we update the head to next node
        }
        
        if (temp->next) { // if node is not tail
            temp->next->prev = temp->prev; // the next node will point back to the previous node
        } else {
            tail = temp->prev; // if it is tail we update tail to previous node
        }
        
        delete temp;  // free allocated memory for the node
        size--;
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