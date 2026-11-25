#include<iostream>
#include<string>
#include<format>

void test0(){
  int x{1};
  std::printf("x is : %d\n", x);
}

void test1(){
  int x{2};
  std::cout << x << std::endl;
}

void test2(){
  std::cout << std::format("Hello everyone")  << std::endl;
  constexpr const char* fmt = "Hello EveryOne {}";
  std::cout << std::format(fmt, "Hope will fine") << std::endl;
}

void test3(){
  int month = 6;
  int year = 2026;
  std::cout << std::format("It is now {}-{}", month, year) << std::endl;
  std::cout << std::format("It is now {0}-{1}", month, year) << std::endl;
  std::cout << std::format("It is now {1}-{0}", month, year) << std::endl;

  int a = 8;
  auto s0 = std::format("{:5}", a);
  auto s1 = std::format("{:6}", a);
  auto s2 = std::format("{:*<6}", a);
  auto s3 = std::format("{:*>6}", a);
  auto s4 = std::format("{:=^6}", a);



  std::cout << s0 << std::endl;
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  std::cout << s3 << std::endl;
  std::cout << s4 << std::endl;
  auto s5 = std::format("default: {0}, {0:=^6}", a);
  std::cout << s5 << std::endl;
  float f = 3.1415269;
  auto s6 = std::format("default: {0}, {0:10.5f}", f);
  std::cout << s6 << std::endl;
  int binary = 7;
  auto s7 = std::format("default: {0}, {0:b}", binary); 
  auto s8 = std::format("default: {0}, {0:0>8B}", binary);
  auto s9 = std::format("default: {0}, {0:0>8X}", binary); 
  std::cout << s7 << std::endl;
  std::cout << s8 << std::endl;
  std::cout << s9 << std::endl;
  constexpr const char* fmtAdr = "value: {0}, address :{1:p}";
  std::cout << std::format(fmtAdr, binary, static_cast<void*>(&binary) << std::endl;
}

int main(){
  test0();
  test1();
  test2();
  test3();
  return 0;
}
