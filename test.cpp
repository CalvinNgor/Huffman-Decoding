//
// Created by calvi on 06/05/2022.
//


using namespace std;

#include <iostream>
#include <fstream>
#include <string>

int main() {
    ifstream f("exemple_freq.txt");
    string text;
    while(getline(f,text)) {
        cout << text;
    }
    f.close();
}