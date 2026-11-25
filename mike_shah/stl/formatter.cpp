#include <iostream>
#include <format> 

struct Point {
  float x, y;
};

template <>
struct std::formatter<Point> {
  bool special = false;

  constexpr auto parse(auto& ctx) {
    auto it = ctx.begin();
    if (it == ctx.end()) {
      return it;
    }
    
    if (*it == 's') {
      special = true;
      it++; 
    }
    
    if (it != ctx.end() && *it != '}') {
      throw std::format_error("invalid args!!");
    }
    return it;
  }

  auto format(const Point& p, auto& ctx) const {
    if (special) {
      return std::format_to(ctx.out(), "({}, {})", p.x, p.y);
    } else {
      return std::format_to(ctx.out(), "{},{}", p.x, p.y);
    } 
  }
};

int main() {
  Point p;
  p.x = 3.7f;
  p.y = 7.7f;

  std::cout << "Default format: " << std::format("{}", p) << std::endl;

  std::cout << "Special format: " << std::format("{:s}", p) << std::endl;

  return 0;
}

