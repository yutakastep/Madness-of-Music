//
// Created by yutak on 4/19/2024.
//
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Node creation
//class Node
//{
//public:
//    int val;
//
//    // Since n children are possible for a root.
//    // A list created to store all the children.
//    vector<Node *> child;
//
//    // Constructor
//    Node(int data) : val(data) {}
//};
//
//void insert (Node* root, int parent, Node* node) {
//    if (!root) {
//        root = node;
//    } else {
//        if (root->val == parent) {
//            root->child.push_back(node);
//        } else {
//            // Recursive approach to
//            // insert the child
//            int l = root->child.size();
//
//            for(int i = 0; i < l; i++) {
//                if (root->child[i]->val == parent) {
//                    insert(root->child[i], parent, node);
//                } else {
//                    insert(root->child[i], parent, node);
//                }
//            }
//        }
//    }
//}
//

#include <iostream>
#include <vector>

class TreeNode {
public:
    int data;
    std::vector<TreeNode*> children;

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