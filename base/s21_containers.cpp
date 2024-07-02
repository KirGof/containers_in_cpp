#include "s21_containers.h"

int main() {

  s21::list<int> l = {1, 2, 3, 4, 5, 6};
  s21::list<int> m = {1, 2, 3};

  l.merge(m);
  std::cout << "l = { ";
  for (int n : l) {
    std::cout << n << ", ";
  }
  std::cout << "};\n";

  // s21::Vector<int> x = {1, 2, 3};
  // x.show();
  return 0;
}
