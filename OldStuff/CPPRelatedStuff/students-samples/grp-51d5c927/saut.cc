#include <iostream>
#include <cmath>
using namespace std;

struct Sportif{
	double m;
	double v;
	double a;
	double h;
	double s;
	};

void afficher(Sportif const& z, double t);
void evolution(Sportif& z, int v0, int h0, int g, int t0);
double vitesse(Sportif const& z, int t, int v0, int h0, int g, int t0);
double hauteur(Sportif const& z, int t, int v0, int h0, int g, int t0);
double acceleration(Sportif const& z, int t, int v0, int h0, int g, int t0);
double terme(Sportif const& z, int t, int v0, int h0, int g, int t0);

int main() {
	const double g(9.81);
	double v0(0.);
	double t0(0.);
	double h0(39000.);
	Sportif felix = {80, v0, g, h0, 2.0};
	evolution(felix, v0, h0, g, t0);
	
  return 0;
}

void afficher(Sportif const& z, double t){
	cout << t << " , " << z.h << " , " << z.v << " , " << z.a << endl;
	}

void evolution(Sportif& z, int v0, int h0, int g, int t0){
	int t(0);
	while(z.h>0){
		z.v =vitesse(z, t, v0, h0, g, t0);
		z.h =hauteur(z, t, v0, h0, g, t0);
		z.a =acceleration(z, t, v0, h0, g, t0);
		t = t+1;
		afficher(z, t);
		}
	}

double vitesse(Sportif const& z, int t, int v0, int h0, int g, int t0){
	double v;
	v = g*z.m/z.s *(1-terme(z,t, v0, h0, g, t0)) + v0 * terme(z,t, v0, h0, g, t0);
	return v;
	}

double acceleration(Sportif const& z, int t, int v0, int h0, int g, int t0){
	double a;
	a = g - z.s/z.m * vitesse(z, t, v0, h0, g, t0);
	return a;
	}

double hauteur(Sportif const& z, int t, int v0, int h0, int g, int t0){
	double h;
	h = h0 - g*z.m/z.s * (t-t0) - (v0-g*z.m/z.s)*z.m/z.s * (1- terme(z,t,v0,h0,g,t0));
	return h;
	}

double terme(Sportif const& z, int t, int v0, int h0, int g, int t0){
	double k;
	k= exp(-(z.s/z.m)*(t-t0));
	return k;
	}
