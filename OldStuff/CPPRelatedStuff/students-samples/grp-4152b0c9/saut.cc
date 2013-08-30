#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void afficher(double, double, double, double, double, int);



int main() {
	double const g(9.81);
	double v0, t0, h0, alpha, t, v, h, a;
	double terme;
	//g = 9.81;
	v0 = 0;
	t0 = 0;
	h0 = 39000;
	t = t0;
	v = v0;
	h = h0;
	struct Sportif {   //structure sportif
		double v0, t0, h0;
		int const poids;
		double surface;
		};

	Sportif felix = {v0, t0, h0, 80, 2.0};
	afficher(felix.v0, felix.t0, felix.h0, g, felix.surface, felix.poids );
	alpha = felix.surface/felix.poids;
	terme = exp(-alpha*(t-t0));
	/*while (h => 0) {
	
		}*/
	return 0;
}


void afficher(double v0, double t0, double h0, double g, double surface, int poids) {	
	cout << t0 << ", " << h0 << ", " << v0 << ", " << g << endl;
}

