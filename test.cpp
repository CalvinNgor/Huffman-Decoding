//
// Created by calvi on 06/05/2022.
//


using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

int main() {
    ifstream f("exemple_freq.txt");
    string text;
    string nbChar;
    getline(f,nbChar);
    while(getline(f,text)) {
        cout << text<< endl;
    }
    f.close();

    //list<int> l;
    //int n = 3;
    //for(int i=0; i<n; i++){
    //    l.push_back(i);
    //    cout << l.size();
}

