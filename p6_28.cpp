#include <iostream>
#include <fstream>
#include <vector>

class Natural {
  std::vector<int> digits;

  Natural fromString(std::string);
  int charToDigit(char);
  
  public:
    Natural();
    Natural(std::string);

    Natural operator - (int);
    Natural operator + (int);

    friend std::istream& operator >> (std::istream &in, Natural &n);
    friend std::ostream& operator << (std::ostream &out, Natural n);
};

Natural::Natural()
{
  digits.push_back(0);
}
Natural::Natural(std::string strBuff)
{
  this->fromString(strBuff);
}

Natural Natural::fromString(std::string str)
{
  this->digits.clear();

  char buff;

  for(size_t i = 0; i < str.length(); i++)
  {
    buff = str[i];
    this->digits.push_back(this->charToDigit(buff));
  }

  return *this;
}

// Conform tabelului ASCII
int Natural::charToDigit(char ch)
{
  if((int)ch < 48 || (int)ch > 57)
  {
    return 0;
  }
  return (int)ch - 48;
}

Natural Natural::operator + (int nr) 
{
}

std::istream& operator >> (std::istream &in, Natural &n)
{
  std::string strBuff;
  in >> strBuff;

  n.fromString(strBuff);

  return in;
}
std::ostream& operator << (std::ostream &out, Natural n)
{
  for(size_t i = 0; i < n.digits.size(); i++)
  {
    out << n.digits[i];
  }
  return out;
}

int main()
{
  Natural n;
  
  std::cin >> n;
  std::cout << n;

  return 0;
}
