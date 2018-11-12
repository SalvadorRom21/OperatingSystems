#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//run the program with this command
//gcc -pthread -o tshirt Tshirt.c -lm


/* Define globally accessible variables and a mutex */

#define NUMTHRDS 3
double tshirts;
pthread_t callThd[NUMTHRDS];
//pthread_mutex_t mutexsum;


void *dotprod(void *arg)
{

   /* Define and use local variables for convenience */

   int i = *((int*)arg);
   char arr[3] = {'A','B','C'};
   double m = 0;


   //pthread_mutex_lock (&mutexsum);
   while(tshirts > 0){
   m = (tshirts/(4));
   m = round(m+0.49);
   tshirts = tshirts - m;
   //pthread_mutex_unlock (&mutexsum);
   printf("\n%c Takes away $: %d  ",arr[i],(int)m);
   sleep(3);
   //pthread_mutex_lock (&mutexsum);
   }
   //pthread_mutex_unlock (&mutexsum);
  
   pthread_exit((void*) 0);
}

/*
The main program creates threads which do all the work and then
print out result upon completion. Before creating the threads,
the input data is created. Since all threads update a shared global variable tshirts,
we need a mutex for mutual exclusion. The main thread needs to wait for
all threads to complete, it waits for each one of the threads. We specify
a thread attribute value that allow the main thread to join with the
threads it creates. Note also that we free up handles when they are
no longer needed.
*/

int main (int argc, char *argv[])
{
   int i;
   int k[3] = {0,1,2};
   void *status;
   tshirts = 4000;

   //pthread_mutex_init(&mutexsum, NULL);            

   for(i=0;i<NUMTHRDS; i++)
   {
      /*
      Each thread works on a different set of data.
      The offset is specified by 'i'.
      */
      //printf("\n%d",i);
      pthread_create(&callThd[i], NULL, dotprod, (void *)&k[i]);
   }

   /* Wait on the other threads */
   for(i=0; i<NUMTHRDS; i++)
   {
      pthread_join(callThd[i], &status);
   }

   /* After joining, print out the results and cleanup */
   printf ("\nThe total number of t-shirts given out is = %0.2f \n",4000-tshirts);
   //pthread_mutex_destroy(&mutexsum);
   pthread_exit(NULL);
}