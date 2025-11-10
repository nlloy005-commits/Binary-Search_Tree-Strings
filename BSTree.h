#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"

using namespace std;

class BSTree {

private:
     Node *root;

    void insert(Node* &nodePtr, const string &newString);
    bool search(Node *nodePtr, const string &key) const;
    void remove(Node* &nodePtr, const string &key);
    int height(Node *nodePtr) const;
    int height(Node *nodePtr, const string &key) const;

    void preOrder(Node *nodePtr) const;
    void inOrder(Node *nodePtr) const;
    void postOrder(Node *nodePtr) const;

public:

    BSTree();
    ~BSTree();

    void insert(const string &newString);
    bool search(const string &key) const;
    void remove(const string &key);
    int height(const string &key) const;

    string largest() const;
    string smallest() const;

    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
};

#endif
