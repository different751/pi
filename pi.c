/*

Name: Tyler Coy
Date: 11/6/16
Programming Assignment: Pi aproximations
Class: CS330
*/


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
         "N", "Trapezoid", "Simpson1/3", "Simpson3/8", "Boole");//print table headings
  for (int n = 12; n <= maxn; n *= 2) {
    long double trap = fabsl(M_PI - trapezoid(f, 0, 1, n));
    printf("%8d %0.10Le %0.10Le %0.10Le %0.10Le\n",//print values
           n,
           trap,
           fabsl(M_PI - simpsons_third(f, 0, 1, n)),
           fabsl(M_PI - simpsons_three_eighth(f, 0, 1, n)),
           fabsl(M_PI - boole(f, 0, 1, n)));


  }
  return 0;
}

static long double f(long double x) {
  return 4.0L / (1.0L + x*x); //return value for f(x)
}




static long double trapezoid(long double (*f)(long double),
                             long double a, long double b, int n) {


        assert(a<b);    //check if a is smaller then b in order to continue
        const double h = (b-a)/n; //initialize h value
        double sum = 0.0;

        for (int i = 1; i<n; i++) //for loop for the sum of f(x)s
                sum += f(a+h*i);
        return h*((f(a) + f(b))/2 + sum); //return the formula for the trapizoid rule






}





static long double simpsons_third(long double (*f)(long double),
                                  long double a, long double b, int n) {
  assert(n % 2 == 0); // n must be multiple of 2


        long double h = (b - a)/n; //initialize h value
        long double h2=h+h; //initialize h2 to fix rounding errors
        long double x=a+h; //initialize x to fix rounding errors
long double sum1 = 0.0;
        for (int i = 1; i < n; i += 2){  //summation for the first f(x)
                sum1 += f(x);
                x+=h2;

        }
long double sum2 = 0.0;
x=a+h+h; //reset x value
for (int d = 2; d < n; d += 2){ //second summation for f(x)
sum2 += f(x);
x+=h2;

}
return (h/3)*((f(a) + f(b)) + 4*sum1 + 2*sum2); //return the vaule
}




static long double simpsons_three_eighth(long double (*f)(long double),
                                         long double a, long double b,
                                         int n) {
  assert((n % 3) == 0); // n must be multiple of 3

        long double h = (b - a)/(n);  //initalize h value
        long double x = a + h;  //intialize x value to fix rounding errors
        long double sum1=0.0;
        long double sum3=0.0;

        long double h3 = h+h+h;
        for(int i=1;i<n;i+=3){  //summation for both f(x) and f(x+h)

                //sum1+=f(a+h*i);
                sum1+=f(x)+f(x+h);
                //sum2+=f(x+h);
                x+=h3;

        }


        x=a+h+h+h; //reset x value
        for(int v=3;v<n;v+=3){  //summation for next f(x)

                //sum3+=f(a+h*v);
                sum3+=f(x);
                x+=h3;

        }


        return(((3*h)/8)*((f(a)+f(b)) + 3*(sum1) + 2 * sum3));  // return value

}





static long double boole(long double (*f)(long double),
                         long double a, long double b, int n) {
  assert((n % 4) == 0); // n must be multiple of 4


        long double h =(b-a)/(n);  //initialize h value
        long double sum1=0.0;
        long double sum2=0.0;
        long double sum3=0.0;

        for(int i=1;i<n;i+=2){  //summation for the first f(x)

        sum1+=f(a+h*i);

        }


        for(int v=2;v<n;v+=4){  //summation for the second f(x)

        sum2+=f(a+h*v);

        }


        for(int c=4;c<n;c+=4){  //summation for the thrid f(x)

        sum3+=f(a+h*c);


        }



        return ((2*h)/45)*(7*(f(a)+f(b)) + (14 * sum3) + (32 * sum1) + (12 * sum2));  //return value




}
