
#include <stdio.h>

/*
#include <stdlib.h>
// Linux with compiler flag -lm
#include <math.h>

#if __STDC_VERSION__ >= 19901L
	#include <complex.h>
#endif

int math1(void)
{
	double i=5.5, pi;
#if __STDC_VERSION__ >= 19901L
	double complex c;
#endif

	// Calc reel numbers
	fprintf(stdout, "Squareroot of %f = %f\n",i,sqrt(i));
	fprintf(stdout, "Sine of %f = %f\n",i,sin(i));
	fprintf(stdout, "Tangens of %f = %f\n",i,tan(i));
	fprintf(stdout, "Cosine of %f = %f\n",i,cos(i));

#if __STDC_VERSION__ >= 19901L
	// calc complex numbers
	pi = 4*atan(1.0);
	c=cexp(I*pi);
	fprintf(stdout, "%f + %f*i\n",creal(c),cimag(c));
#endif
	return EXIT_SUCCESS;
}

int ex61(void)
{
	return math1();
}
*/
