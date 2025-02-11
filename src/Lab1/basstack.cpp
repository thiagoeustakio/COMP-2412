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
            // delete bottom;
            top =nullptr;
            bottom = nullptr;
            return tdata;
        }
        int tdata = top->data;
        Node* previous;
        previous = bottom;
        while (previous->next != top)
        {
            previous = previous->next;
        }
        delete top;
        previous->next = nullptr;
        top = previous;
        return tdata;
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


        recprint(p->next);
    }
};

int main()
{

    Stack dstack;

    for (size_t i = 0; i < 50000; i++)
    {
        dstack.push(i);
    }

    for (size_t i = 0; i < 50000; i++)
    {
        dstack.pop();
    }

    // dstack.print();

    // std::cout << "Popped: " << dstack.pop() << std::endl;

    // std::cout << "top: " << dstack.top->data << std::endl;

    // std::cout << "bottom: " << dstack.bottom->data << std::endl;

    // dstack.print();

    // std::cout << "Popped: " << dstack.pop() << std::endl;
    // dstack.print();


    return 0;
}