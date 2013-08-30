#include <iostream>
#include <cmath>
using namespace std;

struct sportif 
	{
		double m;
		double v;
		double a;
		double h;
		double s;
	};
void afficher (double, sportif);


int main() {
	const double g(9.81);
	double v0(0),t0(0),h0(39000);
	sportif felix = {80, v0, g, h0, 2.0};
	double alph(0);
		alph = felix.s/felix.m;
	double h(0);
	for (double t(0); h >= 0; ++t)
	{
	double ter(0);
		ter = exp(-alph*(t-t0));
	double v(0);
		v = g/alph*(1-ter)+ v0*ter;
		h = h0 - g/alph * (t-t0) - ((v0-(g-alph))/alph)*(1-ter);
	double a(0);
		a = g - alph*v;
		felix = {80, v, a, h, 2.0};
		afficher (t, felix);
	}
  return 0;
}

void afficher (double t, sportif x)
{
	cout << t << ", " << x.h << ", " << x.v << ", " << x.a << endl;
}
