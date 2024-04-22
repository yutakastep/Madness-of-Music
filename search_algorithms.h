#include <iostream>
#include <iomanip>
#include <chrono>
#include <queue>
#include <stack>
#include "tree_formation.h"

using namespace std;
using namespace std::chrono;

pair<vector<TreeNode*>, double> BFS(TreeNode* root, unsigned maxChildren = 10) {
    auto start = high_resolution_clock::now(); // record the start time
    vector<TreeNode*> children;
    queue<TreeNode*> queue;
    int levelNum = 1;
    if (root == nullptr) return {children, 0}; // returns empty if root is empty
    queue.push(root);

    while (!queue.empty()) {
        int size = queue.size();
        vector<TreeNode*> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = queue.front();
            level.push_back(node); // store the node pointer in the level
            queue.pop();

            for (auto& iter : node->children) {
                TreeNode* child = iter.second; // access the value (TreeNode*) using iterator
                if (child != nullptr) {
                    queue.push(child);
                    if (children.size() < maxChildren) // collect up to maxChildren nodes to print out
                        children.push_back(child);
                }
            }
        }
        levelNum++;
    }
    auto end = high_resolution_clock::now(); // record the end time
    double elapsed = double((end - start).count()); // calculate elapsed time

    return {children, elapsed};
}

void dfsRecursion(TreeNode* node, vector<TreeNode*>& children, unsigned maxChildren) {
    if (node == nullptr) return;

    if (children.size() < maxChildren) children.push_back(node);

    for (auto & iter : node->children) {
        TreeNode* child = iter.second; // access the value (TreeNode*) using iterator
        dfsRecursion(child, children, maxChildren);
    }
}

pair<vector<TreeNode*>, double> DFS(TreeNode* root, unsigned maxChildren = 10) {
    auto start = high_resolution_clock::now(); // record the start time

    vector<TreeNode*> children;
    dfsRecursion(root, children, maxChildren); // recursive DFS function

    auto end = high_resolution_clock::now(); // record the end time
    double elapsed = double((end - start).count()); // calculate elapsed time

    return {children, elapsed};
}

void printNodes(const vector<TreeNode*>& nodes) {
    cout << "Children nodes: ";
    for (const TreeNode* node : nodes) {
        cout << node->name << " ";
    }
    cout << endl;
}
