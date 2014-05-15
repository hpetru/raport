#include <iostream>

class Punct
{
  float x; float y;
  int culoare;
};

class Triunghi : virtual public Punct 
{
  float lung_lat;
};
class Patrat : virtual public Punct 
{
  float lung_lat;
};
class Figura : public Triunghi, public Patrat
{
};

int main()
{
  return 0;
}
