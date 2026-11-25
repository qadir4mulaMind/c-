#include <iostream>
#include <print> // 👈 Required for std::print and std::println (C++23)
#include <vector>
#include <string>

// Reusable custom structure matching your layout style
struct Bot {
  std::string name;
  int version;
};

// Test 0: Basic formatting difference between print and println
void test0() {
  // std::print does NOT append a newline character automatically
  std::print("Hello ");
  std::print("World"); 
  
  // std::println automatically appends a newline (\n) at the end
  std::println(); 
  std::println("--------------------------------");

  int runtime_speed = 95;
  std::string model = "LLaMA-3";
  
  // Clean positional formatting without cascading << operator
  std::println("Model {} is running at {}% efficiency.", model, runtime_speed);
}

// Test 1: Advanced formatting placeholders and containers
void test1() {
  Bot primary_bot{"AlphaBot", 4};

  // Easily injecting custom members inside specific output templates
  std::println("Active Bot: {} [v{}]", primary_bot.name, primary_bot.version);

  std::vector<int> benchmarks{92, 87, 99, 104};
  
  // C++23 allows direct formatting/printing of standard ranges/containers!
  std::println("Benchmark Scores: {}", benchmarks); 
}

int main() {
  std::println("=== Running test0 ===");
  test0();
  std::println("=== Running test1 ===");
  test1();
  return 0;
}
