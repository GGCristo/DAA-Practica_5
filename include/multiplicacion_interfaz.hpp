#pragma once
#include <iostream>
#include <vector>
class Polinomio;
// #include "monomio.hpp"
class MultiplicacionInterfaz {
 public:
  virtual ~MultiplicacionInterfaz(){};
  virtual Polinomio multiplicacion(const Polinomio&, const Polinomio&) = 0;
};