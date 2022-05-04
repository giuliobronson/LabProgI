#include <iostream>
#include <cmath>

using namespace std;

class RegularPolygon{
  private:
    int number_of_edges;
    double edge_size;

  public:
    RegularPolygon(int number_of_edges = 0, double edge_size = 0) {
      this->number_of_edges = number_of_edges;
      this->edge_size = edge_size;
    }

    double internalAnglesSum() {
      return this->number_of_edges * M_PI + 2 * M_PI; 
    }

    double perimeter() {
      return this->number_of_edges * this->edge_size;
    }
};

class Square:public RegularPolygon {
  public:
    Square(double edge_size):
      RegularPolygon(4, edge_size){
    }
};

class Triangle:public RegularPolygon {
  public:
    Triangle(double edge_size = 0) {
      RegularPolygon(3, edge_size);
    }
};


int main() {
  return 0;
}