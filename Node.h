//
// Created by calvi on 19/05/2022.
//

#ifndef HUFFMAN_DECOMP_NODE_H
#define HUFFMAN_DECOMP_NODE_H


class Node {
private:
    char letter;
    int freq;
    Node *left, *right;
public:
    Node(char letter, int freq);
    char getLetter() const;
    int getFreq() const;
    Node *getLeft() const;
    Node *getRight() const;
    void setLeft(Node *left);
    void setRight(Node *right);
};


#endif //HUFFMAN_DECOMP_NODE_H
