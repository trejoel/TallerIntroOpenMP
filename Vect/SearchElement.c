//The following program look for an element in an unsorted vector
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

int *generateRandomArray(int numberOfElements);
int seqlookElement(int *myArray, int numberOfElements, int x);
void printMyArray(int *myArray, int numberOfElements);

int main(int argc, char *argv[]){
   int *myArray,n,y,position;
   printf("De cuantos elementos\n");
   scanf("%d",&n);
   myArray=generateRandomArray(n);
   printf("A buscar?\n");
   scanf("%d",&y);
   position=seqlookElement(myArray,n,y);
   if (position>=0){
   	 printf("Elemento encontrado en posicion %d\n\n\n\n",position); 
   }
   else{
   	 printf("Elemento no encontrado\n\n\n\n"); 
   }
  // printMyArray(myArray,n);
}

int *generateRandomArray(int numberOfElements){
   int *myArray;
   int tid, nthreads, begin, end, i,load;
   myArray=malloc(numberOfElements*sizeof(int));
  for ( i=0;i<numberOfElements;i++){
     myArray[i]=rand()%numberOfElements;
   }      
   return myArray;
}

int seqlookElement(int *myArray, int numberOfElements, int x){
  int isIt=-1;
  double wtime=0;
  bool found=false;
   for (int i=0;(i<numberOfElements && !found);i++){
      if (myArray[i]==x){
          isIt=i;
      }
   }
   printf("El secuencial tardo %f en encontrar\n", wtime);  
   return isIt;
  }


  void printMyArray(int *myArray, int numberOfElements){
   for (int i=0;i<numberOfElements;i++){
   	  printf("%d ", myArray[i]);
   }
   printf("\n\n\n");
}