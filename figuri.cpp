#include <iostream>
#include <fstream>
#include <math.h>

class Figure {

  public:
    virtual float get_area() = 0;
    virtual float get_perimeter() = 0;
    virtual void  inspect() = 0;
};

// -------------------------------------------
class Triangle : public Figure {
  float a, b, c;
  
  public:
    Triangle(float a, float b, float c);
    float get_area();
    float get_perimeter();
    void  inspect();
};

Triangle::Triangle(float a, float b, float c)
{
  this->a = a;
  this->b = b;
  this->c = c;
}

float Triangle::get_area()
{
  float p = this->get_perimeter() / 2; // semiperimetru
  return sqrt( p * (p-a) * (p-b) * (p-c) );
}

float Triangle::get_perimeter()
{
  return a + b + c;
}

void Triangle::inspect()
{
  std::cout << "<Triangle { a: " 
            << this->a << ", b: " 
            << this->b << ", c: " 
            << this->c << " } >"
            << std::endl;
}

// -------------------------------------------

class Square : public Figure {
  float a;

  public:
    Square(float a);
    float get_area();
    float get_perimeter();
    void  inspect();
};

Square::Square(float a)
{
  this->a = a;
}
float Square::get_area()
{
  return a * a;
}
float Square::get_perimeter()
{
  return 4 * a;
}

void Square::inspect()
{
  std::cout << "<Square a: " 
            << this->a 
            << " >" 
            << std::endl;
}

// -------------------------------------------

class Rectangle : public Figure {
  float a, b;

  public:
    Rectangle(float a, float b);
    float get_area();
    float get_perimeter();
    void  inspect();
};

Rectangle::Rectangle(float a, float b)
{
  this->a = a;
  this->b = b;
}

float Rectangle::get_area()
{
  return a * b;
}

float Rectangle::get_perimeter()
{
  return 2 * a + 2 * b;
}

void Rectangle::inspect()
{
  std::cout << "<Rectangle a: "
            << this->a
            << ", b: "
            << this->b
            << " >"
            << std::endl;
}

// -------------------------------------------

class Rhombus : public Figure {
  float a, b; // diagonalele rombului

  public:
    Rhombus(float diag1, float diag2);
    float get_area();
    float get_perimeter();
    float get_a(); // latura rombului
    void  inspect();
};

Rhombus::Rhombus(float diag1, float diag2)
{
  this->a = diag1;
  this->b = diag2;
}
float Rhombus::get_area()
{
  return (a+b) / 2;
}
float Rhombus::get_perimeter()
{
  return 4 * this->get_a();
}
float Rhombus::get_a()
{
  return sqrt( pow(a/2, 2)+pow(b/2, 2) );
}

void Rhombus::inspect()
{
  std::cout << "<Rhombus a: "
            << this->a
            << ">"
            << std::endl;
}
// ------------------------------------------
int main()
{
  Rhombus romb1(1, 2);
  romb1.inspect();
  return 0;
}

