#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

//run the program with this command
//gcc -pthread -o Hw3Part1 Hw3Part1.c -lm


/* Define globally accessible variables and a mutex */

#define NUMTHRDS 3
double money;
pthread_t callThd[NUMTHRDS];
//pthread_mutex_t mutexlock;


void *dotprod(void *arg)
{

   /* Define and use local variables for convenience */

   int i = *((int*)arg);
   char arr[3] = {'A','B','C'};
   double m = 0;


   //pthread_mutex_lock (&mutexlock);
   while(money> 0){
   m = (money/(4));
   m = round(m+0.49);
   money= money- m;
   //pthread_mutex_unlock (&mutexlock);
   printf("\n%c Takes away $: %d  ",arr[i],(int)m);
   sleep(3);
   //pthread_mutex_lock (&mutexlock);
   }
   //pthread_mutex_unlock (&mutexlock);
  
   pthread_exit((void*) 0);
}



int main (int argc, char *argv[])
{
   int i;
   int k[3] = {0,1,2};
   void *status;
   money= 4000;

   //pthread_mutex_init(&mutexlock, NULL);            

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
   printf ("\nThe total number of $ given out is = %0.2f \n",4000-money);
   //pthread_mutex_destroy(&mutexlock);
   pthread_exit(NULL);
}