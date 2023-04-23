//
// Created by yevge on 11.05.2017.
//

#ifndef UNTITLED11_TREE_H
#define UNTITLED11_TREE_H

struct Person {
    int id;
    std::string fio;
    double mark;
};

struct Node {
    Person data;
    Node * left;
    Node * right;
};

class tree {
private:
    Node * root = nullptr;
    bool addElement(Person value, Node **pNode);
    void traverseTree(Node *pNode);
    void traverseTree(Node *pNode, int limit);
    Person * find(Node *pNode, std::string fio);
    void removeElement(std::string fio, Node **pNode);
    void removeEl(Node **pNode, Node **q);
public:
    bool add(Person e);
    void traverse();
    void printUnder(int limit);
    Person * find(std::string fio);
    void removeElement(std::string fio);
};


#endif //UNTITLED11_TREE_H
