#include <iostream>
#include <cmath>
using namespace std;

struct Sportif {
						double masse;
						double vchute;
						double acc;
						double alt;
						double surface;
	} ;
	
void afficher (const double& t,const Sportif& s);
double terme (double alpha, double t, double t0)
{
	return (exp(-alpha*(t-t0)));
};

int main() {

	const double g(9.81);
	double v0(0.0), t0(0.0), h0(39000.0);
	
	Sportif felix = { 80.0, v0, g, h0, 2.0 };
	
	afficher (t0, felix);
	
	double v(0.0), h(0.0), a(0.0), alpha(0.0);
	
	for (double t(0.0); felix.alt >= 0; ++t)
	{
		alpha = felix.surface/felix.masse;
		
		v = g/alpha*(1-terme(alpha, t, t0)) + v0*terme(alpha, t, t0);
		
		h = h0 - g/alpha * (t-t0) - (v0 - g/alpha)*(1-terme(alpha, t, t0))/alpha; 
		
		a = g - alpha*v;
		
		felix.alt -= v*t ;
		
		afficher (t, felix);
	}

  return 0;
}


void afficher (const double& t,const Sportif& s)
{
		cout << t << ", " << s.alt << ", " << s.vchute << ", " << s.acc << endl;
}


