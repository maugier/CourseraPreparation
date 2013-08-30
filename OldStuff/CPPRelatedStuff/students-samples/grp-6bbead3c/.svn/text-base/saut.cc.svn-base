#include <iostream>
#include <cmath>
using namespace std;


struct Sportif {
	
	double masse;
	double vitesse;
	double acceleration;
	double alt;
	double surface;
	
	};

void afficher(double temps, Sportif s);


int main() {

const double g(9.81);
double v0(0);
double t0(0);
double h0(39000);

Sportif felix = { 80, v0, g, h0, 2.0};

afficher(t0,felix);

cout << endl;

int t(0);

do{

double a(felix.masse/felix.surface);
double terme(-a*exp(t-t0));
felix.vitesse((g/a)*(1-terme) + v0*terme);
felix.acceleration( g - a*vt );
felix.alt(h0-(g/a)*(t-t0)- ((v0-g/a)/a)*(1-terme));
	
	cout<< t << ", " << felix.alt << ", "
		<< felix.vitesse << ", " << felix.acceleration << endl;
		
	++t;
	
	if (felix.vitesse > 343){
		
		cout << "## Felix depasse la vitesse du son"
		}
	}
while(t < 5.0);

  return 0;
}


void afficher(double temps, Sportif s){
	
	
	
	cout << temps << ", " << s.alt << ", " << s.vitesse << ", " << s.acceleration ;
	
	}
