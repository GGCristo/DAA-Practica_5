// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "../include/polinomio.hpp"

#include "../include/m_clasico.hpp"
#include "../include/m_dyv.hpp"

Polinomio::Polinomio(std::vector<int> polinomioD,
                     std::shared_ptr<MultiplicacionInterfaz> algoritmo) {
  polinomio_.reserve(polinomioD.size());
  for (size_t i = 0; i < polinomioD.size(); ++i) {
    polinomio_.push_back(Monomio(polinomioD[i], polinomioD.size() - i - 1));
  }
  terminos_ = polinomioD.size();
  grado_ = terminos_ - 1;
  multiplicar_ = algoritmo;
}

Polinomio::Polinomio(const std::vector<Monomio> polinomioD,
                     std::shared_ptr<MultiplicacionInterfaz> algoritmo) {
  polinomio_ = polinomioD;
  multiplicar_ = algoritmo;
  terminos_ = polinomioD.size();
  grado_ = terminos_ - 1;
}

Polinomio Polinomio::getDerecha() const {
  auto mitad = polinomio_.begin() + round(polinomio_.size() / 2.0) - 1;
  return Polinomio(polinomio_t(mitad + 1, polinomio_.end()));
}

Polinomio Polinomio::getIzquierda() const {
  auto mitad = polinomio_.begin() + round(polinomio_.size() / 2.0) - 1;
  polinomio_t resultado;
  for (auto i = polinomio_.begin(); i <= mitad; ++i) {
    resultado.push_back(Monomio(i->getCoeficiente(),
                                i->getExponente() - this->getTerminos() / 2));
  }
  return Polinomio(resultado);
}

Polinomio Polinomio::operator+(const Polinomio& polinomioD) const {
  std::vector<Monomio> resultado;
  auto ptr1 = polinomio_.begin();
  auto ptr2 = polinomioD.getPolinomio_t().begin();
  while (ptr1 != polinomio_.end() &&
         ptr2 != polinomioD.getPolinomio_t().end()) {
    if (ptr1->getExponente() > ptr2->getExponente()) {
      resultado.push_back(*ptr1);
      ++ptr1;
    } else if (ptr1->getExponente() == ptr2->getExponente()) {
      resultado.push_back(*ptr1 + *ptr2);
      ++ptr1;
      ++ptr2;
    } else {
      resultado.push_back(*ptr2);
      ++ptr2;
    }
  }
  while (ptr1 != polinomio_.end()) {
    resultado.push_back(*ptr1);
    ++ptr1;
  }
  while (ptr2 != polinomioD.getPolinomio_t().end()) {
    resultado.push_back(*ptr2);
    ++ptr2;
  }
  return Polinomio(resultado);
}

Polinomio Polinomio::operator-(const Polinomio& polinomioD) const {
  std::vector<Monomio> resultado;
  auto ptr1 = polinomio_.begin();
  auto ptr2 = polinomioD.getPolinomio_t().begin();
  while (ptr1 != polinomio_.end() &&
         ptr2 != polinomioD.getPolinomio_t().end()) {
    if (ptr1->getExponente() > ptr2->getExponente()) {
      resultado.push_back(*ptr1);
      ++ptr1;
    } else if (ptr1->getExponente() == ptr2->getExponente()) {
      resultado.push_back(*ptr1 - *ptr2);
      ++ptr1;
      ++ptr2;
    } else {
      resultado.push_back(*ptr2);
      ++ptr2;
    }
  }
  while (ptr1 != polinomio_.end()) {
    resultado.push_back(*ptr1);
    ++ptr1;
  }
  while (ptr2 != polinomioD.getPolinomio_t().end()) {
    resultado.push_back(*ptr2);
    ++ptr2;
  }
  return Polinomio(resultado);
}

const Monomio& Polinomio::operator[](unsigned int index) const {
  return polinomio_[index];
}

bool Polinomio::operator==(const Polinomio& polinomio) {
  if (get_sz() != polinomio.get_sz()) return false;
  for (size_t i = 0; i < get_sz(); ++i) {
    if (polinomio_[i].getCoeficiente() != polinomio[i].getCoeficiente() ||
        polinomio_[i].getExponente() != polinomio[i].getExponente()) {
      return false;
    }
  }
  return true;
}

const polinomio_t& Polinomio::getPolinomio_t() const { return polinomio_; }

Monomio& Polinomio::operator[](unsigned int index) { return polinomio_[index]; }

size_t Polinomio::getGrado() const { return grado_; }

size_t Polinomio::getTerminos() const { return terminos_; }

size_t Polinomio::get_sz() const { return polinomio_.size(); }

Polinomio Polinomio::multiplicar(const Polinomio& polinomio2) {
  if (!multiplicar_) {
    setMultiplicar();
  }
  return multiplicar_->multiplicacion(*this, polinomio2);
}

void Polinomio::setMultiplicar() {
  int eleccion;
  std::cout << "Eliga un algoritmo de multiplicación\n";
  std::cout << "Clásico[0], DyV[1]\n";
  std::cin >> eleccion;
  switch (eleccion) {
    case 0:
      multiplicar_ = std::make_unique<MClasico>();
      break;
    case 1:
      multiplicar_ = std::make_unique<MDyV>();
      break;
    default:
      std::cout << "Esa opción no esta contemplado, eligiendo clásico\n";
      multiplicar_ = std::make_unique<MClasico>();
      break;
  }
}

void Polinomio::setMultiplicar(
    std::shared_ptr<MultiplicacionInterfaz> algoritmo) {
  multiplicar_ = algoritmo;
}

std::ostream& Polinomio::show(std::ostream& os) const {
  for (size_t i = 0; i < polinomio_.size() - 1; ++i) {
    os << polinomio_[i] << " + ";
  }
  if (polinomio_.size() >= 1) {
    os << polinomio_[polinomio_.size() - 1];
    os << '\n';
  }
  return os;
}
