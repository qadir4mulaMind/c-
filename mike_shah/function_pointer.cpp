   #include<iostream>
   
   int add(int a, int b){
     return a + b;
   }
   
   int multilpy(int a, int b){
     return a * b;
   }
  
  int main(){
    int (*op) (int, int);
  
    std::cout << "Enter 1 for multilpy 2 for addition: ";
  
    int n;
  
    std::cin >> n;
  
    if(n == 1){
      op = add;
    } else if(n== 2){
      op = multilpy;
    } else{
      std::cout << "Invalid choice " << std::endl;
      exit(0);
    }
  
    std::cout << "Operation: " << op(2, 2) << std::endl;
 
   return 0;
}
                 
