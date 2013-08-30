#include <iostream>
using namespace std;

double const g(9.81);

struct sportif{
	double masse;
	double vitesseChute;
	double acceleration;
	double altitude;
	double surface;
};

void afficher(double temps,sportif Sportif);

int main() {
	
	double v0(0);
	double t0(0);
	double h0(39000);
	sportif felix={80,v0,9.81,h0,2.0};
	
	afficher(t0,felix);
	
for(double h;h>0;++h){
	sportif felix;
	alpha=felix.surface/felix:masse;
	double v(0);
	double h(0);
	double a(0);
	v=
	h=
	a=
	cout<<" v "
	cout<<" h "
	cout<<" a "
	
}

  return 0;
}

void afficher(double temps,sportif Sportif){
	
	cout<<" temps: "<<temps<<endl;
	cout<<" altitude: "<<Sportif.altitude<<endl;
	cout<<" vitesse: "<<Sportif.vitesseChute<<endl;
	cout<<"acceleration: "<<Sportif.acceleration<<endl;
}
	
