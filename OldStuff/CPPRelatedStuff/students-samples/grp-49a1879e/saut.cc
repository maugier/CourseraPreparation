#include <iostream>
using namespace std;

void afficher (double t , Sportif x);

int main() {

double v0 (0.0);
double t0(0.0);
double h0 (39000);
const double g (9,81);


typedef struct Sportif;

Sportif felix {
	double M;
	double S;
	double V;
	double H;
	double A;
};
Soprtif felix= { 80 ; 2.0 ; v0 ; h0 ; g ;};

 cout << afficher ( double t0, Sportif felix) << endl;

  return 0;
}

void afficher ( double t , sportif x){
 cout << "le temps est " << t << endl;
cout << "altitude : " << x.H << endl;
cout << "vitesse : " << x.V << endl;
cout << "acceleration " << x.A << endl;
}
