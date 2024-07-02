#include "s21_containers.h"

int main() {

  s21::list<int> l;
  s21::list<int> m = {1, 2, 3};

  // std::cout << "l = { ";
  // for (int n : l) {
  //   std::cout << n << ", ";
  // }
  // std::cout << "};\n";
  //
  // std::cout << "m = { ";
  // for (int n : m) {
  //   std::cout << n << ", ";
  // }
  // std::cout << "};\n";

  l.merge(m);
  std::cout << "l = { ";
  for (int n : l) {
    std::cout << n << ", ";
  }
  std::cout << "};\n";

  // for (int i = 0; i < l.size(); i++) {
  //   if (x == nullptr) {
  //     printf("NULL\n");
  //   } else {
  //     printf("%d\n", *x);
  //   }
  //   ++x;
  // }
  // return 0;
}
