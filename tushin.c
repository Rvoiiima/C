#include <stdio.h>
#include <math.h>

int main(void) {
	FILE *gp;
	
	gp = popen("/Applications/gnuplot.app/bin/gnuplot -persist","w");
	fprintf(gp, "set xrange[-5:5]\n");
	fprintf(gp,"plot pi**2*sin(pi*x)/(pi*x)*cos(pi*x)/(pi**2-4*pi**2*x**2) lt rgb "black" \n" );
	fprintf(gp,"replot pi**2*sin(pi*x)/(pi*x)*cos(0.75*pi*x)/(pi**2-4*0.75**2*pi**2*x**2) \n");
	fprintf(gp,"replot pi**2*sin(pi*x)/(pi*x)*cos(0.5*pi*x)/(pi**2-4*0.5**2*pi**2*x**2) \n");	
	fprintf(gp,"replot pi**2*sin(pi*x)/(pi*x)*cos(0.25*pi*x)/(pi**2-4*0.25**2*pi**2*x**2) \n");
	fprintf(gp,"replot pi**2*sin(pi*x)/(pi*x)*1/(pi**2) \n");

	getchar();
	pclose(gp);
	
	return 0;
	
}