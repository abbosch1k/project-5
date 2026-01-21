#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4};
    v.pop_back();
    cout << v.size() << endl;
}
