#include<stdio.h>
#include <stdlib.h>
#include<pthread.h>

int num = 0;
pthread_mutex_t lock;

void firstThread()//for first thread function
{
  pthread_mutex_lock(&lock);
  printf("Thread 1 - %d\n",num);
  num++;
  pthread_mutex_unlock(&lock);
}

void secondThread()//for second thread function 
{
  pthread_mutex_lock(&lock);
  printf("Thread 2 - %d\n",num);
  num++;
  pthread_mutex_unlock(&lock);
}

void workingThreads(int t1,int t2)//make output one by one like in a queue first one is 1.thread 0,second one is 2.thread 1,third one turn the 1. thread again...
{
 while(num<10)
 {
 pthread_create(&t1,NULL,firstThread,NULL);
 pthread_join(t1,NULL);
 pthread_create(&t2,NULL,secondThread,NULL);
 pthread_join(t2,NULL);
 }
}

int main()
{
 FILE *fp;
 pthread_t t1,t2; 
 pthread_mutex_init(&lock, NULL);
 fp = fopen("TolgaCobanoglu17070006032Labwork2Program1.txt", "w"); // creating a test.txt file
 while(num<10){
 fprintf(fp, "%s%d\n","Thread 1 -  ",num);//writing first thread
 num++;
 fprintf(fp, "%s%d\n","Thread 2 -  ",num);//writing second thread
 num++;
 }
 fclose(fp);
 
 
 return 0;
}
