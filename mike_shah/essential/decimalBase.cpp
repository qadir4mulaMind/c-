#include <iostream>
using namespace std;

int main()
{
    int a = 26, b = 20;

    cout << a << " " << b << "\n";  // 26 20

    cout << hex;
    cout << a << " " << b << "\n";  // 1a 14

    cout << oct;
    cout << a << " " << b << "\n";  // 32 24

    cout << dec;
    cout << a << " " << b << "\n";  // 26 20

    return 0;
}
