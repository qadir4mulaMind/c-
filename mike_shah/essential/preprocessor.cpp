#include <iostream>
using namespace std;
      
void func1();
void func2();
 
#pragma startup func1
#pragma exit func2
 
void func1()
{
    cout << "Inside func1()\n";
}
 
void func2()
{
    cout << "Inside func2()\n";
}
 
int main()
{
    void func1();
    void func2();
    cout << "Inside main()\n";
 
    return 0;
}

// This code is contributed by shivanisinghss2110
