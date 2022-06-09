#include <iostream>
#include <ostream>
#include <sstream>

using namespace std;

class DivisionPerZero
{
private:
    int line;
    string msg;

public:
    DivisionPerZero(int line) : line(line) {
        ostringstream aux;
        aux << "In line " << line << ", division per zero not allowed" << endl;
        msg = aux.str();
    }

    int getLine() {
        return line;
    }

    string getMsg() {
        return msg;
    }
};

class Rational
{
private:
    int num, den;

    int gcd(int a, int b) {
        while(b) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

public:
    Rational(int num, int den) {
        if(!den) throw DivisionPerZero(45);
        int d = gcd(num, den);
        this->num = num / d;
        this->den = den / d;
    }

    Rational(const Rational &r) : num(r.num), den(r.den) {
    }

    int getNumerator() {
        return num;
    }

    int getDenominator() {
        return den;
    }

    Rational operator+(const Rational &rhs) {
        return Rational(num * rhs.den + rhs.num * den, den * rhs.den);
    }

    Rational operator-(const Rational &rhs) {
        return Rational(num * rhs.den - rhs.num * den, den * rhs.den);
    }

    Rational &operator++() {
        this->num = num + den;
        return *this;
    }

    Rational operator++(int) {
        Rational r(*this);
        this->num = num + den;
        return r;
    }

    operator float() {
        return float(num) / den;
    }

    friend ostream &operator<<(ostream &os, const Rational &rhs);
};

ostream &operator<<(ostream &os, const Rational &rhs) {
    os << rhs.num << "/" << rhs.den;
    return os;
}

int main() {
    try {
        Rational r(10, 15);
        cout << r++ << endl;
        cout << float(r) << endl;
        cout << ++r << endl;

        Rational s(30, 24);
        cout << r + s << endl;
        return 0;
    }
    catch(DivisionPerZero dz) {
        cout << dz.getMsg();
        return 1;
    }
}