#include "../include/m_dyv.hpp"

MDyV::MDyV() : multiplicarBase(std::make_shared<MClasico>()) {}

Polinomio MDyV::multiplicacion(const Polinomio& polinomio1,
                               const Polinomio& polinomio2) {
  if (polinomio1.get_sz() == 1 || polinomio2.get_sz() == 1) {
    return multiplicarBase->multiplicacion(polinomio1, polinomio2);
  } else {
    Polinomio A0 = polinomio1.getDerecha();
    Polinomio A1 = polinomio1.getIzquierda();
    Polinomio B0 = polinomio2.getDerecha();
    Polinomio B1 = polinomio2.getIzquierda();
    auto izquierda = multiplicacion(A0, B0);
    auto medio = multiplicacion(A0, B1) + multiplicacion(A1, B0);
    auto derecha = multiplicacion(A1, B1);
    return izquierda + medio + derecha;
  }
}

/*
Polinomio sumaExponente(const Polinomio& polinomio, int exponente) {
  Polinomio resultado(polinomio);
  for (size_t i = 0; i < polinomio.get_sz(); ++i) {
    resultado[i].setExponente(polinomio[i].getExponente() + exponente);
  }
  return resultado;
} */