#include <iostream>
#include "ListADT.hpp"

using namespace std;

void ListADT::insert_front(int num){
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}

void ListADT::traversal(){
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << "--" << endl;
        cout << "address of node: " << temp << endl;
        cout << "node data: " << temp->data << endl;
        cout << "node next: " << temp->next << endl;
        cout << "--" << endl;
        temp = temp->next;
    } 
}

void ListADT::rec_reverse(){
    this->head = rec_reverseaux(this->head);
}

Node* ListADT::rec_reverseaux(Node* n){
    if(n==nullptr) return n;
    if(n->next == nullptr) return n;

    Node* newhead = rec_reverseaux(n->next);
    // we have newhead and we have n
    n->next->next = n;
    // newhead->next = n;
    n->next = nullptr;

    return newhead;
}

void ListADT::insert_inOrder(int num){
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = nullptr;

    if(head == nullptr || num<head->data){
        newNode->next = head;
        head=newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != nullptr && temp->next->data <= num){
        temp = temp->next;
    }

    if (temp !=nullptr && temp->next!=nullptr){
        cout << "Inserting " << num << endl;
        cout << "temp: " << temp->data << " temp->next: " << temp->next->data << endl;
    }
    
    newNode->next = temp->next; // the list after tem is lost 
    temp->next = newNode; // the list before temp
}
