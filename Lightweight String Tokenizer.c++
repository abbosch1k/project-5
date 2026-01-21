#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s = "one two three";
    stringstream ss(s);
    string word;
    while (ss >> word) cout << word << endl;
}
