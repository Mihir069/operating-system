#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using namespace std;

int sum = 0;
void *summer(void *);                               

int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;

    if (argc != 2)                                 
    {
        cout<<"usage:integer value\n";
        
    }
    else if (atoi(argv[1]) < 0)                    
    {
        cout<< "integer value must be > 0\n";
        
    }
    pthread_attr_init(&attr);                      
    pthread_create(&tid, &attr, summer, argv[1]);   
    pthread_join(tid,NULL);                         
    cout<<"SUM: %d\n"<<sum;                        
    return 0;
}

void *summer(void *param)
{
    int n = atoi((char*)param);
    for(int i=0;i<=n;i++)
        sum=sum*i;
    pthread_exit(0);
    
}