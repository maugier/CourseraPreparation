#include <iostream>
using namespace std;

double afficher(double sportif);

int main() {
double const g(9.81);
double v0(0), t0(0), h0(39000), masse, t, v, a, h, SI;
double terme, alpha;


for (double H(h0); H>= 0; ++t) {
alpha = SI/masse;
terme = ((-alpha)*(t-t0));
v=(g/alpha)*(1-terme) + (v0*terme);
h=h0 - ((g/alpha)*(t-t0)) - (((v0-(g/a))/alpha)*(1-terme));
a= g - (alpha*v);

if (v>340){
	break;
	cout << "## Felix dépasse la vitesse du son" << endl;
}
if (a<0.5){
	break;
	cout << "## Felix a atteint sa vitesse maximale." << endl;
}

if (h<2500){
	SI=25.0;
	cout << "##Felix ouvre son parachute " << endl;
}
}

  return 0;
}


//struct sportif { double masse;
// double v;
// double accel;
// double h;
// double SI;}

//sportif felix;
//sportif felix={80, v0, g, h0, 2};

//double afficher(double sportif)
//{ cout << "Temps de chute : " << t << endl <<
//"Altitude : " << h << endl <<
//"Vitesse : " << vitesse << endl <<
//"Accélération : " << g << endl;}
