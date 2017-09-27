//The following program look for an element in an unsorted vector
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


#define bool int
#define true 1
#define false 0

int *generateRandomArray(int numberOfElements);
int *addArrayPar(int *A,int *B, int numberOfElements);

int main(int argc, char *argv[]){
   int *A, *B, *C;
   int n;
   printf("De cuantos elementos son los arreglos\n");
   scanf("%d",&n);
   A=generateRandomArray(n);
   B=generateRandomArray(n);
   C=addArrayPar(A,B,n);
}

int *generateRandomArray(int numberOfElements){
   int *myArray;
   myArray=malloc(numberOfElements*sizeof(int));
   for (int i=0;i<numberOfElements;i++){
       myArray[i]=rand()%numberOfElements;
   }
   return myArray;
}

int *addArrayPar(int *A, int *B, int numberOfElements){
   int *C;
   C=malloc(numberOfElements*sizeof(int));
   double wtime=0;
   wtime = omp_get_wtime ();
   //#pragma omp parallel for num_threads(3)
   #pragma omp parallel for
   for (int i=0;i<numberOfElements;i++){
        C[i]=A[i]+B[i];
        //printf("C[%d]=A[%d]+B[%d]:::::%d = %d + %d\n", i,i,i,C[i],A[i],B[i]);
   }
  wtime = omp_get_wtime ()-wtime;
  printf("Tiempo de respuesta:%f\n",wtime);
   return C;
}
