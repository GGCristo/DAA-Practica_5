#pragma once
#include <iostream>
#include <vector>

class MultiplicacionInterfaz {
 public:
  virtual ~MultiplicacionInterfaz(){};
  virtual std::vector<int> multiplicacion(const std::vector<int>&,
                                          const std::vector<int>&) = 0;
};