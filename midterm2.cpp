#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
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

    vector<string> get_all_customers() { // create a vector to store all customer names
        vector<string> customers;  // this holds all customer names
        Node* current = head; // start from the head
        while (current) { 
            customers.push_back(current->data); // traverse the list and add each name to the vector
            current = current->next;    // move to the next node
        }
        return customers; // return the vector containing all customer names
    }
    void print() {  // function to print the list
            Node* current = head; // start from the head
            if (!current) { // if the list is empty
                cout << "        (empty)" << endl; // print empty message
                return;
            }
            while (current) { // traverse the list
                cout << "        " << current->data << endl; // print values to current node
                current = current->next; // move to the next node
            }
        }
        
        ~DoublyLinkedList() {  // use class destructor to free memory
            while (head) {  // if there are still nodes in the list
                Node* temp = head; // store current head
                head = head->next; // move head to next node
                delete temp; // free memory for the old head
            }
        }
    };


int main() {
  srand(time(0));
    
    vector<string> names; // vector to store names from file
    ifstream file("names.txt"); // open the names file
    string name; //holds each name read from the file
    while (file >> name) { // read names from the file
        names.push_back(name); // add each name to the vector
    }
    file.close();  // close the file after reading
    
    DoublyLinkedList line; // create the line using doubly linked list

     
    cout << "Store opens:" << endl;
    for (int i = 0; i < 5; i++) {  // 5 customers join the line
        string customer = names[rand() % names.size()]; // select random name from the list
        cout << "    " << customer << " joins the line" << endl; // blank joins the line
        line.push_back(customer); // add customer to the end of the line
    }
    cout << "    Resulting line:" << endl;
    line.print(); // print the entire line
    cout << endl; 

    for (int t = 2; t <= 20; t++) { // we need to simulate time steps from 2 to 20
        cout << "Time step #" << t << ":" << endl; // print time step
        
        if (!line.is_empty()) { // check if the line is not empty
            int prob = rand() % 100 + 1; // generate a random probability between 1 and 100
            if (prob <= 40) { // 40% chance to serve the front customer
                string customer = line.get_front(); // get the front customer
                cout << "    " << customer << " is served" << endl; // print served customer
                line.pop_front(); //remove custo from line once served
            }
        }
        
        int prob = rand() % 100 + 1; // generate a random probability between 1 and 100
        if (prob <= 10) { // 10% chance a VIP customer arrives
            string customer = names[rand() % names.size()]; // select random name from the list
            cout << "    " << customer << " (VIP) joins the front of the line" << endl; // print VIP joining the line
            line.push_front(customer); // add VIP customer to the front of the line
        }
        
        vector<string> customers = line.get_all_customers(); // get all customers in the line
        for (size_t i = 1; i < customers.size(); i++) { // start from 1 to skip the front customer
            int prob = rand() % 100 + 1; // generate a random probability between 1 and 100
            if (prob <= 10) { // 10% chance a customer leaves the line
                cout << "    " << customers[i] << " left the line" << endl; // print customer leaving the line
                line.delete_customer(customers[i]); // remove customer from the line
            }
        }
  prob = rand() % 100 + 1; // generate a random probability between 1 and 100
        if (prob <= 60) { // 60% chance a new customer arrives
            string customer = names[rand() % names.size()]; // select random name from the list
            cout << "    " << customer << " joins the line" << endl;    // print customer joining the line
            line.push_back(customer); // add customer to the end of the line
        }
        
        if (!line.is_empty()) { // check if the line is not empty
            prob = rand() % 100 + 1;    // generate a random probability between 1 and 100
            if (prob <= 20) {
                string customer = line.get_back(); // get the rear customer
                cout << "    " << customer << " (at the rear) left the line" << endl;   // print rear customer leaving the line
                line.pop_back();    // remove rear customer from the line
            }
        }
        
        cout << "    Resulting line:" << endl;  
        line.print();
        cout << endl;
    }
    
    return 0;
}