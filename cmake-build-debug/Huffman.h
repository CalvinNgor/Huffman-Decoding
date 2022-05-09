//*
// Created by calvin on 06/05/2022.
//

#ifndef HUFFMAN_DECOMP_HUFFMAN_H
#define HUFFMAN_DECOMP_HUFFMAN_H
#include <iostream>
#include <string>

using namespace std;

class Huffman
{
private:
    int alphaSize;
    string lettre;
    int freq;

public:
    Huffman();
    Huffman(int a);
    Huffman(int a, string l);
    Huffman(int a, string l, int f);

    int getAlphaSize();
    void getAlpha();

    friend istream& operator >> (istream& flux, Huffman& H);
    friend ostream& operator << (ostream&, Huffman& H);
};






#endif //HUFFMAN_DECOMP_HUFFMAN_H
