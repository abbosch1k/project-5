#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream f("data.txt");
    int lines = 0;
    string s;
    while (getline(f, s)) lines++;
    cout << lines << endl;
}
