// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <iostream>
#include <vector>

#include "../include/m_clasico.hpp"
#include "../include/m_dyv.hpp"
#include "../include/polinomio.hpp"
#include "../include/times.hpp"

int main() {
  Polinomio polinomio1(std::vector<int>{-1, 1, 3, 5, 2},
                       std::make_shared<MClasico>());
  Polinomio polinomio2(std::vector<int>{6, 3, 2, 2, 2});
  polinomio1.multiplicar(polinomio2).show();

  Polinomio polinomio3(std::vector<int>{-1, 1, 3, 5, 2},
                       std::make_shared<MDyV>());
  Polinomio polinomio4(std::vector<int>{6, 3, 2, 2, 2});
  polinomio3.multiplicar(polinomio4).show();
  // times();
  return 0;
}
