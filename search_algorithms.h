#include <iostream>
#include <iomanip>
#include <ctime>
#include <queue>

using namespace std;

pair<vector<Node*>, double> BFS(Node* root, unsigned maxChildren = 10) {
    clock_t start = clock(); // record the start time
    vector<Node*> children;
    queue<Node*> queue;
    int levelNum = 1;
    if (root == nullptr) return {children, 0}; // returns empty if root is empty
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            Node* node = queue.front();
            level.push_back(node->val);
            queue.pop();
            for (int j = 0; j < (node->children).size(); j++) {
                if ((node->children)[j] != nullptr) {
                    queue.push((node->children)[j]);
                }
            }
        }
        levelNum++;
    }
    clock_t end = clock(); // record the end time
    double elapsed = double(end - start) / CLOCKS_PER_SEC; // calculate elapsed time
    return {children, elapsed};
}

pair<vector<Node*>, double> DFS(Node* root, unsigned maxChildren = 10) {

}
