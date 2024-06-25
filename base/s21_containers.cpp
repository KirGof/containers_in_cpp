#include "s21_containers.h"

int main() {

  // s21::list<int> l = {7, 3, 5};
  s21::list<int> q;
  // std::cout << "l = { ";
  // for (int n : l) {
  //   std::cout << n << ", ";
  // }
  // std::cout << "};\n";
  // printf("%ld\n", l.max_size());
  s21::iter_for_list<int> x;
  int l = 7;
  q.insert(x, l);

  return 0;
}
