#include "../include/m_clasico.hpp"

monomio_t MClasico::multiplicacion(const monomio_t& polinomio1,
                                   const monomio_t& polinomio2) {
  monomio_t resultado;
  int N = (polinomio1.size() > polinomio2.size() ? polinomio1.size()
                                                 : polinomio2.size());
  std::cout << '\n';
  for (size_t i = 0; i <= 2 * N - 2; ++i) {
    int coeficiente = 0;
    int exponente = 0;
    for (size_t j = 0; j <= i; ++j) {
      if (j < polinomio1.size() && (i - j) < polinomio2.size()) {
        coeficiente +=
            polinomio1[j].getCoeficiente() * polinomio2[i - j].getCoeficiente();
        exponente =
            polinomio1[j].getExponente() + polinomio2[i - j].getExponente();
      }
    }
    resultado.push_back(Monomio(coeficiente, exponente));
  }
  for (size_t i = 0; i < resultado.size(); ++i) {
    std::cout << resultado[i].getCoeficiente() << " x^"
              << resultado[i].getExponente() << " + ";
  }
  std::cout << '\n';
  return resultado;
}