// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "../include/m_clasico.hpp"

Polinomio MClasico::multiplicacion(const Polinomio& polinomio1,
                                   const Polinomio& polinomio2) {
  polinomio_t resultado;
  size_t N = (polinomio1.get_sz() > polinomio2.get_sz() ? polinomio1.get_sz()
                                                        : polinomio2.get_sz());
  for (size_t i = 0; i <= 2 * N - 2; ++i) {
    int coeficiente = 0;
    int exponente = 0;
    for (size_t j = 0; j <= i; ++j) {
      if (j < polinomio1.get_sz() && (i - j) < polinomio2.get_sz()) {
        coeficiente +=
            polinomio1[j].getCoeficiente() * polinomio2[i - j].getCoeficiente();

        exponente =
            polinomio1[j].getExponente() + polinomio2[i - j].getExponente();
      }
    }
    // std::cout << coeficiente << '\n';
    if (coeficiente != 0) {
      resultado.push_back(Monomio(coeficiente, exponente));
    }
  }
  /*
  for (size_t i = 0; i < resultado.size(); ++i) {
    std::cout << resultado[i].getCoeficiente() << " x^"
              << resultado[i].getExponente() << " + ";
  }
  std::cout << '\n';
*/
  /*
   if (N == 1) {
     resultado.push_back(
         Monomio(polinomio1[0].getCoeficiente() *
   polinomio2[0].getCoeficiente(), polinomio1[0].getExponente() +
   polinomio2[0].getExponente()));
   }*/
  return Polinomio(resultado);
}
