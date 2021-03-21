#include "../include/m_clasico.hpp"

Polinomio MClasico::multiplicacion(const Polinomio& polinomio1,
                                   const Polinomio& polinomio2) {
  polinomio_t resultado;
  int N = (polinomio1.get_sz() > polinomio2.get_sz() ? polinomio1.get_sz()
                                                     : polinomio2.get_sz());
  std::cout << '\n';
  for (size_t i = 0; i < 2 * N - 2; ++i) {
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
    resultado.push_back(Monomio(coeficiente, exponente));
  }
  /*
  for (size_t i = 0; i < resultado.size(); ++i) {
    std::cout << resultado[i].getCoeficiente() << " x^"
              << resultado[i].getExponente() << " + ";
  }
  std::cout << '\n';
  */
  return Polinomio(resultado);
}