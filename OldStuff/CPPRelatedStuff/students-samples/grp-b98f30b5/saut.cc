#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<double> Sportif;


void afficher(const double& temps, const Sportif& S);
double terme(const double& alpha,const double& t, const double& t0);
double v(const double& alpha, const double& g, const double& v0, const double& t, const double& t0);
double h(const double& alpha, const double& g, const double& v0, 
			const double& t, const double& t0, const double& h0);
double a(const double& alpha, const double& g, const double& v0,
			const double& t, const double& t0);


int main() {
	const double g(9.81);
	double v0(0), t0(0), h0(39000);
	double v(0), t(0), h(0);
	
	Sportif felix {80, 2.0, h0, v0, g};
	
	for(size_t t(0); t < 138; ++t) {
		felix[2] = h(felix[1], g, v0, t, t0, h0);
		felix[3] = v(felix[1], g, v0, t, t0);
		felix[4] = a(felix[2], g, v0, t, t0);
		afficher(t, felix);
	}
	//afficher(t0, felix);


  return 0;
}

void afficher(const double& temps, const Sportif& S) {
	cout << temps << endl;
	cout << S[2] << endl;
	cout << S[3] << endl;
	cout << S[4] << endl;
}

double terme(const double& alpha,const double& t, const double& t0){
	double terme;
	terme = exp(-alpha*(t-t0));
	return alpha;
}

double v(const double& alpha, const double& g, const double& v0, 
			const double& t, const double& t0) {
	double v;
	v = g/alpha*(1-terme(alpha, t, t0) + v0*terme(alpha, t, t0));
	return v;
}

double h(const double& alpha, const double& g, const double& v0, 
			const double& t, const double& t0, const double& h0) {
	double h;
	h=(h0 - g/alpha*(t-t0)-((v0-g/alpha)/alpha)*(1-terme(alpha, t, t0)));
	return h;	
}
			
double a(const double& alpha, const double& g, const double& v0,
			const double& t, const double& t0) {
	double a;
	a = g - alpha*v(alpha, g, v0, t, t0);
	return a;
}
			
