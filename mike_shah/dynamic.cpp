#include<iostream>

int main(){
  int numberOfStudents = 0;

  std::cout << "How many student in our class?: ";
  std::cin >> numberOfStudents;

  int* studentids = new int[numberOfStudents];

  for(int i = 0; i < numberOfStudents; ++i){
    studentids[i] = i;
  }

 delete[] studentids;
 int* y = new int;
 delete y;
  return 0;
}
