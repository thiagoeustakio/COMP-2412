#include <iostream>
#include "ListADT.hpp"

int main(int argc, char** argv){
    ListADT list;
    
    if (argc < 2){
        cout << "please run ./executable 1 2 3 ... " << endl;
        return -1;
    }

    for (int i = 1; i<argc; i++){
        cout << "------> Inserting " << argv[i] << endl;
        list.insert_ordered(std::atoi(argv[i]));
        // list.traverselist();
    }
    list.traverselist();

    cout << "Reversing list:" << endl;

    list.rec_reverse();
    list.traverselist();

    cout << endl;   
}