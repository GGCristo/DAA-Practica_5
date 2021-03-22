#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "monomio.hpp"
#include "multiplicacion_interfaz.hpp"

typedef std::vector<Monomio> polinomio_t;

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

  Polinomio getDerecha() const;
  Polinomio getIzquierda() const;
  size_t get_sz() const;
  void setMultiplicar();
  Polinomio operator+(const Polinomio&) const;
  Polinomio operator-(const Polinomio&) const;
  const Monomio& operator[](unsigned int) const;
  const polinomio_t& getPolinomio_t() const;
  Monomio& operator[](unsigned int);
  std::ostream& show(std::ostream& os = std::cout);

 private:
  int grado_;     // Grado del polinomio
  int terminos_;  // Numero de terminos en el polinomio
  std::vector<Monomio> polinomio_;
  std::shared_ptr<MultiplicacionInterfaz> multiplicar_;
};