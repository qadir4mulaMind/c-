#include <iostream>
#include <numeric>
#include <vector>
#include <functional>
#include <iterator>

// Aapka signature style: Universal reusable auto print lambda
auto print = [](const auto& container) {
  for (const auto& ele : container) {
    std::cout << ele << " ";
  }
  std::cout << std::endl;
};

struct OrderItem {
  int price;
  int quantity;
};

// Test 0: Vector of integers ka elements-square karke sum nikalna
void test0() {
  std::vector v1{1, 2, 3, 4, 5}; // C++17 CTAD style
  std::cout << "v1 elements: ";
  print(v1);

  // transform_reduce: Square each element, then sum them up
  int sum_of_squares = std::transform_reduce(
      v1.begin(), v1.end(), 
      0, 
      std::plus<int>(),          // Reduce Step: Kaise jodhna hai
      [](int x) { return x * x; } // Transform Step: Har element ka square
  );

  std::cout << "Sum of squares: " << sum_of_squares << std::endl;
  std::cout << "--------------------------------" << std::endl;
}

// Test 1: Struct data types (Cart Items) ka total value calculation
void test1() {
  // Vector of custom structures
  std::vector<OrderItem> cart{{100, 2}, {45, 1}, {10, 5}}; // Total: 200 + 45 + 50 = 295

  // transform_reduce: Multiply price * quantity for each object, then sum them up
  int total_cart_value = std::transform_reduce(
      cart.begin(), cart.end(),
      0,
      std::plus<int>(),
      [](const OrderItem& item) { return item.price * item.quantity; }
  );

  std::cout << "Total Cart Bill Value: " << total_cart_value << " INR" << std::endl;
}

int main() {
  test0();
  test1();
  return 0;
}

