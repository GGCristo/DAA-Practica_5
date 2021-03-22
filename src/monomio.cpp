// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "../include/monomio.hpp"

Monomio::Monomio() {
  coeficiente_ = 0;
  exponente_ = 0;
}

Monomio::Monomio(int coef, int exp) {
  coeficiente_ = coef;
  exponente_ = exp;
}

// int Monomio::Evaluar(int x) const {}

int Monomio::getCoeficiente() const { return coeficiente_; }

int Monomio::getExponente() const { return exponente_; }

// void Monomio::setCoeficiente(int c) { coeficiente_ = c; }

void Monomio::setExponente(int c) { exponente_ = c; }

bool Monomio::operator<(const Monomio &monomio2) {
  return exponente_ > monomio2.getExponente();
}
// Operadores de insercion y extraccion
std::ostream &operator<<(std::ostream &nout, const Monomio &s) {
  if (s.getExponente() == 0) {
    nout << s.getCoeficiente();
  } else {
    nout << s.getCoeficiente() << "x^" << s.getExponente();
  }
  return nout;
}
// std::istream &operator>>(const std::istream &sin, Monomio &r) {}

// Suma dos monomios de mismo exponente
Monomio operator+(const Monomio &x, const Monomio &y) {
  assert(x.getExponente() == y.getExponente());
  return Monomio(x.getCoeficiente() + y.getCoeficiente(), y.getExponente());
}

// Resta dos monomios de mismo exponente
Monomio operator-(const Monomio &x, const Monomio &y) {
  assert(x.getExponente() == y.getExponente());
  return Monomio(x.getCoeficiente() - y.getCoeficiente(), y.getExponente());
}
