// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "Complexo.h"
#include <cmath>
#include <iostream>//

using std::cout;
using std::cin;

Complexo::Complexo()
{
	real_=0.0;
	imag_=0.0;
}

Complexo::Complexo(double a)
{
	real_=a;
	imag_=0.0;
}

Complexo::Complexo(double a,double b)
{
	real_=sqrt(a*a+b*b);
	imag_=atan(b/a);
}

double Complexo::real() 
{
	double r;
	r=real_*cos(imag_);
  return r;
}

double Complexo::imag() 
{
  double i;
  i=real_*sin(imag_);
  return i;
}

bool Complexo::operator==(Complexo x) 
{
   if(real_== x.real_ && imag_==x.imag_)
  {
  	return true;
  }
  else{
	  return false;
  }
  
}

void Complexo::operator=(Complexo x) 
{
	real_=x.real_;
	imag_=x.imag_;
}

double Complexo::modulo()
{
	return real_;
}

Complexo Complexo::conjugado()
{
    Complexo conjugado;
	conjugado.imag_=-imag_;
	conjugado.real_=real_;
	return conjugado;
}

Complexo Complexo::operator-() 
{
	Complexo simetrico;
	double r,i;
	r=-real_*cos(imag_);
    i=-real_*sin(imag_);
	simetrico=Complexo(r,i);
	return simetrico;
}

Complexo Complexo::inverso()
{
  Complexo i;
  
  if(real_ !=0.0 && imag_!=0.0)
  {
  	i.real_=1/real_;
	i.imag_=-imag_;		
  }
  return i;
}

Complexo Complexo::operator+(Complexo y) 
{
  Complexo s;
  s=Complexo((real_*cos(imag_)+y.real()),(real_*sin(imag_)+y.imag()));
  return s;
}

Complexo Complexo::operator-(Complexo y) {
  Complexo c;
  c=Complexo((real_*cos(imag_)-y.real()),(real_*sin(imag_)-y.imag()));
  return c;
}

Complexo Complexo::operator*(Complexo y) {
  Complexo p;
  p=Complexo(((y.modulo()*real_)*cos(y.imag_+imag_)),((y.modulo()*real_)*sin(imag_+y.imag_)));
  return p;
}

Complexo Complexo::operator/(Complexo y) {
  Complexo c;
  c=Complexo(((real_/y.modulo())*cos(imag_-y.imag_)),((real_/y.modulo()*sin(imag_-y.imag_))));
  return c;
}

void CalcularRaizes(float a, float b, float c,Complexo * r1, Complexo* r2)
{
    float delta,x1,x2,raiz;
	delta=pow(b,2)-(4*a*c);
	double real,imag;
	
	if(delta>0.0)
	{
		x1=((-b)+(sqrt(delta)))/(2*a);
		x2=((-b)-(sqrt(delta)))/(2*a);
		cout<<" x1= "<<x1<<" \n x2= "<<x2<<"\n";
		
	}
	if(delta==0.0)
	{
		x1=(-b)/(2*a);
		x2=-x1;
		cout<<" x1= "<<x1<<"\n x2= "<<x2<<"\n";
	}
	if(delta<0.0)
	{
		raiz=sqrt(delta*(-1));
		
		real=(-b)/(2*a);
		imag=-(raiz/(2*a));
		
		r1= new Complexo(real,imag);
	    
		real=(-b)/(2*a);
		imag=(raiz/(2*a));

		r2= new Complexo(real,imag);
		
		real=r1->real();
		imag=r1->imag();
		cout<<"Raizes complexas \n";
		cout<<"x1 = ("<<real<<","<<imag<<")\n";
		real=r2->real();
		imag=r2->imag();
		
		cout<<"x2 = ("<<real<<","<<imag<<")\n";
		
	}
}

