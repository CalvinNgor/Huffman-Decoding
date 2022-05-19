//*
// Created by calvin on 06/05/2022.
//

#ifndef HUFFMAN_DECOMP_HUFFMAN_H
#define HUFFMAN_DECOMP_HUFFMAN_H
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Huffman
{
private:
    char letter;
    int freq;
    Huffman *left;
    Huffman *right;
    Huffman *top;

public:
    Huffman();
    Huffman(char l);
    Huffman(char l, int f);

    // Step 1
    char getLetter();
    int getFreq();
    const int getLeft();
    const int getRight();
    int getAlphaSize();
    string getAlpha();
    //friend istream& operator >> (istream& flux, Huffman& H);
    //friend ostream& operator << (ostream&, Huffman& H);

    // Step 2

    void createTree(int size);
    void createStorage(Huffman* n, string s);

    Huffman *getTop() const;

    // Step 3


    // Step 4


};






#endif //HUFFMAN_DECOMP_HUFFMAN_H
