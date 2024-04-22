#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "tree_formation.h"
//#include "search_algorithms.h"

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
    ifstream inputFile("../ufo_sightings.txt");
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

    // Example usage to print details of sightings in a city (based on first line of the file)
    tree.printCityDetails("US", "AK", "anchorage");

    return 0;
}
