#include "s21_containers.h"
#include "s21_list.h"

int main() {
  //
  s21::list<int> l = {7, 3, 5, 1};
  auto x = l.begin();
  ++x;
  // std::cout << "l = { ";
  // for (int n : l) {
  //   std::cout << n << ", ";
  // }
  // std::cout << "};\n";
  //
  l.erase(x);
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
