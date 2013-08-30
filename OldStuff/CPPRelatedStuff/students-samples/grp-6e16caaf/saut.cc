#include <iostream>
#include <cmath> 
using namespace std;


int main() 
{

const double g(9.81);
double v0(0);
double t0(0); 
double h0(39000);

struct Sportif 
{
	double masse;
	double vitesseChute;
	double acceleration;
	double altitude;
	double surface;
		}; 

Sportif felix = {80, 0.0, g, 3900, 2.0.};

void afficher (double, Sportif)
{
	cout << "temps: " << t0 << endl << "altitude: " <<felix.altitude << endl << "vitesse: " << felix.vitesseChute << endl << "acceleration: " << felix.acceleration << endl;
	}

afficher(felix);

double a = felix.surface/felix.masse;
int t (0);
double terme = exp(-a*(t- t0));
double v = (g/a)*(1 - terme) + v0*terme;
double h = h0 - (g/a)*(t- t0) - ((v0 - (g/a))/a)*(1 - terme);
double a = g - a*v; 

while ( h > = 0)
{
	cout << t << "   "<< h << "   " << v << "   " << a;
	
	double v2 (0);
	if (v2 > 343) 
	{
		cout << "## Felix depasse la vitesse du son";
		v2=0;
		}
	
	t++;
	}

  return 0;
}
