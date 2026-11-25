#include <iostream>

class UDT; // Forward declaration so PrivateSecurityInfo knows UDT exists

class PrivateSecurityInfo {
private:
    int passcode;

    // Grant UDT permission to access PrivateSecurityInfo's private members
    friend class UDT; 
};

class UDT {
public:
    // Fixed constructor name to match the class 'UDT'
    UDT() : m_var(0) {
        m_info.passcode = 7; // Now legal because UDT is a friend of PrivateSecurityInfo
    }

private:
    int m_var;
    PrivateSecurityInfo m_info;

    // Friend function declaration
    friend void printVarUDT(UDT u);
};

// Friend function definition (removed the 'friend' keyword here)
void printVarUDT(UDT u) {
    // Fixed the typo at the end from std::cout to std::endl
    std::cout << "m_var: " << u.m_var << std::endl; 
}

int main() {
    UDT u1;
    printVarUDT(u1);
    return 0;
}

