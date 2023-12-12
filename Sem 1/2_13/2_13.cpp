
#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
  float a,b,c,d,x_1,x_2;
 
  cin >> a >> b >> c;
  
  d = b * b - 4 * a * c;
  if (d > 0)
  {
    x_1 = ((-b) + sqrt(d)) / (2 * a);
    x_2 = ((-b) - sqrt(d)) / (2 * a);
    cout << "x_1 = " << x_1 << endl;
    cout << "x_2 = " << x_2 << endl;
  }
  if (d == 0)
  {
    x_1 = -(b / (2 * a));
    cout << "x_1 = x_2 = " << x_1 << endl;
  }
  if (d < 0) {
    cout << "D < 0, Действительных корней не существует";
    }
    return 0;
}
