#include <iostream>
#include<iomanip>
using namespace std;

int main() {
    double x = 123.456789;
    cout << setprecision(4) << x << endl;
    cout << setprecision(7) << x << endl;
    return 0;
}
