#include <iostream>
#include "ListADT.hpp"

int main(int argc, char** argv){
    ListADT mylist;
    mylist.insert_inOrder(1);
    mylist.insert_inOrder(2);
    mylist.insert_inOrder(3);
    mylist.insert_inOrder(4);
    mylist.traversal();
    // mylist.rec_reverse();
    // std::cout << "-----------Reversed-------------" << std::endl;
    // mylist.traversal();
}