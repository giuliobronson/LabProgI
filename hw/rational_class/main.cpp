#include <iostream>

using namespace std;

class Rational {
  private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
      while(b) {
        int tmp = b;
        b = a % b;
        a = tmp;
      }
      return a;
    }

  public:
    Rational(int numerator = 1, int denominator = 1) {
      try {
        if(denominator == 0) throw "math error";
        int divisor = gcd(numerator, denominator);
        this->numerator = numerator / divisor;
        this->denominator = denominator / divisor;
      }
      catch(const char* msg) {
        cerr << msg << endl;
      }
    }

    void setNumerator(int numerator) {
      this->numerator = numerator;
    }

    int getNumerator() {
      return this->numerator;
    }
    
    void setDenominator(int denominator) {
      this->denominator = denominator;
    }

    int getDenominator() {
      return this->denominator;
    }

    Rational sum(Rational r) {
      int m = r.getNumerator();
      int n = r.getDenominator();
      return Rational(this->numerator * n + m * this->denominator, this->denominator * n);
    }

    Rational subtract(Rational r) {
      int m = r.getNumerator();
      int n = r.getDenominator();
      return Rational(this->numerator * n - m * this->denominator, this->denominator * n);
    }

    Rational multiply(Rational r) {
      return Rational(r.getNumerator() * this->numerator, r.getDenominator() * this->denominator);
    }

    Rational divide(Rational r) {
      return Rational(r.getDenominator() * this->numerator, r.getNumerator() * this->denominator);
    }

    void printFractionFormat() {
      cout << this->numerator << "/" << this->denominator << endl;
    }

    void printFloatingPointFormat() {
      cout << this->numerator / this->denominator << endl;
    }
};

int main() {
  Rational r1 = Rational(5, 6);
  Rational r2 = Rational(3, 4);
  Rational r3 = r1.sum(r2);

  r3.printFloatingPointFormat();
  r3.printFractionFormat();

  return 0;
}