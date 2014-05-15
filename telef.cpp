#include <iostream>
#include <string>
#include <vector>

class Phone
{
  std::string brand;

  std::string year_of_publication;
  int exp_timestamp;

  std::string color;
  float price;
};
//=---------------------------------------
template<class T>
class Collection : std::vector<T>
{

};
//=---------------------------------------
class PhoneCollection : public Collection<Phone>
{

};
//=---------------------------------------
class StoreIO
{
  private:
  void menu(std::ostream&);
  void header(std::ostream&);
  void footer(std::ostream&);

  public:
  friend std::istream& operator >> (std::istream&, StoreIO&);
};

void StoreIO::menu(std::ostream& out)
{
  this->header(out);
  this->footer(out);
}

std::istream& operator >> (std::istream& in, StoreIO& store)
{
  bool b = 0;
  //while(b)
  //{
  //}
  return in;
}
//=---------------------------------------
int main()
{
  StoreIO store;
  std::cin >> store;
}
