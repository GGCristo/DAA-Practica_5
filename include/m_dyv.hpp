#pragma once

#include "m_clasico.hpp"
#include "multiplicacion_interfaz.hpp"
#include "polinomio.hpp"

typedef std::vector<Monomio> polinomio_t;

class MDyV : public MultiplicacionInterfaz {
 public:
  MDyV();
  ~MDyV(){};
  Polinomio multiplicacion(const Polinomio&, const Polinomio&) override;

 private:
  std::shared_ptr<MClasico> multiplicarBase;
};

Polinomio sumaExponente(const Polinomio&, int);