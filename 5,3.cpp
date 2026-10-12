#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double p(const double x);

int main()
{
    double gp, gk, z;
    int n;

    cout << "gp = "; cin >> gp;
    cout << "gk = "; cin >> gk;
    cout << "n  = "; cin >> n;

    double dg = (gk - gp) / n;

    double g = gp;

    cout << "-----------------------" << endl;
    cout << "| " << setw(6) << "k" << " | " << setw(10) << "z" << " |" << endl;
    cout << "-----------------------" << endl;

    while (g <= gk + 1e-9)
    {
        z = p(2 * g + 1) - pow(p(2 * g - 1), 2) + sqrt(p(g));
        cout << fixed
            << "| " << setw(6) << setprecision(2) << g
            << " | " << setw(10) << setprecision(5) << z << " |" << endl;
        g += dg;
    }

    cout << "-----------------------" << endl;

    return 0;
}

double p(const double x)
{
    if (abs(x) >= 1)
        return (cos(x) + 1) / (sin(x) * sin(x) + exp(x));
    else
    {
        double S = 0;
        int j = 0;
        double a = 1;
        S = a;
        do
        {
            j++;
            double R = -x / j;
            a *= R;
            S += a;
        } while (j < 7);
        return S / exp(x);
    }
}