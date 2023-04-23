//
// Created by yevge on 11.05.2017.
//

#include <cstring>
#include <iostream>
#include "tree.h"

using namespace std;

bool tree::add(Person e) {
    return addElement(e, &root);
}

bool tree::addElement(Person value, Node **pNode) {
    if (*pNode == nullptr) {
        Node *t = new Node;
        t->data = value;
        t->left = nullptr;
        t->right = nullptr;
        *pNode = t;
        return true;
    } else {
        Person data = (*pNode)->data;
        if (data.fio == value.fio) return false;
        if (data.fio > value.fio) {
            return addElement(value, &((*pNode)->left));
        } else {
            return addElement(value, &((*pNode)->right));
        }
    }
}

void tree::traverse() {
    traverseTree(root);
}

void tree::traverseTree(Node *pNode) {
    if (pNode != nullptr) {
        traverseTree(pNode->left);
        std::cout << pNode->data.id << " | "
             << pNode->data.fio << " | "
             << pNode->data.mark << " | " <<"\n";
        traverseTree(pNode->right);
    }
}

void tree::traverseTree(Node *pNode, int limit) {
    if (pNode != nullptr) {
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

Person* tree::find(string fio) {
    return find(root, fio);
}

Person* tree::find(Node *pNode, string fio) {
    if (pNode == nullptr) return nullptr;
    Person tmp = pNode->data;
    if (tmp.fio == fio) {
        Person * res = new Person {tmp.id, tmp.fio, tmp.mark };
        return res;
    }
    if (tmp.fio > fio) {
        return find(pNode->left, fio);
    } else {
        return find(pNode->right, fio);
    }
}

void tree::removeElement(string fio) {
    removeElement(fio, &root);
}

void tree::removeElement(string fio, Node **pNode) {
    if (*pNode == nullptr); else {
        if (fio < (*pNode)-> data.fio)
            removeElement(fio, &((*pNode)->left));
        else {
            if (fio > (*pNode)->data.fio)
                removeElement(fio, &((*pNode)->right));
            else {
                Node *q = *pNode;
                if (q->right == nullptr) *pNode = q->left;
                else if (q->left == nullptr) *pNode = q->right; else {
                    removeEl(&(q->left), &q);
                }
                delete q;
            }
        }
    }
}

void tree::removeEl(Node **pNode, Node **q) {
    if ((*pNode)->right != nullptr) removeEl(&(*pNode)->right, q);
    else {
        (*q)->data.fio = (*pNode)->data.fio;
        *q = *pNode;
        *pNode = (*pNode)->left;
    }
}

