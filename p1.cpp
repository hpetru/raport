#include <iostream>
#include <string>
#include <math.h>

class IFigure {
  public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

    virtual void read() = 0;
    virtual void write() = 0;
};

// -----------------------------------------------------------------
class Square : public IFigure {
  double a;

  public:
    double getArea() { return a * a; }
    double getPerimeter() { return 4 * a; }

    void read();
    void write();
};

void Square::read()
{
  std::cout << "Introduceti latura figurei" << std::endl;
  std::cout << "a = ";
  std::cin >> this->a;
}

void Square::write()
{
  std::cout << "<Partat x: " << this->a << " aria: " << this->getArea() << " perimetru: ";
  std::cout << this->getPerimeter() << " >" << std::endl;
}

// -----------------------------------------------------------------
class Triangle : public IFigure {
  double a, b, c;

  public:
    double getArea();
    double getPerimeter();

    void read();
    void write();
};

double Triangle::getArea() {
  double p = this->getPerimeter() / 2;

  return sqrt( p*(p-a)*(p-b)*(p-c) );
}

double Triangle::getPerimeter() {
  return a + b + c;
}

void Triangle::read() {
  std::cout << "Introduceti laturile triunghiului" << std::endl;
  std::cout << "a = "; std::cin >> a;
  std::cout << "b = "; std::cin >> b;
  std::cout << "c = "; std::cin >> c;
}

void Triangle::write() {
  std::cout << "<Triunghi aria: " << this->getArea() << " perimetru: " << this->getPerimeter() << " >";
  std::cout << std::endl;
}
// -----------------------------------------------------------------

int main()
{
  IFigure *figuri[20];
  
  for(int i = 0; i < 3; i++)
  {
    figuri[i] = new Square;
    figuri[i]->read();
  }

  for(int i = 3; i < 6; i++)
  {
    figuri[i] = new Triangle;
    figuri[i]->read();
  }

  for(int i = 0; i < 6; i++)
  {
    figuri[i]->write();
  }

  return 0;
}
