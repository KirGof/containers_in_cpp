#include "s21_containers.h"
#include <list>

int main() {

  s21::list<int> l = {7, 3, 5};
  std::cout << "l = { ";
  for (int n : l) {
    std::cout << n << ", ";
  }
  std::cout << "};\n";

  auto iter = l.end();
  --iter;
  // s21::iter_for_list iter = l.end();
  // s21::iter_for_list iter = l.begin();
  // ++iter;
  // iter++;
  // ++iter;
  // printf("%d\n", *(iter));

  // iter--;
  // iter--;
  // iter++;
  // l.insert(iter, 10);
  //
  // std::cout << "l = { ";
  // for (int n : l) {
  //   std::cout << n << ", ";
  // }
  // std::cout << "};\n";
  return 0;
}
