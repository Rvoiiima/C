#include <stdio.h>
#include <math.h>
#define X 500

int main(void) {
	 FILE *data,*gp;
	 char *data_file;
	 int i,m = -2;
	 double dx , x, y ;
	 
	 data_file = "out.dat" ;
	 data = fopen(data_file , "w");
	 
	 dx = 4*M_PI/X;
	 for(i=0;i<=X;i++) {
	 	x = -2*M_PI+i*dx;
	 	y=pow(M_PI,2) * sin(M_PI*(x-m)) /(M_PI*(x-m))*cos(M_PI*(x-m))/(pow(M_PI,2)-4*pow(M_PI,2)*pow((x-m),2));
	 	y = y+1/sqrt(2);
	 	fprintf(data,"%f %f\n",x,y);
	 }
	 fclose(data);
	  
	 gp = popen("/Applications/gnuplot.app/bin/gnuplot -persist","w");
	 fprintf(gp,"set x range [-1.5,1.5]\n");
	 fprintf(gp,"plot \"%s\" with lines linetype 1 title \"sin\"\n",data_file);
	 pclose(gp);
	 
	 return 0;
}
