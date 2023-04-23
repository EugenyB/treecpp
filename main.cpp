#include <iostream>
#include <fstream>
#include "tree.h"

using namespace std;

tree * ReadFile(const char * fname) {
    ifstream fin(fname);
    tree * res = new tree;
    Person e;

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
    Person * p = t->find("Kate");
    if (p) {
        cout << p->id << " : " << p->fio << " : " << p->mark << endl;
    } else {
        cout << "Not Found";
    }

    t->removeElement("Kate");
    Person * p1 = t->find("Kate");
    if (p1) {
        cout << p1->id << " : " << p1->fio << " : " << p1->mark << endl;
    } else {
        cout << "Not Found";
    }

    return 0;
}