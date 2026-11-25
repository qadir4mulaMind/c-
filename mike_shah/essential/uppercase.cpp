#include <iostream>
#include<iomanip>
using namespace std;

int main() {
    double x = 12345.678;
    cout << scientific << x << endl;
    cout << uppercase << x << endl;
    cout << nouppercase << x << endl;
    return 0;
}
