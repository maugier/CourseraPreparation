#include <iostream>
using namespace std;

typedef double Sportif;
void afficher(double t, Sportif s);

int main() {
	
double const g(9.81);
double v0(0.0);
double t0(0.0);
double h0(39000.0);

Sportif felix {
double masse(80.0);
double surface(2.0);
double h(h0);
double v(v0);
double a(g);
}
cout << afficher(t0, felix) << endl;

  return 0;
}

void afficher(double t(0.0), Sportif double& s) {
	cout << "temps: " << t << ", altitude: " << s.h << ", vitesse: " << s.v << ", acceleration: " << a.v << endl;

}

