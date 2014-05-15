#include <iostream>
#include <string>
#include <fstream>

class Person
{
  std::string first_name;
  std::string last_name;
  unsigned int year;
  unsigned long int cnp;
  
  public:
  Person();
  Person(
      std::string first_name, 
      std::string last_name,
      unsigned int year, 
      unsigned long int cnp
  );
  // Getters
  std::string getFirstName() { return this->first_name; }
  std::string getLastName()  { return this->last_name;  }
  unsigned int getYear()     { return this->year;       }
  unsigned long int getCNP() { return this->cnp;        }

  // Methods
  unsigned int getAge();
  unsigned int getCurrentYear() { return 2014; }

  void ioRead(std::ifstream io);
  void ioWrite(std::ofstream io);
};
Person::Person(
    std::string first_name,
    std::string last_name,
    unsigned int year,
    unsigned long int cnp
    )
{
  this->first_name = first_name;
  this->last_name = last_name;
  this->year = year;
  this->cnp = cnp;
}

unsigned int Person::getAge()
{
  return this->getCurrentYear() - this->getYear();
}

void Person::ioRead(std::ifstream io)
{
  io >> this->first_name;
  io >> this->last_name;
  io >> this->year;
  io >> this->cnp;
}
void Person::ioWrite(std::ofstream io)
{
  io << "---------------------------------" << std::endl;
  io << this->getFirstName() << std::endl;
  io << this->getLastName()  << std::endl;
  io << this->getAge()       << std::endl;
  io << this->getCNP()       << std::endl;
  io << "---------------------------------" << std::endl;
}


// ---------------------------------------------
class Student : public Person 
{
  std::string group_name;
  float marks_average;
  float grant;

  public:
  Student(
      std::string fist_name, 
      std::string last_name, 
      unsigned int year, 
      unsigned long int cnp,
      float marks_average
      )
    :Person(first_name, last_name, year, cnp)
  {
    this->marks_average = marks_average;
  };

  float getMarksAverage();
  float getGrant();

  void ioRead(std::ifstream io);
  void ioWrite(std::ofstream io);
};

float Student::getGrant()
{
  if(this->grant == -1)
  {
    this->grant = (this->getMarksAverage() > 7.5 ? this->getMarksAverage() * 75 : 0);
  }
  return this->grant;
}

void Student::ioRead(std::ifstream io)
{
  Person::ioRead(io); 
  io >> this->marks_average;
} 

void Student::ioWrite(std::ofstream io)
{
  Person::ioWrite(io);
  io << this->getGrant();
}
  

int main()
{
  return 0;
}
