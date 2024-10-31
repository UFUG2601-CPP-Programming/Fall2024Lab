//
// Created by Mingyu on 24-10-29.
//
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// ifstream template
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    string a,b;
    in>>a>>b;
    out<<a+b<<endl;
    return 0;
}