
#include "AVL.hpp"
#include "AVLLIST.hpp"
#include "Stack.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    Control* avllist = new Control();

    ifstream file("Veri.txt");
    if (!file.is_open())
    {
        cout << "Dosya acilamadi" << endl;
        return 1;
    }
    int sayi=1;
    string row;
    while (getline(file, row))
    {        

        if(row.empty())
        {
            continue;
        }

        istringstream iss(row);
        AVL* avl = new AVL(sayi);

        sayi++;
        
        int num;
        while (iss >> num)
        {
            avl->Add(num);
        }

        avllist->addtree(avl);
    }   

    file.close();

    avllist->lastfunc();

    delete avllist;
    return 0;

}

