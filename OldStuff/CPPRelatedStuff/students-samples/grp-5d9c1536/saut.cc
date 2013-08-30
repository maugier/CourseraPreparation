#include <iostream>
#include <cmath>
using namespace std;

struct Sportif { double masse;
				 double v_chute;
				 double acceleration;
				 double altitude;
				 double surface; };
				 
				 
void afficher(double temps, Sportif sportif);

int main() 
{
	const double g(9.81);
	double v0(0.0);
	double t0(0.0);
	double h0(39000.0);
	
	Sportif felix = { 80.0, v0, g, h0, 2.0 };
	
	afficher(t0, { h0, v0, g });
	
	double alpha(felix.surface/felix.masse);
	
	double t(t0);
	double terme(exp(-alpha*(t-t0)));
	
	
	double vt(g/alpha*(1-terme) + v0*terme);
	double ht(h0 - g/alpha*(t-t0) - (v0-g/alpha)/alpha*(1-terme));
	double at(g - alpha*vt); 
		
	do {
		t = t + 1;
		
		felix = { 80.0, vt, at, ht, 2.0 };
		
		afficher(t, felix);
		cout << endl;
	
	 
		if (vt == 343) {
		 cout << "Felix depasse la vitesse du son.. " << endl;
		 }
		 
		if (at == 0.5) {
			cout <<  "felix a atteind sa vitesse maximale.. " << endl;
			}
			
	
	 } while (felix.altitude > 0);
	 
	 
  return 0;
}


void afficher(double temps, Sportif sportif)
{
	cout << temps << ", " << sportif.altitude << ", " << sportif.v_chute << ", " << sportif.acceleration;
}

