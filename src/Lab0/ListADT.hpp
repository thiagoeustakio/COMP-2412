#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class ListADT
{
private:
    Node *head; // we will always keep this pointer
public:
    ListADT() : head{nullptr} {};
    // ~ListADT();
    void insert_front(int num);
    void traverselist();
    void insert_end(int num);
    void insert_ordered(int num);
    void rec_reverse();
};