//
// Created by yevge on 11.05.2017.
//

#ifndef UNTITLED11_TREE_H
#define UNTITLED11_TREE_H

struct elem {
    int id;
    char fio[20];
    int mark;
};

struct node {
    elem data;
    node * left;
    node * right;
};

class tree {
private:
    node * root = nullptr;
    bool addElement(elem value, node **pNode);
    void traverseTree(node *pNode);
    void traverseTree(node *pNode, int limit);
public:
    bool add(elem e);
    void traverse();
    void printUnder(int limit);

};


#endif //UNTITLED11_TREE_H
