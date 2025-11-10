#include "BSTree.h"
#include "Node.h"
#include <iostream>
#include <cmath>

using namespace std;

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    if (root) {
        delete root;
    }
}

void BSTree::insert(const string &newString) {
    insert(root, newString);
}

void BSTree::insert(Node *&nodePtr, const string &newString) {
    if (nodePtr == nullptr) {
        nodePtr = new Node(newString);
    }
    else if (newString < nodePtr->str) {
        insert(nodePtr->left, newString);
    }
    else if (newString > nodePtr->str) {
        insert(nodePtr->right, newString);
    }
    else {
        nodePtr->count++;
    }
}

bool BSTree::search(const string &key) const {
    return search(root, key);
}

bool BSTree::search(Node *nodePtr, const string &key) const {
    if (nodePtr == nullptr) {
        return false;
    }
    else if (key < nodePtr->str) {
        return search(nodePtr->left, key);
    }
    else if (key > nodePtr->str) {
        return search(nodePtr->right, key);
    }
    else {
        return true;
    }
}

string BSTree::largest() const {
    Node *curr = root;
    if (curr == nullptr) {
        return "";
    }
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    return curr->str;
}

string BSTree::smallest() const {
    Node *curr = root;
    if (curr == nullptr) {
        return "";
    }
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr->str;
}

int BSTree::height(const string &key) const {
    return height(root, key);
}

int BSTree::height(Node *nodePtr, const string &key) const {
    if (nodePtr == nullptr) {
        return -1;
    }
    else if (key < nodePtr->str) {
        return height(nodePtr->left, key);
    }
    else if (key > nodePtr->str) {
        return height(nodePtr->right, key);
    }
    else {
        return height(nodePtr);
    }
}

int BSTree::height(Node *nodePtr) const {
    if (nodePtr == nullptr) {
        return -1;
    }
    int leftHeight = height(nodePtr->left);
    int rightHeight = height(nodePtr->right);
    return max(leftHeight, rightHeight) + 1;
}

void BSTree::remove(const string &key) {
    remove(root, key);
}

void BSTree::remove(Node *&nodePtr, const string &key) {
    if (nodePtr == nullptr) {
        return;
    }
    if (key < nodePtr->str) {
        remove(nodePtr->left, key);
    }
    else if (key > nodePtr->str) {
        remove(nodePtr->right, key);
    }
    else {
        if (nodePtr->count > 1) {
            nodePtr->count--;
        }
        else if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
            delete nodePtr;
            nodePtr = nullptr;
        }
        else if (nodePtr->left != nullptr) {
            Node *pred = nodePtr->left;
            while (pred->right != nullptr) {
                pred = pred->right;
            }
            nodePtr->str = pred->str;
            nodePtr->count = pred->count;
            pred->count = 1;
            remove(nodePtr->left, pred->str);
        }
        else {
            Node *succ = nodePtr->right;
            while (succ->left != nullptr) {
                succ = succ->left;
            }
            nodePtr->str = succ->str;
            nodePtr->count = succ->count;
            succ->count = 1;
            remove(nodePtr->right, succ->str);
        }
    }
}


void BSTree::preOrder() const {
    preOrder(root);
    cout << endl;
}

void BSTree::preOrder(Node *nodePtr) const {
    if (nodePtr != nullptr) {
        cout << nodePtr->str << "(" << nodePtr->count << "), ";
        preOrder(nodePtr->left);
        preOrder(nodePtr->right);
    }
}

void BSTree::inOrder() const {
    inOrder(root);
    cout << endl;
}

void BSTree::inOrder(Node *nodePtr) const {
    if (nodePtr != nullptr) {
        inOrder(nodePtr->left);
        cout << nodePtr->str << "(" << nodePtr->count << "), ";
        inOrder(nodePtr->right);
    }
}

void BSTree::postOrder() const {
    postOrder(root);
    cout << endl;
}

void BSTree::postOrder(Node *nodePtr) const {
    if (nodePtr != nullptr) {
        postOrder(nodePtr->left);
        postOrder(nodePtr->right);
        cout << nodePtr->str << "(" << nodePtr->count << "), ";
    }
}
