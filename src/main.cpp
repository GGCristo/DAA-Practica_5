#include <iostream>
#include <vector>

#include "../include/m_clasico.hpp"
#include "../include/m_dyv.hpp"
#include "../include/polinomio.hpp"

int main() {
  Polinomio polinomio1(std::vector<int>{-1, 1, 3, 5, 2},
                       std::make_shared<MDyV>());
  Polinomio polinomio2(std::vector<int>{6, 3, 2, 2, 1});
  auto resultado = polinomio1.multiplicar(polinomio2);
  // resultado.show();
  return 0;
}