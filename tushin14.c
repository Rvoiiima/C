#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define X 500

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

double randA2() {
	
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
	 double A[5],A2[5],dx , x, y=0.0,y2=0.0;
	 
	 data_file = "out.dat" ;
	 data = fopen(data_file , "w");
	 
	 

for(int l=0;l<10000;l++){
	 for(k= 0;k<5;k++){
	 	A[k] = randA();
	 	A2[k] =randA2();
	 }
	 
	 dx = 4*M_PI/X;
	 for(i=0;i<=X;i++) {
	 	y=0;
	 	y2=0;
	 	x = -2*M_PI+i*dx;
	 	for(m = -2; m<3 ; m++){
	 		
	 		y += A[m+2]* pow(M_PI,2) * sin(M_PI*(x-m)) /(M_PI*(x-m))*cos(M_PI*(x-m))/(pow(M_PI,2)-4*pow(M_PI,2)*pow((x-m),2)); /*...#1*/  
	 		y2 += A2[m+2]* pow(M_PI,2) * sin(M_PI*(x-m)) /(M_PI*(x-m))*cos(M_PI*(x-m))/(pow(M_PI,2)-4*pow(M_PI,2)*pow((x-m),2)); /*...#1*/
	 }  
	 fprintf(data,"%f %f\n",y,y2);	 
	
     }
}
     fclose(data);
     

     gp = popen("/Applications/gnuplot.app/bin/gnuplot -persist","w");
     fprintf(gp,"set xrange [-2.5:2.5]\n");
     fprintf(gp,"set yrange [-2.5:2.5]\n");
     
	 fprintf(gp,"plot \"%s\" with lines linetype 1 title \"a=1\"\n",data_file);  /*...#2*/


	 pclose(gp);
	 
	
	 return 0;
}
