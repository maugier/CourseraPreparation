#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Sportif{
	double masse;
	double vitesse;
	double acc;
	double altitude;
	double surface;
};

void afficher(double temps, Sportif felix) {
	cout << temps << ", " << felix.altitude << ", " << felix.vitesse << ", " << felix.acc << endl;
}

int main() {
	double const g(9.81);
	double v0(0), t0(0), h0(39000);
	
	Sportif felix = {80, v0, g, h0, 2.0};
	
	double alpha(felix.surface/felix.masse);
	double terme;
	bool vit(true), accele(true);
	
	for(int i(0); felix.altitude>0; ++i){
		terme = exp((-1*alpha)*(i-t0));
		
		felix.vitesse = (g/alpha)*(1-terme)+(v0*terme);
		felix.acc = g - (alpha*felix.vitesse);
		felix.altitude = h0 - (g/alpha)*(i-t0)-(((v0-g)/alpha)/alpha)*(1-terme);
		
		if(felix.vitesse>343 and vit==true){
			cout << "## Felix depasse la vitesse du son"<< endl;
			vit = false;
		}
		
		if(felix.acc < 0.5 and accele==true){
			cout << "## Felix a atteint sa vitesse maximale" << endl;
			accele = false;
		}
		
		afficher(i, felix);
	}

	return 0;
}
