#include<stdio.h>
#include <time.h>

double main(){
   clock_t before_ij, after_ij, before_ji, after_ji;
   time_t t;
   srand((unsigned) time(&t));
   char *p;
   double **A;
   double *b;
   double *x;
   int n = 1024;

   while(1){

   /* 2D array declaration*/
   A = (double **)malloc(n * sizeof(double*));
   b = (double *)malloc(n * sizeof(double));
   x = (double *)malloc(n * sizeof(double));

   /*Counter variables for the loop*/
   int i, j;
   int randint;
   for(i=0; i<n; i++) {
      A[i] = (double *)malloc(n * sizeof(double));
      for(j=0;j<n;j++) {
         A[i][j] = rand();
      }
   }

   for(i=0; i<n; i++) {
      b[i] = rand();
   }

   for(i=0; i<n; i++) {
      x[i] = 0;
   }

   before_ij = clock();
   double aux; 
   for(i=0; i<n; i++) {
      for(j=0;j<n;j++) {
         x[i] += A[i][j]*b[j];
      }
   }
   after_ij = clock();

   before_ji = clock();
   for(j=0; j<n; j++) {
      for(i=0;i<n;i++) {
         x[i] += A[i][j]*b[j];
      }
   }
   after_ji = clock();


   printf("%d;%.6f;%.6f\n", n, ((double)(after_ij - before_ij)) / CLOCKS_PER_SEC, ((double)(after_ji - before_ji)) / CLOCKS_PER_SEC);
   
   for(i=0; i<n; i++) {
      free(A[i]);
   }
   free(b);
   free(x);

   n = n*2;
   }

   return 0;
}