#pragma once

class Monomio {
  public:
    Monomio(); // Constructor por defecto
    Monomio(int coef, int exp); // Constructor con Coeficiente y Exponente
    int Evaluar(int x) const;
    int getCoeficiente() const;
    void setCoeficiente(int c);
    void setExponente(int e);
  private:
    int Coeficiente;
    int Exponente;
};
