#include <iostream>
#include <vector>

#include "../include/polinomio.hpp"

int main() {
  Polinomio polinomio1(std::vector<int>{4, 3, 2, 1});
  Polinomio polinomio2(std::vector<int>{5, 4, 3, 2, 1});
  auto resultado = polinomio1.multiplicar(polinomio2);
  for (size_t i = 0; i < resultado.size(); ++i) {
    std::cout << resultado[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
