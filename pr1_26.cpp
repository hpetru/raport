#include <iostream>
#include <string>
#include <sstream>

class Temp
{
  int hh;
  int mm;
  int ss;
  
  public:
    Temp(){};
    Temp(int h, int m, int s)
    {
      this->setHours(h);
      this->setMinutes(m);
      this->setSeconds(s);
    };

    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);

    void cout();

    Temp operator +  (Temp);
    Temp operator -  (Temp);
    void operator ++ ();
    void operator -- ();
    Temp operator =  (int);

    bool operator == (Temp);
    bool operator != (Temp);
    bool operator >  (Temp);
    bool operator <  (Temp);
    bool operator >= (Temp);
    bool operator <= (Temp);

    void operator << (std::string);
    void operator >> (std::string);
};

void Temp::setHours(int h)
{
  if(h < 0)
  {
    this->hh = 0;
    return;
  }
  if(h < 24)
  {
    this->hh = h;
  }
  else
  {
    this->hh = h - 24;
  }
}
void Temp::setMinutes(int m)
{
  if(m < 0) 
  {
    this->mm = 0;
    return;
  }
  if(m <= 60)
  {
    this->mm = m;
  }
  else
  {
    while(m > 60)
    {
      this->hh++;
      m -= 60;
    }
    this->mm = m;
  }
}
void Temp::setSeconds(int s)
{
  if(s < 0)
  {
    this->ss = 0;
    return;
  }
  if(s <= 60)
  {
    this->ss = s;
  }
  else
  {
    while(s > 60)
    {
      this->mm++;
      s -= 60;
    }
    this->ss = s;
  }
}


Temp Temp::operator + (Temp t)
{
  this->setHours(t.hh + this->hh);
  this->setMinutes(t.mm + this->mm);
  this->setSeconds(t.ss + this->ss);
}
Temp Temp::operator - (Temp t)
{
  this->setHours(this->hh - t.hh);
  this->setMinutes(this->mm - t.mm);
  this->setSeconds(this->ss - t.ss);
}
Temp Temp::operator = (int s)
{
  this->setSeconds(s);
  return *this;
}
void Temp::operator -- ()
{
  this->setSeconds(this->ss - 1);
}
void Temp::operator ++ ()
{
  this->setSeconds(this->ss + 1);
}
bool Temp::operator == (Temp t)
{
  if(t.mm != this->mm)
    return 0;
  if(t.hh != this->hh)
    return 0;
  if(t.ss != this->ss)
    return 0;

  return 1;
}
bool Temp::operator != (Temp t)
{
  return !(*this == t);
}
bool Temp::operator > (Temp t)
{
  if(this->hh > t.hh)
    return 1;
  if(this->mm > t.mm)
    return 1;
  if(this->ss > t.ss)
    return 1;

  return 0;
}
bool Temp::operator < (Temp t)
{
  return !(*this > t);
}
bool Temp::operator >= (Temp t)
{
  if(*this == t || *this > t) return 1;
  return 0;
}
bool Temp::operator <= (Temp t)
{
  if(*this == t || *this < t) return 1;
  return 0;
}

void Temp::operator << (std::string str)
{
  int h;
  int m;
  int s;

  std::string buff;
  buff += str[0];
  buff += str[1];

  std::istringstream sbuff1(buff);
  sbuff1 >> h; 

  buff = "";
  buff += str[3];
  buff += str[4];
  std::istringstream sbuff2(buff);
  sbuff2 >> m;

  buff = "";
  buff += str[6];
  buff += str[7];
  std::istringstream sbuff3(buff);
  sbuff3 >> s; 

  this->setHours(h);
  this->setMinutes(m);
  this->setSeconds(s);
}
void Temp::cout()
{
  std::cout << this->hh << ":" << this->mm << ":" << this->ss << std::endl;
}

int main()
{
  Temp c;
  c << "11:80:1";
  c = -1;
  c.cout();

  return 0;
}
