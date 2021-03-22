#include <iostream>
#include <vector>

#include "../include/m_clasico.hpp"
#include "../include/m_dyv.hpp"
#include "../include/polinomio.hpp"

int main() {
  /*
  Polinomio polinomio1(std::vector<int>{2, 3}, std::make_shared<MDyV>());
  Polinomio polinomio2(std::vector<int>{4, 5});
  polinomio1.multiplicar(polinomio2).show();*/

  Polinomio polinomio1(std::vector<int>{-1, 1, 3, 5, 2},
                       std::make_shared<MDyV>());
  Polinomio polinomio2(std::vector<int>{6, 3, 2, 2, 1});
  polinomio1.multiplicar(polinomio2).show();
  return 0;
}