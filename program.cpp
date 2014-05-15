#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <iomanip.h>

class numar{
  protected:
    double a;
  public:
    virtual void citire();
    virtual double suprafata(){return 0;}
    virtual void afisare(){cout<<"a="<<a;}
    virtual double perimetru(){return 0;}
    int tip(){return 0;}};

void numar::citire(){
  cout<<"a=";cin>>a;
}

class patrat:public numar{
  public:
    int tip(){return 1;}
    void citire(){cout <<"Indicati latura patratului"; numar::citire();}
    double arie(){return a*a;}
    double perimetru(){return 4*a;}
    void afisare(){cout<<"Patrat a="<<a;
      cout<<"Suprafata= "<<suprafata();
      cout<<"Perimetrul= "<<perimetru();}
};



class triunghi_echilateral:public numar{
  public:
    int tip(){return 2;}
    void citire(){cout<<"Indicati latura triunghiului echilateral" ;
      numar::citire();}
    double suprafata(){return (sqrt(3)*a*a)/4;}
    double perimetru(){return 3*a;}
    void afisare(){cout<<"Triunghi a="<<a;
      cout<<"Suprafata="<<suprafata();
      cout<<"Perimetru=" <<perimetru();}
};



numar *fig[100];
int n;



void citire(){
  int q;
  cout<<"Introduceti numarul de figuri ";cin>>n;
  for(i=0;i<n;i++){
    cout<<"Indicati"<<endl<<"1-Patrat"<<endl<<"2-triunghi_echilateral"<<endl;
    cin>>g;
    switch(q){
      case 1:fig[i]=new patrat;break;
      case 2:fig[i]=new triunghi_echilateral; break;
      default :fig[i]=new numar;
    }

    fig[i]->citire();
  }
}

void afisare(){
  int  suprafata, perimetru;
  double smax,pmax;
  smax=pmax=0;
  for(i=0;i<n;i++)
  {
    fig[i]->afisare();
    if(smax<fig[i]->suprafata())
    {smax=fig[i]->suprafata(); suprafata=i;}
    if(pmax<fig[i]->perimetru()){pmax=fig[i]->perimetru();perimetru=i;}
  }

  cout<<"Figura cu suprafata maxima "<<endl;
  fig[suprafata]->afisare();
  cout<<"Figura cu perimetru maxim "<<endl;
  fig[perimetru]->afisare();
}

void af_tip(int t) {
  for(int i=0;i<n;i++)
    if(fig[i]->tip()==t)fig[i]->afisare();
}

void lista_fig(){
  cout<<"Lista patratelor "<<endl;
  af_tip(1);
  cout<<"Lista triunghiurilor echilaterale "<<endl;
  af_tip(2);
}

void sortare()
{
  numar *aux;
  int i,j;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
      if(fig[i]->suprafata()<fig[j]->suprafata())
      {
        aux=fig[i];
        fig[i]=fig[j];
        fig[j]=aux;
      }
  cout<<"Sortarea descrescator dupa suprafata "<<endl;
  for(int i=0;i<n;i++) fig[i]->afisare();
}
main(){
  citire();
  afisare();
  lista_fig();
  afisare();
  for(int i=0;i<n;i++) delete fig[i];
}