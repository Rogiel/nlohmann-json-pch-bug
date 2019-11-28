#include <iostream>
#include <nlohmann/json.hpp>

int main() {
  nlohmann::json json = {{
    "Hello", "World"
  }};
  std::cout << json << std::endl;
  return 0;
}
