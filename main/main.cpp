#include "Monom.h"

int main()
{
  TMonom a(new double[3]{ 1,2,3 }, 3, 1);
  TMonom b(new double[3]{ 3,2,1 }, 3, 1);
  TMonom c;
  c = a * b;
  cout << c;
  return 0;
}
