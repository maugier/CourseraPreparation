#include <iostream>
#include <array>
#include <cmath>
using namespace std;

constexpr int dim(5);
typedef array<double, dim> Sportif;

void affiche(Sportif felix, double t);


int main() {
constexpr double g(9.81);
double v0(0.0);
double t0(0.0);
double h0(39000.0);


Sportif felix = {80, v0, g, h0, 2.0};
affiche(felix, t0);

double alpha((felix[4])/(felix[0]));


Sportif felix2= felix; // sportif en cours de chute, dont les paramètres vont varier.
double t(0.0);


 while (felix2[3]>0.0) {
	double terme(exp((-alpha)*(t-t0)));
	felix2[1]= (g/alpha)*(1-terme) + (v0*terme);
	felix2[3]= h0- (g/alpha)*(t-t0) - ((v0-(g/alpha))/alpha)*(1-terme);
	felix2[2] = g - (alpha * felix2[1]);
	
	bool vcontrole(true);
	if ((felix[1] >= 343.0) and (vcontrole==true)) {
		cout << "## Felix dépasse la vitesse du son" << endl;
		vcontrole = false; }
		
	bool acontrole(true);
		if ((felix[2] <= 0.5) and (acontrole==true)) {
		cout << "## Felix atteint sa vitesse maximale" << endl;
		acontrole = false; }
		
	bool controleparachute(false);
		if ((controleparachute==false ) and( felix[3] <2500)) {
		}
		
		
	affiche(felix2, t);
	t=t+1;
};


	
  return 0;
}

void affiche(Sportif felix, double t){
	cout << "Votre sportif au temps " << t << " est à l'altitude " << felix[3] << ", de vitesse " << felix[1] << " et d'accélération " << felix[2] << endl;
}
