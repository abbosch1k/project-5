#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[3] = {4, 9, 1};
    cout << *max_element(a, a+3) << endl;
}
