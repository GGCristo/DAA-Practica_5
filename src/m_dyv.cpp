#include "../include/m_dyv.hpp"

Polinomio MDyV::multiplicacion(const Polinomio& polinomio1,
                               const Polinomio& polinomio2) {
  polinomio_t resultado = {Monomio(2, 1), Monomio(2, 0)};
  Polinomio A0 = polinomio1.getDerecha();
  Polinomio A1 = polinomio1.getIzquierda();
  Polinomio B0 = polinomio2.getDerecha();
  Polinomio B1 = polinomio2.getIzquierda();
  auto exponenteMedio = A1[A1.get_sz() - 1].getExponente();
  auto exponenteDerecha = exponenteMedio + B1[B1.get_sz() - 1].getExponente();
  std::cout << "ExponenteMedio: " << exponenteMedio << '\n';
  std::cout << "ExponenteDerecha: " << exponenteDerecha << '\n';
  A0.show();
  A1.show();
  B0.show();
  B1.show();
  return Polinomio(resultado);
}

polinomio_t multiplicar(const polinomio_t& polinomio1,
                        const polinomio_t& polinomio2) {
  /*
polinomio_t resultado;
for (size_t i = 0; i < polinomio1.size(); ++i) {
for (size_t j = 0; j < polinomio2.size(); ++j) {
resultado.push_back(polinomio1[i] * polinomio2[j]);
}
}*/
}