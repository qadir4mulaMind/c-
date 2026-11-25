#include <iostream>
#include "array3.hpp"

// ❌ BAD PRACTICE / NOT USEFUL: Pass by Value (Triggers slow Copy Constructor)
void processByValue(Array tempArr) {
  std::cout << "\n--> Inside processByValue function" << std::endl;
  tempArr.setData(0, 99999); // Changes only the copy
  std::cout << "Temp copy status: ";
  tempArr.printData();
  std::cout << "--> Leaving processByValue function (Copy gets destroyed)" << std::endl;
}

// 🟢 GOOD PRACTICE / EFFICIENT: Pass by Const Reference (0ms Overhead, No Copy)
void processByReference(const Array& sharedArr) {
  std::cout << "\n--> Inside processByReference function" << std::endl;
  std::cout << "Shared array status: ";
  // sharedArr.printData() works directly on main's object safely
  // (Cannot modify data here due to const constraint)
  const_cast<Array&>(sharedArr).printData(); 
  std::cout << "--> Leaving processByReference function" << std::endl;
}

int main() {
  std::cout << "--- Creating myArr ---" << std::endl;
  Array myArr; // Triggers Default Constructor
  myArr.setData(0, 100);
  myArr.setData(1, 200);

  std::cout << "\n--- DEMO 1: Passing Array By Value ---" << std::endl;
  processByValue(myArr); // Watch the console logs print out the deep copy setup!

  std::cout << "\n--- DEMO 2: Passing Array By Reference ---" << std::endl;
  processByReference(myArr); // Fast execution, no copy logs will appear

  std::cout << "\n--- Final sanity check inside main ---" << std::endl;
  std::cout << "Original myArr status: ";
  myArr.printData();

  return 0;
}
