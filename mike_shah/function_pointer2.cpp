#include<iostream>
#include<functional>

typedef int (*PFnIntegerOperation) (int, int);

int add(int a, int b){
  return a + b;
}

int multiply(int a, int b){
  return a * b;
}

int main(){
  
  std::function<int(int, int)> op;

  std::cout << "1 for add & 2 for mutiply: ";

  int x, n1, n2;

  std::cin >> x;

   if(x > 2) {
     std::cout << "Invalid choice: " << std::endl;
     exit(0);
    }
 

  std::cout << "Enter first number: ";
  std::cin >> n1;

  std::cout << "Enter Second number: ";
  std::cin >> n2;

  if(x == 1){
    op = add;
  } else if(x == 2){
    op = multiply;
  } 
  
  std::cout << op(n1, n2) << std::endl;
  return 0;
}
