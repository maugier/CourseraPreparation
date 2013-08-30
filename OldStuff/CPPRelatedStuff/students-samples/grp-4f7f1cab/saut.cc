#include <iostream>
#include <cmath>
using namespace std;

struct sportif{
	
	int masse;
	double surface_corps;
	double vitesse_chute;
	double acceleration;
	double altitude;
	
};

sportif afficher(double temps, sportif a);	

	
	
int main() {
	
const double g(9.81);
double v0(0.0);
double t0(0.0);
double h0(39000);



sportif felix = {80,2.0,v0,g,h0};
afficher(t0, felix);

double alpha(0.0);
alpha = felix.surface_corps/felix.masse ;
double terme(0.0);
double t(0.0);
terme = exp(-alpha/(t-t0));


  return 0;
}

sportif afficher(double temps, sportif a){
	
	cout << temps << " , " << a.altitude << " , " << a.vitesse_chute << " , " << a.acceleration ;
	
	}
	
	
	
	
	
	
	
