//
// Created by yutak on 4/19/2024.
//
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class TreeNode {
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int val) : data(val) {}

    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }
};

class NaryTree {
private:
    TreeNode* root;

public:
    NaryTree() : root(nullptr) {}

    ~NaryTree() {
        delete root;
    }

    void insert(int parentData, int childData) {
        if (!root) {
            root = new TreeNode(parentData);
        }
        TreeNode* parent = findNode(root, parentData);
        if (parent) {
            parent->children.push_back(new TreeNode(childData));
        }
    }

    TreeNode* findNode(TreeNode* node, int data) {
        if (!node) return nullptr;
        if (node->data == data) return node;

        for (TreeNode* child : node->children) {
            TreeNode* found = findNode(child, data);
            if (found) return found;
        }
        return nullptr;
    }
};
