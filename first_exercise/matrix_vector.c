#include<stdio.h>
#include <time.h>

RAND_MAX = 10;

double main(int argc, char *argv[]){
   time_t t;
   srand((unsigned) time(&t));
   char *p;
   int n = strtol(argv[1], &p, 10);

   /* 2D array declaration*/
   double **A = (double **)malloc(n * sizeof(double*));
   double *b = (double *)malloc(n * sizeof(double));
   double *x = (double *)malloc(n * sizeof(double));

   /*Counter variables for the loop*/
   int i, j;
   int randint;
   for(i=0; i<n; i++) {
      A[i] = (double *)malloc(n * sizeof(double));
      for(j=0;j<n;j++) {
         A[i][j] = rand()%10;
         printf("%f ", A[i][j]);
      }
      printf("\n");
   }

   printf("\n");
   for(i=0; i<n; i++) {
      b[i] = rand()%10;
      printf("%f ", b[i]);
   }

   printf("\n\n");
   double aux; 
   for(i=0; i<n; i++) {
      aux = 0;
      for(j=0;j<n;j++) {
         aux += A[i][j]*b[j];
      }
      x[i] = aux;
      printf("%f ", aux);
   }

   double *aux_vector = (double *)malloc(n * sizeof(double));
   for(i=0; i<n; i++) {
      aux_vector[i] = 0;
   }

   for(j=0; j<n; j++) {
      for(i=0;i<n;i++) {
         aux_vector[i] += A[i][j]*b[j];
      }
   }

   printf("\n\n");
   for(i=0; i<n; i++) {
      printf("%f ",  aux_vector[i]);
   }

   return 0;
}