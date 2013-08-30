#include <iostream>
using namespace std;

struct  sportif { double masse;double vitesse;double acceleration;double altitude;double surface;};
void afficher(double t,sportif a)
{cout<<t<<","<<a.altitude<<","<<a.vitesse<<","<<a.acceleration<<endl;}
sportif calculer(double t,sportif a,double v0,double h0,double t0)
{ const double B=a.surface/a.masse;
double v1;double h1;double a1;unsigned int c(0);
v1==(G/B)(1-(exp(-B(t-t0))))+(v0*(exp(-B(t-t0))));
h1==h0-(G/B)(t-t0)-((v0-(G/B))/B)*(1-(exp(-B(t-t0)));
a1==G-(B*v0);

do {c=c+1;
	 v1=(G/B)(1-(exp(-B(t-t0))))+v1*(exp(-B(t-t0)));
h1=h1--(G/B)(t-t0)-((v1-(G/B))/B)*(1-(exp(-B(t-t0)));
a1=G-(B*v1);}
while (h1=0.0)




int main() {
const double G=9.81;
double v0(0.0);double t0(0.0);double h0(39000.0);
sportif felix={80.0,v0,G,h0,2.0};
afficher(t0,felix);
  return 0;
}
