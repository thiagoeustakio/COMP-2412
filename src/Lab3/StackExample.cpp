#include <iostream>

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int num) : data(num) {}
};

class Stack
{
public:
    int size;
    Node *bottom;
    Node *top;

    Stack() : size(0), bottom(nullptr), top(nullptr) {}

    void push(int data)
    {
        Node *newNode = new Node(data);

        if (bottom == nullptr)
        {
            bottom = newNode;
            top = newNode;
        }
        else
        {
            top->next = newNode;
            top = newNode;
        }
        size++;
    }

    int pop(){
        if(bottom == nullptr){
            return -1;
        }

        if(top == bottom){
            int tdata = top->data;
            delete top;
            delete bottom;
            top =nullptr;
            bottom = nullptr;
            return tdata;
        }
    }

    void print()
    {
        std::cout << std::endl;
        recprint(bottom);
        std::cout << std::endl;
    }

    void recprint(Node *p)
    {
        if (p == nullptr)
        {
            return;
        }
        std::cout << p->data << " ";

        return recprint(p->next);
    }
};

int main()
{

    Stack dstack;

    dstack.push(1);
    dstack.push(2);
    dstack.push(3);

    dstack.print();

    return 0;
}