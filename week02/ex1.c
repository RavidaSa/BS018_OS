#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
  int int_var;
  float float_var;
  double double_var;
  int_var = INT_MAX;
  float_var = FLT_MAX;
  double_var = DBL_MAX;
  printf("%d %d\n",sizeof(int_var), int_var);
  printf("%d %.10e\n",sizeof(float_var),float_var);
  printf("%d %.10e",sizeof(double_var),double_var);
  return 0;
}
