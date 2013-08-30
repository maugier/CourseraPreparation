#include <iostream>
#include <cmath>
using namespace std;

struct Sportif {
	double masse;
	double vitesse;
	double acceleration;
	double altitude;
	double surface_frottement;
};

void afficher ( double t, Sportif s );
void chutesportif ( double t0, Sportif s );

int main() {
	
	const double g (9.81);
	double v0 (0.0);
	double t0 (0.0);
	double h0 (39000.0);
	
	Sportif felix = { 80, v0, g , h0, 2.0 };
	
	
	afficher ( t0, felix );
	
	chutesportif ( t0 , felix );
	

  return 0;
}

void afficher ( double t, Sportif s ){
	cout << t << ", "
		 << s.altitude << ", "
		 << s.vitesse << ", "
		 << s.acceleration << ", "
		 << endl;
	 }

void chutesportif ( double t0 , Sportif s ){
	double g (9.81);
	double alpha ( s.surface_frottement / s.masse );
	double t (0.0);
	double vt ( s.vitesse );
	double ht ( s.altitude );
	double at ( s.acceleration );
	double terme ( exp(-alpha*(t-t0)));
	
	do {
		++t;
		vt = (g/alpha)*(1-terme)+(s.vitesse)*terme;
		ht = s.altitude - (g/alpha)*(t-t0)-((s.vitesse-(g/alpha))/alpha)*(1-terme);
		
	
	Sportif chute = { s.masse , vt , at, ht, s.surface_frottement };
	
	afficher ( t, chute );
	
	} while ( ht > 0 );

	}
