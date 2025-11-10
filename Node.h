#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Node {

public:
    string str;
    int count;
    Node *left;
    Node *right;
   
    Node(const string &s) : str(s), count(1), left(nullptr), right(nullptr) {}
    ~Node();
   
    Node(const Node &other) = delete;
    const Node& operator=(const Node &other);
};

#endif
