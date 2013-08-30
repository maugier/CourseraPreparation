#include <iostream>
#include <cmath>
using namespace std;

struct Sportif{
	double masse;
	double v_chute;
	double a;
	double alt;
	double frot;
};


void afficher(Sportif& x,  double t);
void evolution(Sportif& x, double t);


int main() {
	
	const double g(9.81);
	double v0(0);
	double t0(0);
	double h0(39000);
	double t_chute;

	Sportif felix = {80, g*t - v0, g, h0, 2};

afficher(felix, 0);

evolution(felix);


  return 0;
}

void afficher (Sportif& x,  double t){
cout << t << ", ";
cout << x.alt - t * x.a << ", ";
cout << x.a *t + x.v_chute << ", ";
cout << x.a << ", " << endl;
};

void evolution(Sportif& x){

	
double alpha(x.frot/x.masse);
double terme(exp(-alpha(t-t0)));


for(int i = h0; i = h0; --i){
	double vt(g/alpha(1-terme+v0*terme));
	double ht(h0-g/alpha*(t-t0)- ((v0-g/alpha)/alpha)*(-terme));
	double at(g-alpha*(vt));
	cout << i<< ", " << ht << ", " << x.a << ", "<<  g << endl;
	if(vt=343){
		cout<< "felix depasse la vitesse du son" << endl;}
		//se {}
	}
	
}
