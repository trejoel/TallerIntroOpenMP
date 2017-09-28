//The following program look for an element in an unsorted vector
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

int *generateRandomArray(int numberOfElements);
void minMaxElementSeq(int *A, int numberOfElements);
void printArray(int *A, int n);

int main(int argc, char *argv[]){
   int *A, *B;
   int n;
   printf("De cuantos elementos son los arreglos\n");
   scanf("%d",&n);
   A=generateRandomArray(n);
   printArray(A,n);
   minMaxElementSeq(A,n);
}

int *generateRandomArray(int numberOfElements){
   int *myArray;
   myArray=malloc(numberOfElements*sizeof(int));
   for (int i=0;i<numberOfElements;i++){
       myArray[i]=rand()%numberOfElements;
   }
   return myArray;
}

void printArray(int *A, int n){
   
    printf("Arreglo=");
   for (int i=0;i<n;i++){
       printf("%d  ",A[i]);
   }
   printf("\n");
}

void minMaxElementSeq(int *A, int numberOfElements){
   int minimo,maximo;
   minimo=A[0];
   maximo=A[0];
   double wtime=0;
   //#pragma omp parallel for reduction(min:minimo) reduction(max:maximo)
   for (int i=0;i<numberOfElements;i++){
        //printf("C=%d+A[%d]*B[%d]\n", C, i,i);
        if (A[i]<minimo){
          minimo=A[i];
        }
        if (A[i]>maximo){
          maximo=A[i];
        }
   }
   printf("El menor es:%d. El mayor es:%d\n", minimo, maximo);
   printf("Tiempo de respuesta secuencial:%f\n",wtime);
}

