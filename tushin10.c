#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define X 5

double randA() {
	rand(); rand();
	int j = rand()%4;
	if(j == 0) { 
	 	return +3/sqrt(10);
	 }else if(j == 1){
	 	return 1/sqrt(10);
	 }else if(j == 2){
	 	return -3/sqrt(10);
	 }else{
	 	return -1/sqrt(10);
	 }
}

int main(void) {
	 FILE *data,*gp;
	 char *data_file;
	 int i,k,m;
	 double A[5],dx , x, y=0.0;
	 
	 data_file = "out.dat" ;
	 data = fopen(data_file , "w");
	 
	 

for(int l=0;l<1000;l++){
	 for(k= 0;k<5;k++){
	 	A[k] = randA();
	 }
	 
	 dx = 4*M_PI/X;
	 for(i=0;i<=X;i++) {
	 	y=0;
	 	x = -2*M_PI+i*dx;
	 	for(m = -2; m<3 ; m++){
	 		
	 		y +=A[m+2]* pow(M_PI,2) * sin(M_PI*(x-m)) /(M_PI*(x-m))*cos(0.5*M_PI*(x-m))/(pow(M_PI,2)-4*pow(0.5,2)*pow(M_PI,2)*pow((x-m),2));  /*...#1*/        }
	 fprintf(data,"%f %f\n",x,y);	 
	
     }
}
     fclose(data);
     

     gp = popen("/Applications/gnuplot.app/bin/gnuplot -persist","w");
     fprintf(gp,"set xrange [-4.5:4.5]\n");
     fprintf(gp,"set yrange [-2:2]\n");
     
	 fprintf(gp,"plot \"%s\" with lines linetype 1 title \"a=0.5\"\n",data_file);  /*...#2*/


	 pclose(gp);
	 
	
	 return 0;
}
