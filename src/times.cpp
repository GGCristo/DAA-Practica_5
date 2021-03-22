#include "../include/times.hpp"

void times(size_t tamano) {
  std::vector<int> polinomio1;
  polinomio1.reserve(tamano);
  std::vector<int> polinomio2;
  polinomio2.reserve(tamano);
  for (size_t i = 0; i < tamano; ++i) {
    polinomio1.push_back(Random::get(-9, 9));
  }
  for (size_t i = 0; i < tamano; ++i) {
    polinomio2.push_back(Random::get(-9, 9));
  }
  // MClásico
  Polinomio polinomio1C(polinomio1, std::make_shared<MClasico>());
  Polinomio polinomio2C(polinomio2);
  if (tamano < 10) {
    std::cout << "Primer polinomio:\n";
    polinomio1C.show();
    std::cout << "Segundo polinomio:\n";
    polinomio2C.show();
  }
  auto t1 = std::chrono::high_resolution_clock::now();
  Polinomio resultado(polinomio1C.multiplicar(polinomio2C));
  auto t2 = std::chrono::high_resolution_clock::now();
  if (tamano < 10) {
    std::cout << "Resultado MClasico:\n";
    resultado.show();
  }
  std::cout
      << "El algoritmo tardó:\n"
      << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
      << " microsegundos | "
      << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                 .count() /
             1000.0
      << " milisegundos | "
      << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                 .count() /
             1000000.0
      << " segundos\n";
  polinomio1C.setMultiplicar(std::make_shared<MDyV>());
  auto t3 = std::chrono::high_resolution_clock::now();
  resultado = polinomio1C.multiplicar(polinomio2C);
  auto t4 = std::chrono::high_resolution_clock::now();
  if (tamano < 10) {
    std::cout << "Resultado MDyV:\n";
    resultado.show();
  }
  std::cout
      << "El algoritmo tardó:\n"
      << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count()
      << " microsegundos | "
      << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3)
                 .count() /
             1000.0
      << " milisegundos | "
      << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3)
                 .count() /
             1000000.0
      << " segundos\n";
}

void times() {
  std::cout << "||||||||||TESTEO PEQUEÑO|||||||||\n";
  times(6);
  std::cout << "||||||||||TESTEO MEDIANO|||||||||\n";
  times(100);
  std::cout << "||||||||||TESTEO GRANDE|||||||||\n";
  times(1000);
  std::cout << "||||||||||TESTEO ENORME|||||||||\n";
  times(32000);
}