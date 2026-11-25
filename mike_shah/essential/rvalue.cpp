#include<iostream>
using namespace std;

void editAndPrint(string &&s) { // 's' is an R-value reference
    s = "Hi, " + s; // Modifies the temporary string
    cout << s << "\n";
}

int main() {
    editAndPrint("Welcome to GeeksforGeeks"); 
    return 0;
}
