#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <vector>

#include "../include/m_clasico.hpp"
#include "../include/m_dyv.hpp"
#include "../include/polinomio.hpp"

TEST_CASE("Clásico") {
  Polinomio polinomio1(std::vector<int>{-1, 1, 3, 5, 2},
                       std::make_shared<MClasico>());
  Polinomio polinomio2(std::vector<int>{6, 3, 2, 2, 2});
  Polinomio resultado(std::vector<int>{-6, 3, 19, 39, 33, 24, 20, 14, 4});
  CHECK(polinomio1.multiplicar(polinomio2) == resultado);
}
TEST_CASE("DyV") {
  Polinomio polinomio1(std::vector<int>{-1, 1, 3, 5, 2},
                       std::make_shared<MDyV>());
  Polinomio polinomio2(std::vector<int>{6, 3, 2, 2, 2});
  Polinomio resultado(std::vector<int>{-6, 3, 19, 39, 33, 24, 20, 14, 4});
  CHECK(polinomio1.multiplicar(polinomio2) == resultado);
}
