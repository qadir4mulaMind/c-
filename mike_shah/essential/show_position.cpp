#include <iostream>
#include<iomanip>
using namespace std;

int main() {
    int a = 10;
    int b = -10;
    cout << a << " " << b << endl;
    cout << showpos << a << " " << b << endl;
    cout << noshowpos << a << " " << b << endl;
    return 0;
}
