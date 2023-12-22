
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    
    float a, b, c;
    float fA, fB, fC;
    double eps = 0.000001;
    
    a = 0;
    b = 2;
    
    while (b-a > eps)
    {
        c = (a + b) / 2;
        fA = (0.25*pow(a, 3) + a - 1.2502);
        fB = (0.25*pow(b, 3) + b - 1.2502);
        fC = (0.25*pow(c, 3) + c - 1.2502);
        if (fA * fC < 0) { b = c; }
        else if (fC * fB < 0) { a = c; }
        else { cout << "Error!" << endl; }
    }
    cout << "Корни по методу половинного деления: " << a << "; " << b << endl;
    
    
    
    // f(x) = 0.25*x^3 + x - 1.2502;
    // f'(x) = 0.75x^2 + 1;
    // f''(x) = 1.5x;
    // [0, 2]
    float x, xPrev;
    
    // f(b) * f''(b) > 0
    // (2+2-1.2502) * (1.5*2) > 0 => x0 = b;
    x = 2;
    xPrev = 0;  // x(n-1)
    
    while(abs(x - xPrev) > eps)
    {
        xPrev = x;
        // x(i-1) - f(x(i-1)) / f'(x(i-1))
        x = xPrev - ( (0.25*pow(xPrev, 3) + xPrev - 1.2502) / (0.75*pow(xPrev, 2) + xPrev) );
    }
    cout << "Корень по методу Ньютона: " << x << endl;
    
    
    
    // f(x) = 0.25*x^3 + x - 1.2502;
    // f'(x) = 0.75x^2 + 1;
    // f''(x) = 1.5x;
    // [0, 2]
    // ф(x) = x + λ(x^3 - x - 1)
    // -1/r < λ < 0, если f'(x) > 0
    // 0 < λ < 1/r, если f'(x) < 0
    // r = max(|f'(a)|, |f'(b)|)
    // r = max(|1|, |4|) = 4
    // f'(x) > 0 => -1/r < λ < 0
    // λ = -1/10 = -0.1
    double lambda = -0.1; // -1/10
    x = 2;
    xPrev = 0;
    
    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = lambda * (0.25*pow(xPrev, 3) + xPrev - 1.2502) + xPrev;
    }
    cout << "Корень по методу итераций: " << x << endl;
    return 0;
}
