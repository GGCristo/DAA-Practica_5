#pragma once
#include "multiplicacion_interfaz.hpp"
class MClasico : public MultiplicacionInterfaz {
 public:
  MClasico(){};
  ~MClasico(){};
  std::vector<int> multiplicacion(const std::vector<int>&,
                                  const std::vector<int>&) override;
};