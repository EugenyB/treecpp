#include <iostream>
#include <fstream>
#include "tree.h"

using namespace std;

tree * ReadFile(const char * fname) {
    ifstream fin(fname);
    tree * res = new tree;
    elem e;

    while (fin >> e.id >> e.fio >> e.mark) {
        res->add(e);
    }
    return res;
}

int main() {
    tree * t;
    t = ReadFile("file.txt");
    t->traverse();
    cout << "---------------------" << endl;
    t->printUnder(66);
    return 0;
}