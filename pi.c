#include <stdio.h>
#include <math.h>
#include <assert.h>

#ifndef M_PI
#define M_PI 3.141562953589793238462643383279502884
#endif

static long double trapezoid(long double (*f)(long double), 
                             long double a, long double b, int n);
static long double simpsons_third(long double (*f)(long double), 
                                  long double a, long double b, int n);
static long double simpsons_three_eighth(long double (*f)(long double), 
                                         long double a, long double b, 
                                         int n);
static long double boole(long double (*f)(long double), 
                         long double a, long double b, int n);
static long double f(long double x);

int main(int argc, char *argv[]) {
  if (argc != 1) {
    fprintf(stderr, "Usage: %s\n", argv[0]);
    return 1;
  }
  
  const int maxn = 800000;
  printf("%8s %-16s %-16s %-16s %-16s\n", 
         "N", "Trapezoid", "Simpson1/3", "Simpson3/8", "Boole");
  for (int n = 12; n <= maxn; n *= 2) {
    printf("%8d %0.10Le %0.10Le %0.10Le %0.10Le\n",
           n,
           fabsl(M_PI - trapezoid(f, 0, 1, n)),
           fabsl(M_PI - simpsons_third(f, 0, 1, n)),
           fabsl(M_PI - simpsons_three_eighth(f, 0, 1, n)),
           fabsl(M_PI - boole(f, 0, 1, n)));
  }
  return 0;
}

static long double f(long double x) {
  return 4.0L / (1.0L + x*x);
}

static long double trapezoid(long double (*f)(long double), 
                             long double a, long double b, int n) {
  return 0.0L;
}

static long double simpsons_third(long double (*f)(long double), 
                                  long double a, long double b, int n) {
  assert((n % 2) == 0); // n must be multiple of 2
  return 0.0L;
}

static long double simpsons_three_eighth(long double (*f)(long double), 
                                         long double a, long double b, 
                                         int n) {
  assert((n % 3) == 0); // n must be multiple of 3
  return 0.0L;
}

static long double boole(long double (*f)(long double), 
                         long double a, long double b, int n) {
  assert((n % 4) == 0); // n must be multiple of 4
  return 0.0L;
}
