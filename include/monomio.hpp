#pragma once

#include <iostream>

class Monomio {
 public:
  Monomio();                   // Constructor por defecto
  Monomio(int coef, int exp);  // Constructor con Coeficiente y Exponente
  int Evaluar(int x) const;    // Evalua un monomio en un punto
  int getCoeficiente() const;  // Devuelve el Exponente
  void setCoeficiente(int c);  // Asigna un valor al Coeficiente
  void setExponente(int e);    // Asigna un valor al Exponente
 private:
  int Coeficiente;
  int Exponente;
};

// Operadores de insercion y extraccion
std::ostream &operator<<(std::ostream &nout, const Monomio &s);
std::istream &operator>>(const std::istream &sin, Monomio &r);

// Suma dos monomios de mismo exponente
Monomio operator+(const Monomio &x, const Monomio &y);