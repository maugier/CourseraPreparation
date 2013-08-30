#include <iostream>
#include <cmath>
using namespace std;

struct Sportif {
	double masse;
	double vitesse;
	double accel;    // accélération
	double altitude;
	double surface;  // surface du corps exposée aux frottements
}

void afficher(const double&, const Sportif&);

int main()
{
	constexpr double g(9.81);
	double v0(0.0);
	double t0(0.0);
	double h0(39000.0);
  
	Sportif felix = { 80.0, v0, g, h0, 2.0 };
	
	double alpha = (felix.surface) / (felix.masse);
	double t(0.0);
	bool son(false);
	
	do {
		double terme = exp(-alpha * (t - t0));
		
		felix.vitesse = (g / alpha) * (1 - terme) + v0 * terme;
		felix.altitude = h0 - (g / alpha) * (t - t0)
				         - ((v0 - (g / alpha)) / alpha) * (1 - terme);
		felix.accel = g - alpha * v;
		
		afficher(t, felix);
		cout << endl;
		
		if ((felix.vitesse > 343.0) and (!son)) {
			cout << "## Felix dépasse la vitesse du son" << endl;
			son = true;
		}
		++t;
	} while (felix.altitude <= h0);

	return 0;
}

// ---------------------------------------------

void afficher(const double& t, const Sportif& p)
{
	cout << t << ", " 
         << p.altitude << ", " 
         << p.vitesse << ", "
         << p.accel;
}
