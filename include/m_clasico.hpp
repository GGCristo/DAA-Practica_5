#pragma once
#include "multiplicacion_interfaz.hpp"
#include "polinomio.hpp"

typedef std::vector<Monomio> monomio_t;

class MClasico : public MultiplicacionInterfaz {
 public:
  MClasico(){};
  ~MClasico(){};
  monomio_t multiplicacion(const monomio_t&, const monomio_t&) override;
};