#include <iostream>
#include <vector>

#include "../include/m_clasico.hpp"
#include "../include/polinomio.hpp"

int main() {
  Polinomio polinomio1(std::vector<int>{5, 2, 1, 1},
                       std::make_shared<MClasico>());
  Polinomio polinomio2(std::vector<int>{2, 0, 3, 1, 2});
  auto resultado = polinomio1.multiplicar(polinomio2);
  return 0;
}