#include <iostream>
using namespace std;

struct A {
    ~A() { cout << "Destroyed\n"; }
};

int main() {
    A a;
}
