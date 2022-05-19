//
// Created by calvin on 06/05/2022.
//

using namespace std;

#include <string>
#include <fstream>
#include <iostream>
#include "Huffman.h"
#include <list>
#include <map>
#include <vector>
#include <queue>


Huffman::Huffman()
{
    letter = NULL;
    freq = 0.;
}

Huffman::Huffman(char l)
{
    letter = l;
    freq = 0.;
    left = NULL;
    right = NULL;
}

Huffman::Huffman(char l, int f)
{
    letter = l;
    freq = f;
    left = NULL;
    right = NULL;
}

char Huffman::getLetter() {
    return letter;
}

int Huffman::getFreq() {
    return freq;
}


Huffman *Huffman::getTop() const {
    return top;
}

int Huffman::getAlphaSize()
// read first line file return alpha size
{
    ifstream f("exemple_freq.txt");
    string text;
    getline(f,text);
    f.close();
    int t = atoi("text");
    return t;
}

string Huffman:: getAlpha()
// read all lines except the first one.
{
    ifstream f("exemple_freq.txt");
    string text;
    string nbChar;
    getline(f,nbChar);
    while(getline(f,text)) {
        cout << text<< endl;
    }
    f.close();
}

map<char,string> code;
map<char,int> freq;

struct compare
{
    bool operator()(Huffman* l, Huffman* r)
    {
        return (l->getFreq() > r->getFreq());
    }
};

void Huffman::createStorage(Huffman* root, string s)
{
    if (root == NULL)
        return;
    if (root->getLetter()!= '$')
        code[root->getLetter()] = s;
    createStorage((Huffman &&) root->getLeft(), s + "0");
    createStorage((Huffman &&) root->getRight(), s + "1")
}

priority_queue<Huffman*, vector < Huffman *>, compare> pq;

void Huffman::createTree(int size)
{
    for(map<char, int>::iterator i=freq.begin(); i != freq.end();i++)
        pq.push(new Huffman (i->first, i->second));
    while (pq.size() != 1)
    {
        left = pq.getTop();
        pq.pop();
        right = pq.getTop();
        pq.pop();
        top = new Huffman ('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    createStorage(Huffman pq.getTop(), "");
}

