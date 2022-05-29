//
// Created by calvin on 19/05/2022.
//

#include "Node.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

map<char, int> frequencies;

map<char, string> code;


struct compare
{
    bool operator()(Node* l, Node* r)
    {
       // cout << l->getFreq() << l->getLetter() << ' ' << r->getFreq() << endl;
        return (l->getFreq() > r->getFreq());
    }
};

void printCode(Node* root, string str)
{
    if (!root)
        return;
    if (root->getLetter() != '$')
        cout << root->getLetter() << ": " << str << "\n";
    printCode(root->getLeft(), str + "0");
    printCode(root->getRight(), str + "1");
}

void storeCode(Node* root, string str)
{
    //cout << "STR : " << str << endl;
    if (root==NULL)
        return;
    if (root->getLetter() != '$')
        code[root->getLetter()]=str;
    //cout << "ROOT : " << root->getLetter()<< ' ' << root->getLetter() << ' ' << root->getFreq() << ' ' << root->getRight() << ' ' << root->getLeft() << ' ' << root<< endl;
    storeCode(root->getLeft(), str + "0");
    storeCode(root->getRight(), str + "1");
}

priority_queue<Node*, vector<Node*>, compare> pq;

void Huffman()
{
    Node *left = NULL;
    Node *right = NULL;
    Node *temp = NULL;
    auto it=frequencies.begin();

    while(it != frequencies.end())
    {
        Node *node = new Node(it->first,it->second);
        pq.push(node);
        it++;
    }

    while (pq.size() != 1)
    {

        //cout << "TMP :" << tmp->getLetter() << ' ' << tmp->getFreq() << endl;
        left = pq.top();
        //cout << "LEFT : " << left->getLetter() << ' ' << left->getFreq() << endl;
        pq.pop();
        //cout << "APRES POP :" << pq.top()->getLetter() << endl;
        right = pq.top();
        pq.pop();
        //cout << "RIGHT : " << right->getLetter() << ' ' << right->getFreq() << endl;
        temp = new Node('$', left->getFreq() + right->getFreq());
        temp->setLeft(left);
        temp->setRight(right);
        //cout << "TEMP : " << temp->getLetter()<< ' ' << temp->getLetter() << ' ' << temp->getFreq() << ' ' << temp->getRight() << ' ' << temp->getLeft() << ' ' << temp << endl;

        //cout << "LEFT :" << temp->getLeft() << endl;
        //cout << "RIGHT :" << temp->getRight() << endl;
        pq.push(temp);
    }
    //cout << "PQ :" << pq.size() << endl;
    storeCode(pq.top(), "");

}


string decode(Node* root, const string& str)
{
    string out;

    Node* curr = root;
    for (char i : str){
        if (i == '0'){
            curr = curr->getLeft();
        }else{
            curr = curr->getRight();
        }
        if (!curr->getLeft() && !curr->getRight()){
            out += curr->getLetter();
            curr = root;
        }
    }
    return out+'\0';
}

int main() {

    ifstream MyReadFile("exemple_freq.txt");
    string str;
    string smg;
    int index = 0;
    char letter = '\0';
    int frequency = 0;
    getline(MyReadFile, str);
    string truc = "bonjour!!";

    while (getline(MyReadFile, str)) {
        index = str.find(' ');
        letter = str.substr(0, index)[0];
        frequency = stoi(str.substr(index));
        frequencies[letter] = frequency;
        //cout << "STR :" << str << endl;
    }


    MyReadFile.close();
    string s1, s2;
    Huffman();
    //cout << "Character With there Huffman codes:" << endl;
    auto it = code.begin();
    //cout << "CODE.SIZE : " << code.size() << endl;

    while (it != code.end()) {
        //cout << it->first << " " << it->second << endl;
        it++;
    }

    for (char &i: smg) {
        s1 = s1 + code[i];
        //cout << "S1 : " << s1 << endl;
        //cout << "CODE :" << code[i] << endl;
    }

    cout << "Encoded Huffman:" << s1 << endl;

    s2 = decode(pq.top(), s1);
    cout << "Decoded Huffman:" << s2 << endl;
    return 0;
}