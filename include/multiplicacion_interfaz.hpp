#pragma once
#include <iostream>
#include <vector>

#include "monomio.hpp"
class MultiplicacionInterfaz {
 public:
  virtual ~MultiplicacionInterfaz(){};
  virtual std::vector<Monomio> multiplicacion(const std::vector<Monomio>&,
                                              const std::vector<Monomio>&) = 0;
};