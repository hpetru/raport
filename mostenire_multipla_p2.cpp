#include <iostream>
#include <math.h>

class Cerc
{
  float raza;

  public:
    Cerc(float raza) 
    { 
      this->raza = raza; 
    }
    float perimetru()
    {
      return 0;
    }
    float arie()
    {
      return M_PI * pow(this->raza, 2);
    }
};
class Triunghi
{
  float lung_lat; float inaltime;

  public:
    Triunghi(float lung_lat, float inaltime) 
    { 
      this->lung_lat = lung_lat;
      this->inaltime = inaltime;
    }
    float perimetru()
    {
      float lat2 = sqrt( pow(this->lung_lat, 2) + pow(this->inaltime, 2) );
      return lat2 * 2 + this->lung_lat; 
    }
    float arie()
    {
      return (this->inaltime * this->lung_lat)/2;
    }
};
class Figura : public Cerc, public Triunghi
{
  public:
    Figura(float raza, float inaltime)
      : Cerc(raza), Triunghi(raza*2, inaltime) {};

    float perimetru()
    {
      return this->Triunghi::perimetru(); 
    }
    float arie()
    {
      return this->Triunghi::arie() + this->Cerc::arie();
    }
};

int main()
{
  return 0;
}
