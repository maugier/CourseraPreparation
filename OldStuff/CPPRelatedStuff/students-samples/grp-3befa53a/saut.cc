#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Structures
struct sportif {double masse;
double vitesse;
double acceleration;
double altitude;
double surface;
}

//fonctions
void afficher(double, sportif);

void calcul(sportif tom);


int main() {

double const g(9.81);

double v0(0), t0(0), h0(39000);

sportif felix = {80, v0, g, h0, 2.0} ;

afficher(t0, felix);

calcul(felix);

}
  return 0;
}

//Fonctions
void afficher(double temps, sportif Tom)
{
    cout << temps << ", " << Tom.altitude << ", " << Tom.vitesse << ", "
    << Tom.acceleration << endl;
}

void calcul(sportif tom)
{
    for (int t(t0) : t ; t++ )
{
    double v(v0) , h(h0), a(a0);

    double alpha, terme;
    alpha = tom.surface / tom.masse ;
    terme = exp((- alpha)*(t-t0)) ;

    while (a > 0)
    {
        sportif tombis;

        v = (g/alpha) * (1-terme) + v0 * terme:

        h = h0 - (g/alpha) * (t - t0) - ((v0 - g/alpha)/alpha) ;

        a = g - alpha*v

        tombis.vitesse = v;
        tombis.altitude = h;
        tombis.altitude = a;

        afficher(t, tombis);

        if (v > 343) {cout << "Felix passe le mur du son" << endl:}

        if (a < 0.5) ¢cout << "vitesse max" << endl;}

            }
}
