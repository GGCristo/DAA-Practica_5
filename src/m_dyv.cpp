// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "../include/m_dyv.hpp"

MDyV::MDyV() : multiplicarBase(std::make_shared<MClasico>()) {}

Polinomio MDyV::multiplicacion(const Polinomio& polinomio1,
                               const Polinomio& polinomio2) {
  if (polinomio1.get_sz() == 1 || polinomio2.get_sz() == 1) {
    return multiplicarBase->multiplicacion(polinomio1, polinomio2);
  } else {
    Polinomio AL = polinomio1.getDerecha();
    Polinomio AH = polinomio1.getIzquierda();
    Polinomio BL = polinomio2.getDerecha();
    Polinomio BH = polinomio2.getIzquierda();
    auto izquierda = multiplicacion(AL, BL);
    auto medio = multiplicacion(AL + AH, BL + BH);
    auto derecha = multiplicacion(AH, BH);

    if (polinomio1.get_sz() % 2 == 0) {
      return izquierda +
             sumaExponente((medio - izquierda - derecha),
                           polinomio1.getTerminos() / 2) +
             sumaExponente(derecha, polinomio1.getTerminos());
    }
    return izquierda +
           sumaExponente((medio - izquierda - derecha),
                         polinomio1.getTerminos() / 2) +
           sumaExponente(derecha, polinomio1.getTerminos() - 1);
  }
}

Polinomio sumaExponente(const Polinomio& polinomio, int exponente) {
  Polinomio resultado(polinomio);
  for (size_t i = 0; i < polinomio.get_sz(); ++i) {
    resultado[i].setExponente(polinomio[i].getExponente() + exponente);
  }
  return resultado;
}
