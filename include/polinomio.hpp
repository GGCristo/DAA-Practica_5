#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "multiplicacion_interfaz.hpp"

class Polinomio {
 public:
  // Constructores
  // constructor por defecto
  Polinomio();
  // constructor con vector de coeficientes
  Polinomio(std::vector<int>);
  std::vector<int> multiplicar(const Polinomio&);

 private:
  int grado_;     // Grado del polinomio
  int terminos_;  // Numero de terminos en el polinomio
  std::vector<int> polinomio_;
  std::unique_ptr<MultiplicacionInterfaz> multiplicar_;
};