#include <iostream>
#include <cmath>
using namespace std;

struct Sportif { int masse;
double vitchute;
double acce;
int alt;
double corps;};

void afficher(double t, Sportif s);
Sportif chute(double T, Sportif S);

int main() {
	
	const double g(9.81);
	double v0(0);
	double t0(0);
	int h0(39000);
	Sportif felix = { 80, v0, g, h0, 2.0};
	
	afficher(t0, felix);
	
	return 0;
}

void afficher(double t, Sportif s)
{
	cout << t << ", " << s.alt << ", " << s.vitchute << ", " << s.acce << endl;
}

Sportif chute(double T, Sportif S)
{
	double alpha(0);
	double e(0);
	double t(0);
	Sportif d;
	
	alpha = S.corps / S.masse;
	e = exp( -alpha*(t - T));
	d.vitchute = (S.acce / alpha)*(1 - e) + S.vitchute*e;
	d.alt = S.alt - (S.acce / alpha)*(t - T) - ((S.vitchute - (S.acce / alpha))/alpha)*(1 - e);
	d.acce = S.acce - (alpha*d.vitchute);
	
	return d;
}
