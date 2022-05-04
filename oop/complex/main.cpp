#include <iostream>
#include <cmath>

class Complex {
  private:
    double r;
    double i;
  
  public:
    Complex(double x = 0, double y = 0) {
      r = x;
      i = y;
    }

    double complex_module() {
      return sqrt(r * r + i * i);
    }

    Complex complex_conjugate() {
      return Complex(r, -i);
    }

    void print_complex() {
      printf(i > 0 ? "%.5lf + j%.5lf\n" : "%.5lf - j%.5lf\n", r, -i);
    }

    Complex sum(Complex z) {
      return Complex(r + z.r, i + z.i);
    }

    Complex subtraction(Complex z) {
      return Complex(r - z.r, i - z.i);
    }
};

int main() {
  Complex z1(1, 1), z2(1, -2);
  Complex z3 = z1.complex_conjugate();
  Complex z4 = z1.sum(z2);

  z3.print_complex();
  z4.print_complex();

  return 0;
}