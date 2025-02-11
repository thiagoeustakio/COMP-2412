#include <iostream>
#include "ListADT.hpp"

using namespace std;

void traverselistaux(Node *n){
    cout << "--" << endl;
    cout << "node: " << n << endl; // address stored in l
    cout << "data: " << n->data << endl; // data
    cout << "next: " << n->next << endl; // address of next
    cout << "--" << endl;
    if (n->next!=nullptr){
        traverselistaux(n->next);
    }
}

Node* rec_reverse_aux(Node *n){
    if (n == nullptr) return n;
    if (n->next == nullptr) return n;
    
    Node* newhead = rec_reverse_aux(n->next);
    n->next->next = n;
    n->next = nullptr;
    return newhead;
}

void ListADT::insert_front(int num){
    Node *newNode = new Node;
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}

void ListADT::insert_end(int num){
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = nullptr;
    Node* temp = head;
    if (temp!=nullptr){
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
    head = newNode;    
}

void ListADT::traverselist(){
    if (head==nullptr) return;
    traverselistaux(head);
}

void ListADT::insert_ordered(int num){

    Node *newNode = new Node;
    newNode->data = num;

    //list empty
    if (head == nullptr){
        head = newNode;
        return;
        }

    //num is smaller than head->data
    if (num < head->data){
        newNode->next = head;
        head = newNode;
        return;
    }
    
    //num >= head->data, where should we insert?
    Node *temp = head;
    while (temp!=nullptr)
    {
        //num should be after temp
        if (num >= temp->data) 
        {
            //num should before temp->next
            if (temp->next != nullptr && num < temp->next->data){ 
                   newNode->next = temp->next;
                   temp->next = newNode;
                   return;
            }
            // there is no temp->next
            if(temp->next == nullptr){ 
                temp->next = newNode;
                return;
            }
            // num should be after temp->next
            // this could be risky
            // could lead to infinit loop
            if (num >= temp->next->data) 
            {
                temp = temp->next;
            }
        }
    }
}

void ListADT::rec_reverse(){
    head = rec_reverse_aux(head);
}