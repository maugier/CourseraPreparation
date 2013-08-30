#include <iostream>
using namespace std;


struct Sportif {
	double masse;
	double vitesse;
	double acceleration;
	double altitude;
	double surface;};
	
void affiche(double t, Sportif nom);


int main() {
double const g(9.81);
double v0(0.0);
double t0(0.0);
double h0(39000.0);
double t(0.0);
double al(2.0/80.0);
Sportif felix ={80.0,v0,g,h0,2.0};
affiche(t0,felix);
do{t=t+1.0;
	felix.vitesse=(g/al)*(1-(-al*(t-t0)))+v0*(-al*(t-t0));
	felix.altitude=h0-(t-t0)*(g/al)-((v0-(g/al))/al)*(1-(-al*(t-t0)));
	felix.acceleration=g-al*felix.vitesse;
	affiche(t, felix);
}while(felix.altitude>0.0);
  return 0;
}

void affiche(double t, Sportif nom){
	cout<<t<<", "<<nom.altitude<<", "<<nom.vitesse<<", "<<nom.acceleration<<endl;
	}

