#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "search_algorithms.h"

using namespace std;

/*
 General Plan:
 tree:
    country->state->city->vector of details
    ex: US->Florida->Gainesville->vector of details

 iterate through each line in ufo_sightings.txt (60633 total)
 iterate through each string, separated by |
 insert into vector of strings

 before next line, insert vector into n-ary tree:
    compare country to countries in tree (maybe have a running set?)
    go down the node if ==
    compare state to states in tree
    go down the node if ==
    compare city to city in tree
    go down the node if ==
    insert a pointer to the vector

*/

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ifstream inputFile("ufo_sightings.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    NaryTree tree;

    string line;
    while (getline(inputFile, line)) {
        vector<string> tokens = split(line, '|');
        tree.insert(tokens);
    }

    inputFile.close();
/*
    while(true) {
        // Get user input for city
        string state, city;
        cout << "Enter the initials of the state: ";
        cin >> state;
        cout << "Enter the city: ";
        cin >> city;

        // Check if the city exists in the tree
        if (tree.checkCity(state, city)) {
            // City exists, so prompt for maximum number of children nodes
            unsigned maxChildren;
            cout << "Enter the maximum number of descriptions you want to see: ";
            cin >> maxChildren;
            // Perform BFS and DFS
            cout << "BFS results for " << city << ":" << endl;
            auto bfsResult = BFS(tree.getNode(state, city));
            printNodes(bfsResult.first);
            cout << "Time taken: " << bfsResult.second << " seconds\n\n";

            cout << "DFS results for " << city << ":" << endl;
            auto dfsResult = DFS(tree.getNode(state, city));
            printNodes(dfsResult.first);
            cout << "Time taken: " << dfsResult.second << " seconds" << endl;
        } else {
            // City does not exist
            cout << "Invalid city: " << city << ". Please enter a valid city." << endl;
        }

        // Ask user if they want to continue or quit
        char choice;
        cout << "Do you want to search for another city? (y/n): ";
        cin >> choice;
        if (tolower(choice) != 'y') {
            break; // exit the loop if user doesn't want to continue
        }
    }
    */

    // Example usage to print details of sightings in a city (based on first line of the file)
    cout << "Printing out default details for Anchorage, Alaska!\n";
    cout << "BFS results for Anchorage:" << endl;
    auto bfsResult = BFS(tree.getNode("AK", "anchorage"));
    printNodes(bfsResult.first);
    cout << "Time taken: " << bfsResult.second << " seconds\n\n";

    cout << "DFS results for Anchorage:" << endl;
    auto dfsResult = DFS(tree.getNode("AK", "anchorage"));
    printNodes(dfsResult.first);
    cout << "Time taken: " << dfsResult.second << " seconds" << endl;

    tree.printCityDetails("US", "AK", "anchorage");

    return 0;
}
