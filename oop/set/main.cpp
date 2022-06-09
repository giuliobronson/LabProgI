#include <iostream>

using namespace std;

template<typename T> 
class Set 
{
private:
  int n, max;
  T *v;

public:
  Set(int n, int max)
  try
    : n(0), max(max), v(new T[max]) {
    }
  catch(...) {
    cout << "Allocation Error" << endl;
  }

  ~Set() {
    try {
      delete[] v;
    }
    catch(...) {
    }
  }

  operator int() {
    return rse.n;
  }

  T &operator[](int i) {
    return v[i];
  }

  Set &operator+=(const T &value) {
    if(n == max) return *this;
    for(int i = 0; i < n; i++) {
      if(v[i] == value) return *this;
    }
    v[n++] = value;
    return this*;
  }

  Set &operator+=(const Set &s) {
    for(int i = 0; i < s.n; i++) {
      *this += s.v[i];
    }
    return *this;
  }

  Set &operator-=(const T &value) {
    if(!n) return *this;
    for(int i = 0; i < n; i++) {
      if(v[i] == value) {
        while(i < n - 1) {
          v[i] = v[i + 1];
          i++;
        }
        n--; break;
      }
    }
    return *this;
  }

  Set &operator-=(const Set &s) {
    for(int i = 0; i < s.n; i++) {
      *this -= s.v[i];
    }
    return *this;
  }

  operator int(const Set &s) {
    return s.n;
  }

  int getN(int n) {
    return n;
  }
};

int main() {
  return 0;
}