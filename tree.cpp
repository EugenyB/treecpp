//
// Created by yevge on 11.05.2017.
//

#include <cstring>
#include <iostream>
#include "tree.h"

bool tree::addElement(elem value, node **pNode) {
    if (*pNode == nullptr) {
        node *t = new node;
        t->data = value;
        t->left = nullptr;
        t->right = nullptr;
        *pNode = t;
        return true;
    } else {
        elem data = (*pNode)->data;
        if (strcmp(data.fio,value.fio)==0) return false;
        if (strcmp(data.fio,value.fio)>0) {
            return addElement(value, &((*pNode)->left));
        } else {
            return addElement(value, &((*pNode)->right));
        }
    }
}

bool tree::add(elem e) {
    addElement(e, &root);
}

void tree::traverse() {
    traverseTree(root);
}

void tree::traverseTree(node *pNode) {
    if (pNode != NULL) {
        traverseTree(pNode->left);
        std::cout << pNode->data.id << " | "
             << pNode->data.fio << " | "
             << pNode->data.mark << " | " <<"\n";
        traverseTree(pNode->right);
    }
}

void tree::traverseTree(node *pNode, int limit) {
    if (pNode != NULL) {
        traverseTree(pNode->left, limit);
        if (pNode->data.mark<limit) {
            std::cout << pNode->data.id << " | "
                      << pNode->data.fio << " | "
                      << pNode->data.mark << " | " << "\n";
        }
        traverseTree(pNode->right, limit);
    }
}

void tree::printUnder(int limit) {
    traverseTree(root, limit);
}
