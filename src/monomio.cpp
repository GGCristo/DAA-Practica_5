#include "../include/monomio.hpp"

Monomio::Monomio() {
  coeficiente_ = 0;
  exponente_ = 0;
}

Monomio::Monomio(int coef, int exp) {
  coeficiente_ = coef;
  exponente_ = exp;
}

int Monomio::Evaluar(int x) const {}

int Monomio::getCoeficiente() const { return coeficiente_; }

int Monomio::getExponente() const { return exponente_; }

void Monomio::setCoeficiente(int c) { coeficiente_ = c; }

// Operadores de insercion y extraccion
std::ostream &operator<<(std::ostream &nout, const Monomio &s) {}
std::istream &operator>>(const std::istream &sin, Monomio &r) {}

// Suma dos monomios de mismo exponente
Monomio operator+(const Monomio &x, const Monomio &y) {}