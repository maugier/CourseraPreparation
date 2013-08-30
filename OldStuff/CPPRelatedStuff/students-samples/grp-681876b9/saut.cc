#include <iostream>
#include <cmath>
using namespace std;

struct Sportif {			//On peut utiliser un vector, ou un array...
		double m;
		double v;
		double a;
		double h;
		double surf;
	};
	
void afficher(double duree, Sportif sportif);


int main() {
	
	double const g(9.81);
	double v0(0), t0(0), h0(39000);
	
	Sportif felix {80.0, v0, g, h0, 2.0};
	
	afficher(t0, felix);
	
	for (int t(t0); felix.h > 0; ++t)
	{
		double alpha = felix.surf / felix.m;
		double terme = exp( -alpha * (t - t0));
		
		felix.v = (g / alpha) * (1 - terme) + (v0 * terme);
		felix.h = h0 - ((g / alpha) * (t - t0)) 
				- (((v0 - (g / alpha)) / alpha) * (1 - terme)) ;
		felix.a = g - (alpha * felix.v);
		
		if (felix.h > 0) afficher(t, felix);
		
	}
	
	return 0;
}

void afficher(double duree, Sportif sportif)
{
	cout << duree << ", " << sportif.h << ", " << sportif.v << ", "
		 << sportif.a << endl;
}
