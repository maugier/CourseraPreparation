#include <iostream>
using namespace std;

struct sportif{double masse; double vitesse; double acceleration; double altitude; double surface;};
void afficher(double t, sportif s){
	cout<< t<<", "<< s.altitude<<", "<< s.vitesse<<", "<< s.acceleration;
}
double alpha(sportif s){
	double alpha(s.surface/s.masse);
	return alpha;
}
double ter(double t, double a, double t0){
	double terme(-a*(t-t0));
	return terme;
}
double vt(double a, double g, double terme, double v0){
	double vt(g/a*(1-terme)+(v0*terme));
	return vt;
}
double ht(double a, double g, double h0, double t, double t0, double v0, double terme){
	double ht(h0-g/a*(t-t0)-(v0-g/a)/a*(1-terme));
	return ht;
}
double at(double g, double a, double vt){
	double at(g-a*vt);
	return at;
}
void alt(sportif s, double g, double h0, double t0, double v0){
	double i;
	for (i=0; ht>0; ++i){
		cout<< ht(alpha(s), g, h0, i, t0, v0, ter(i, alpha(s), t0));
	}
}	

	


int main() {
	double const g(9.81);
	double v0(0), t0(0), h0(39000), m, t(0);
	sportif felix={80, v0, g, h0, 2};
	afficher(t, felix);
	alt(felix, g, h0, t0, v0);
	
	
	


	return 0;
}
