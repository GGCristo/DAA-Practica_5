#include "../include/polinomio.hpp"

#include "../include/m_clasico.hpp"

Polinomio::Polinomio(std::vector<int> polinomio) {
  polinomio_ = polinomio;
  for (size_t i = 0; i < polinomio_.size(); i++) {
    std::cout << polinomio_[i] << ' ';
  }
  std::cout << '\n';
  terminos_ = polinomio_.size();
  grado_ = terminos_ - 1;
  std::cout << "Este polinomio tiene:\n";
  std::cout << terminos_ << " terminos\n";
  std::cout << "Y es de grado " << grado_ << '\n';
  multiplicar_ = std::make_unique<MClasico>();
};

std::vector<int> Polinomio::multiplicar(const Polinomio& polinomio2) {
  return multiplicar_->multiplicacion(this->polinomio_, polinomio2.polinomio_);
}