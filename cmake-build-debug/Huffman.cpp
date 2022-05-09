//
// Created by calvin on 06/05/2022.
//

using namespace std;

#include <string>
#include <fstream>
#include <iostream>
#include "Huffman.h"

Huffman::Huffman()
{
    alphaSize = 0.;
    lettre = "";
    freq = 0.;
}

Huffman::Huffman(int a)
{
    alphaSize = a;
    lettre = "";
    freq = 0.;
}

Huffman::Huffman(int a, string l)
{
    alphaSize = a;
    lettre = l;
    freq = 0.;
}

Huffman::Huffman(int a, string l, int f)
{
    alphaSize = a;
    lettre = l;
    freq = f;
}

istream& operator >> (istream& flux, Huffman &H)
{
    flux >>
}


int Huffman::getAlphaSize()
// read first line file return alpha size
{
    ifstream f;
    f.open("exemple_freq.txt", ios::out);
    string text;
    while(getline(f,text)) {
        cout << text;
    }
    int size = stoi(text);
    f.close();

    return size;

}

