#include <iostream>
#include <complex>
using namespace std;

double sum(double a , double b){
    return a-b;
}

complex<double> sum(complex<double> a, complex<double> b){
    return a-b;
}


int main()
{
    complex< double > z1( 1.0, 2.0 );
    complex< double > z2( 2.0, 1.0 );
    double k1 = 4.5, k2 = 5.5;
    cout << sum(k1,k2) << endl;
    cout << sum(z1,z2) << endl;
    
    
}
