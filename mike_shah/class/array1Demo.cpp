#include<iostream>
#include "array1.hpp"

int main(){
  Array myArr;
  myArr.setData(0, 100000);
  myArr.setData(1, 77);
  myArr.setData(2, 9999);

  Array myArr2 = myArr;

  myArr.printData();
  myArr2.printData();
  return 0;
}
