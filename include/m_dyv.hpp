#pragma once

#include "multiplicacion_interfaz.hpp"
#include "polinomio.hpp"

typedef std::vector<Monomio> polinomio_t;

class MDyV : public MultiplicacionInterfaz {
 public:
  MDyV(){};
  ~MDyV(){};
  Polinomio multiplicacion(const Polinomio&, const Polinomio&) override;
};