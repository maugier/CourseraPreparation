#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Sportif{
	double m;
	double v;
	double a;
	double h;
	double s;
};

void afficher(double t, Sportif x){
	cout << t << ",  ";
	cout << x.h << ",  " << x.v << ",  " << x.a;
}

int calcule(Sportif& x, double t0, double v0, double h0, double g){
	double aa(x.s/x.m);
	int t(0);
	int i(0);
	int j(0);
	double terme(exp(-aa*(t-t0)));
	for (t=0, x.h=h0; x.h<=0; ++t){
		terme= (exp(-aa*(t-t0)));
		x.h=(h0-(g/aa)*(t-t0)-((v0-(g/aa))/aa)*(1-terme));
		x.v = (g/aa)*(1-terme)+v0*terme;
		x.a = g-aa*x.v;
		
		do{
		if (x.v >= 343){
			cout << "## Felix a depasse la vitesse du son" << endl;
			++i;
		}
		} while (i<1);
		
		do{
			if (x.a < 0.5){
				cout << "## felix a atteint sa vitesse maximale " << endl;
				++j;
			}
		} while (j<1);
		
		
		
			
	}

	return t;
	
}

int main() {
const double g(9.81);
double v0(0);
double t0(0);
double h0(39000);


Sportif felix = {80, v0, g, h0, 2.0};
afficher(t0, felix);
int t;
t = calcule(felix, t0, v0, h0, g);
afficher(t, felix);



  return 0;
}
