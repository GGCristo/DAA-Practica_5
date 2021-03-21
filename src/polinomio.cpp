#include "../include/polinomio.hpp"

#include "../include/m_clasico.hpp"

Polinomio::Polinomio(const Polinomio& polinomio)
    : polinomio_(polinomio.polinomio_), multiplicar_(polinomio.multiplicar_) {
  grado_ = polinomio.grado_;
  terminos_ = polinomio.terminos_;
}

Polinomio::Polinomio(std::vector<int> polinomio,
                     std::shared_ptr<MultiplicacionInterfaz> algoritmo) {
  polinomio_.reserve(polinomio.size());
  for (size_t i = 0; i < polinomio.size(); ++i) {
    polinomio_.push_back(Monomio(polinomio[i], polinomio.size() - i - 1));
  }
  terminos_ = polinomio.size();
  grado_ = terminos_ - 1;
  multiplicar_ = algoritmo;
}

Polinomio::Polinomio(const std::vector<Monomio> polinomio,
                     std::shared_ptr<MultiplicacionInterfaz> algoritmo) {
  polinomio_ = polinomio;
  multiplicar_ = algoritmo;
}

// void Polinomio::insert(Monomio monomio) { polinomio_.push_back(monomio); }

// size_t Polinomio::get_sz() const { return polinomio_.size(); }

Polinomio Polinomio::multiplicar(const Polinomio& polinomio2) {
  if (!multiplicar_) {
    setMultiplicar();
  }
  return Polinomio(
      multiplicar_->multiplicacion(this->polinomio_, polinomio2.polinomio_));
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
    default:
      std::cout << "Esa opción no esta contemplado, eligiendo clásico\n";
      multiplicar_ = std::make_unique<MClasico>();
      break;
  }
}

std::ostream& Polinomio::show(std::ostream& os) {
  for (size_t i = 0; i < polinomio_.size() - 1; ++i) {
    os << polinomio_[i].getCoeficiente() << "x^" << polinomio_[i].getExponente()
       << " + ";
  }
  os << polinomio_[polinomio_.size() - 1].getCoeficiente();
  os << '\n';
  return os;
}