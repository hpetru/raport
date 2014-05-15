#include <iostream>
#include <vector>
#include <algorithm>

// --------------------------------------------
class HRow : public std::vector<int>
{
  public:
    int sum();
    int max();
    int min();
    void sort();

    friend std::ostream& operator << (std::ostream&, HRow);
};

int HRow::sum()
{
  int tmp = 0;
  for(int i = 0; i < this->size(); i++)
  {
    tmp += this->at(i);
  }
  return tmp;
}
int HRow::max()
{
  int max = this->at(0);
  for(int i = 1; i < this->size(); i++)
  {
    int tmp = this->at(i);
    if(max < tmp)
    {
      max = tmp;
    }
  }
  return max;
}
int HRow::min()
{
  int min = this->at(0);
  for(int i = 1; i < this->size(); i++)
  {
    int tmp = this->at(i);
    if(min > tmp)
    {
      min = tmp;
    }
  }
  return min;
}
void HRow::sort()
{
  std::sort(this->begin(), this->end());
}

std::ostream& operator << (std::ostream& out, HRow r)
{
  for(int i = 0; i < r.size(); i++)
  {
    out << r[i] << " ";
  }
  out << "> " << r.min() << " ";
  out << "< " << r.max();
  return out;
}
// --------------------------------------------
class HContainer : public std::vector<HRow>
{
  public:
    int sum();
    void sort();
    int max_row_sum();

    friend std::ostream& operator << (std::ostream&, HContainer);
};

int HContainer::sum()
{
  int tmp = 0;
  for(int i = 0; i < this->size(); i++)
  {
    tmp += this->at(i).sum();
  }
  return tmp;
}
void HContainer::sort()
{
  for(int i = 0; i < this->size(); i++)
  {
    this->at(i).sort();
  }
}
int HContainer::max_row_sum()
{
  int max = this->at(0).sum();
  for(int i = 1; i < this->size(); i++)
  {
    int tmp = this->at(i).sum();
    if(max < tmp)
    {
      max = tmp;
    }
  }
  return max;
}

std::ostream& operator << (std::ostream &out, HContainer c)
{
  for(int i = 0; i < c.size(); i++)
  {
    out << c[i];
    out << std::endl;
  }
  return out;
}
// ---------------------------------------------

int main()
{
  HContainer container;
  for(int i = 0; i < 10; i++)
  {
    HRow row;
    for(int j = 10; j > 0; j--)
    {
      row.push_back(j);
    }
    container.push_back(row);
  }
  
  // Afisarea
  std::cout << container;
  std::cout << "Super suma este: " << container.sum();

  // Afisarea deja sortata
  container.sort();
  std::cout << container;

  // Suma maxima de pe linii
  std::cout << container.max_row_sum() << std::endl;

  return 0;
}
