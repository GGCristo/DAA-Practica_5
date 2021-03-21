#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "monomio.hpp"
#include "multiplicacion_interfaz.hpp"

class Polinomio {
 public:
  // Constructores
  // constructor por defecto
  Polinomio() = delete;
  Polinomio(const Polinomio&);
  // constructor con vector de coeficientes
  explicit Polinomio(
      std::vector<int>,
      std::shared_ptr<MultiplicacionInterfaz> algoritmo = nullptr);
  explicit Polinomio(
      std::vector<Monomio>,
      std::shared_ptr<MultiplicacionInterfaz> algoritmo = nullptr);
  Polinomio multiplicar(const Polinomio&);
  // size_t get_sz() const;
  // void insert(Monomio);
  void setMultiplicar();
  // Monomio& operator[](unsigned int) const;
  std::ostream& show(std::ostream& os = std::cout);

 private:
  int grado_;     // Grado del polinomio
  int terminos_;  // Numero de terminos en el polinomio
  std::vector<Monomio> polinomio_;
  std::shared_ptr<MultiplicacionInterfaz> multiplicar_;
};