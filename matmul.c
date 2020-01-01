#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define N 1000
#define G 100000000

double a[N][N];
double b[N][N];
double c[N][N];

void generate_matrix(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			a[i][j] = (double)rand()/RAND_MAX;
			b[i][j] = (double)rand()/RAND_MAX;
		}
	}
}

int main(void){
	double start,time;

	generate_matrix();

	start = omp_get_wtime();

	for(int i=0;i<N;i++){
		for(int k=0;k<N;k++){
			for(int j=0;j<N;j++){
				c[i][j] = a[i][k] * b[k][j];
			}
		}	
	}

	time = omp_get_wtime() - start;
	printf("%lf\n\n",time);
	double gflops = ((2 * (N*N*N))/time) / G;

	printf("%lf",gflops);
}
