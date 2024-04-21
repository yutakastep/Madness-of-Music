//
// Created by yutak on 4/19/2024.
//
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Node creation
class Node
{
public:
    int val;

    // Since n children are possible for a root.
    // A list created to store all the children.
    vector<Node *> child;

    // Constructor
    Node(int data) : val(data) {}
};

void insert (Node* root, int parent, Node* node) {
    if (!root) {
        root = node;
    } else {
        if (root->val == parent) {
            root->child.push_back(node);
        } else {
            // Recursive approach to
            // insert the child
            int l = root->child.size();

            for(int i = 0; i < l; i++) {
                if (root->child[i]->val == parent) {
                    insert(root->child[i], parent, node);
                } else {
                    insert(root->child[i], parent, node);
                }
            }
        }
    }
}