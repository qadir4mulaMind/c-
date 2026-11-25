#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 12;

    cout << setw(5);          // Set width to 5
    cout << setfill('*');     // Set fill character to '*'
    cout << a << "\n";        // ***12

    cout << setw(5);
    cout << "Hi" << "\n";     // ***Hi

    cout << left;             // Left-align the output
    cout << setw(5);
    cout << a << "\n";        // 12***

    return 0;
}
