
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int numberthreads, id_threads;

/* Fork a team of threads giving them their own copies of variables */
//Las variablws nthreads y tid son privadas para cada thread
#pragma omp parallel private(numberthreads, id_threads)
  {
  
  id_threads = omp_get_thread_num();
  if (id_threads==0){
      numberthreads=omp_get_num_threads();     
      printf("El numero de cores es %d:\n",numberthreads);
  }

  printf("Hola mundo del thread = %d\n", id_threads);


  }  /* All threads join master thread and disband */

}
