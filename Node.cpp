//
// Created by calvi on 19/05/2022.
//
#include <iostream>
#include "Node.h"
#include "stddef.h"

void Node::setLeft(Node *left) {
    Node::left = left;
}

void Node::setRight(Node *right) {
    Node::right = right;
}

Node::Node(char _letter, int _freq)
{
    letter = _letter;
    freq = _freq;
    left = nullptr;
    right = nullptr;
}

char Node::getLetter() const {
    return letter;
}
int Node::getFreq() const {
    return freq;
}
Node *Node::getLeft() const {
    return left;
}
Node *Node::getRight() const {
    return right;
}
