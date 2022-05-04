#include <iostream>
#include <cmath>

using namespace std;

class Point {
  private:
    double x, y, z;

  public:
    Point(double a = 0, double b = 0, double c = 0) {
      x = a;
      y = b;
      z = c;
    }

    double distanceToOrigin() {
      return sqrt(x * x + y * y + z * z);
    }

    double distanceToPoint(Point p) {
      return sqrt((x - p.x) * (x - p.x) + 
                  (y - p.y) * (y - p.y) + 
                  (z - p.z) * (z - p.z));
    }

    double getX() {
      return x;
    }

    double getY() {
      return y;
    }

    double getZ() {
      return z;
    }

    void setX(double n) {
      x = n;
    }

    void setY(double n) {
      y = n;
    }

    void setZ(double n) {
      z = n;
    }
};

int main() {
  double x1, y1, z1;
  double x2, y2, z2;
  double dist;

  cin >> x1 >> y1 >> z1;
  cin >> x2 >> y2 >> z2;

  Point point1(x1, y1, z1);
  Point point2(x2, y2, z2);

  cout << point1.distanceToPoint(point2) << endl;

  return 0;
}