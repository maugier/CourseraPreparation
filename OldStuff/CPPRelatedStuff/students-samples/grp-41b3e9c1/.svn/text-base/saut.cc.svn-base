#include <iostream>
#include <cmath>
using namespace std;

struct sportif {
	double masse;
	double vChute;
	double acceleration;
	double altitude;
	double surface; 
};

void afficher (double temps, sportif x) {
	
	cout << temps << ", " << x.altitude << ", " << x.vChute << ", " << x.acceleration << endl;
}

double vitesse (double x, double y, double w, double z) {
	double vitesse;
	vitesse = (x/y)*(1-w)+z*w;
	return vitesse;
}

double hauteur (sportif b, double x, double y, double z, double w) {
	double hauteur;
	
	hauteur = (b.altitude)- ( (b.acceleration)/x )*(y-z) - ( ( (b.vChute)-( (b.acceleration) / x ) ) /x ) * (1-w);
	return hauteur;
}

double acc (sportif c, double x, double y) {
	double acc;
	acc= (c.acceleration)- x*y;
	return acc;
}



int main() {
	double const g(9.81);
	double v0(0.0);
	double t0(0.0);
	double h0(39000);
	
	sportif felix = {80, v0, g, h0, 2.0};
	
	afficher (t0, felix);
	
	double a( (felix.surface)/(felix.masse) );
	double t(0.0);
	
	double terme( exp(-a*(t-t0) ) );
	
	for (double t(0.0); felix.altitude >0.0; t++) {
		
		cout << t << ", " << hauteur(felix, a, t, t0, terme) << ", " << acc (felix, a, 
		
		
		
		}
	
	
	


  return 0;
}
