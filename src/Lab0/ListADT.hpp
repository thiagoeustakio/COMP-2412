
class Node{
public:
    int data;
    Node* next;
};

class ListADT{
    private:
        Node* head;
        Node* rec_reverseaux(Node* n);
    public:
        ListADT() : head(nullptr) {};
        void insert_front(int num);
        void traversal();
        void rec_reverse();
        void insert_inOrder(int num);
};

