#pragma once
#include "multiplicacion_interfaz.hpp"
#include "polinomio.hpp"

typedef std::vector<Monomio> polinomio_t;

class MClasico : public MultiplicacionInterfaz {
 public:
  MClasico(){};
  ~MClasico(){};
  Polinomio multiplicacion(const Polinomio&, const Polinomio&) override;
};