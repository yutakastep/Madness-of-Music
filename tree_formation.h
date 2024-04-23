#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

// Node structure for the n-ary tree
struct TreeNode {
    string name;
    unordered_map<string, TreeNode*> children;
    vector<vector<string>*> data; // Vector of pointers to vectors of data
    TreeNode(string n) : name(n) {}
};

class NaryTree {
private:
    TreeNode* root;

    // Function to convert a string to lowercase
    string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    // Function to convert a string to uppercase
    string toUpper(string s) {
        string result = s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return result;
    }

public:
    NaryTree() {
        root = new TreeNode("Global");
    }

    // Insert function to insert data into the n-ary tree
    void insert(const vector<string>& data) {
        TreeNode* current = root;

        // Ensure the structure is as expected: country -> state -> city -> vector of data
        if (data.size() < 3) {
            cerr << "Invalid data format." << endl;
            return;
        }

        // Insert country
        string country = data[2];
        if (current->children.find(country) == current->children.end()) {
            current->children[country] = new TreeNode(country);
        }
        current = current->children[country];

        // Insert state
        string state = data[1];
        if (current->children.find(state) == current->children.end()) {
            current->children[state] = new TreeNode(state);
        }
        current = current->children[state];

        // Insert city
        string city = data[0];
        if (current->children.find(city) == current->children.end()) {
            current->children[city] = new TreeNode(city);
        }
        current = current->children[city];

        // Insert pointer to data vector
        current->data.push_back(new vector<string>(data.begin(), data.end()));
    }

    // Function to print details of sightings in a city
    void printCityDetails(const string& country, const string& state, const string& city) {
        TreeNode* current = root;
        if (current->children.find(country) == current->children.end() ||
            current->children[country]->children.find(state) == current->children[country]->children.end() ||
            current->children[country]->children[state]->children.find(city) == current->children[country]->children[state]->children.end()) {
            cout << "No sightings found for " << city << ", " << state << ", " << country << endl;
            return;
        }
        current = current->children[country]->children[state]->children[city];
        cout << "Sightings in " << city << ", " << state << ", " << country << ":" << endl;
        for (vector<string>* ptr : current->data) {
            for (const string& detail : *ptr) {
                cout << detail << " | ";
            }
            cout << endl;
        }
    }

    // Function to retrieve the node corresponding to a city
    TreeNode* getNode(const string& state, const string& city) {
        string lState = toUpper(state);
        string lCity = toLower(city);
        TreeNode* current = root;
        if (current->children.find(lState) == current->children.end() ||
            current->children[lState]->children.find(lCity) == current->children[lState]->children.end()) {
            return nullptr; // City not found
        }
        return current->children[lState]->children[lCity];
    }

    // Function to check if a city exists (case-insensitive)
    bool checkCity(const string& state, const string& city) {
        string lState = toUpper(state);
        string lCity = toLower(city);
        TreeNode* node = getNode(lState, lCity);
        return node != nullptr;
    }
};
