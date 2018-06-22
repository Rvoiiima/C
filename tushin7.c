#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define X 500

double randA() {
	int j = rand()%2;
	if(j == 0) { 
	 	return +1/sqrt(2);
	 }else {
	 	return -1/sqrt(2);
	 }
}

double randA2() {
	rand(); rand();
	int j = rand()%2;
	if(j == 0) { 
	 	return +1/sqrt(2);
	 }else {
	 	return -1/sqrt(2);
	 }
}

int main(void) {
	 FILE *data,*gp;
	 char *data_file;
	 int i,k,m;
	 double A[5],A2[5],dx , x, y=0.0,y2=0.0;
	 /*I*/
	 data_file = "outIQ.dat" ;
	 data = fopen(data_file , "w");
	 

for(int l=0;l<900;l++){
	
	 for(k= 0;k<5;k++){
	 	A[k] = randA();
	 	A2[k] = randA2();
	 }
	 
	 dx = 4*M_PI/X;
	 for(i=0;i<=X;i++) {
	 	y=0;
	 	y2=0;
	 	x = -2*M_PI+i*dx;
	 	for(m = -2; m<3 ; m++){
	 		
	 		y += A[m+2]* pow(M_PI,2) * sin(M_PI*(x-m)) /(M_PI*(x-m))*cos(0.5*M_PI*(x-m))/(pow(M_PI,2)-4*pow(0.5,2)*pow(M_PI,2)*pow((x-m),2));	 		y2 += A2[m+2]* pow(M_PI,2) * sin(M_PI*(x-m)) /(M_PI*(x-m))*cos(0.5*M_PI*(x-m))/(pow(M_PI,2)-4*pow(0.5,2)*pow(M_PI,2)*pow((x-m),2));        }
	 fprintf(data,"%f %f\n",y,y2);	 
	
     }
}
     fclose(data);
     
     gp = popen("/Applications/gnuplot.app/bin/gnuplot -persist","w");
     fprintf(gp,"set xrange [-2.0:2.0]\n");
     fprintf(gp,"set yrange [-2.0:2.0]\n");
     
	 fprintf(gp,"plot \"%s\" with lines linetype 1 title \"a=0.5\"\n",data_file);


	 pclose(gp);
	 
	 return 0;
}
