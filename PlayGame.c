#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
pthread_t t,t1;
pthread_mutex_t  l;
void *Student()
{
pthread_mutex_lock(&l);
printf("Student you can play till 6.00hr \n");
printf("Student playing\n");
sleep(2);
pthread_mutex_unlock(&l);
printf("Student played now next turn\n");
}
void *Faculty()
{
pthread_mutex_lock(&l);
printf("Faculty you can play till 8.00hr \n",time);
printf("Faculty playing\n");
sleep(2);
pthread_mutex_unlock(&l);
printf("Faculty played next turn\n");
}
void *Staff()
{
pthread_mutex_lock(&l);
printf("Staff you can play till you want \n",time);
printf("Staff playing\n");
sleep(2);
pthread_mutex_unlock(&l);
printf("Staff played next turn\n");
}
void *Enter()
{
float time;
char name[10];
printf("\n\nenter the person who want to play game\n");
scanf("%s",name);
printf("time of arrival in 24 hour format\n");
scanf("%f",&time);
if(strcmp(name,"Student")==0)
{
if(time>=22.00 || time<=6.00)
{
printf("\n\nFrom %.2fhr,",time);
pthread_create(&t1,NULL,Student,NULL);
pthread_join(t1,NULL);
}
else
{
printf("\n\n%s,you are not allowed to play as your arrival %.2fhr time is differ different  from the scheduled one \n",name,time);
}
}
else if(strcmp(name,"Faculty")==0)
{
if(time>=17.00 || time<=8.00)
{
printf("\n\nFrom %.2fhr,",time);
pthread_create(&t1,NULL,Faculty,NULL);
pthread_join(t1,NULL);
}
else
printf("\n\n%s,you are not allowed to play as your arrival %.2fhr time is different  from the scheduled one \n",name,time);
}
else if(strcmp(name,"Staff")==0)
{
printf("\n\nFrom %.2fhr,",time);
pthread_create(&t1,NULL,Staff,NULL);
pthread_join(t1,NULL);
}
else
printf("\n\n%s you don't have access to games\n",name);
pthread_exit(NULL);
}
int main()
{
int n;
printf("enter number of person want to play game\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
pthread_create(&t,NULL,Enter,NULL);
pthread_join(t,NULL);
}
}

