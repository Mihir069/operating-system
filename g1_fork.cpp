#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<iostream>
using namespace std;

void sameProgramSameCode();
void sameProgramDifferentCode();
void sameProgramWaitForChildToExit();

int main()
{
    int choice;
    while(1)
    {
        cout<<"1) Same program and same code\n";
        cout<<"2) Same program different code\n";
        cout<<"3) before terminating the parent wait for the child to finish it's task\n";
        cout<<"Enter 0 to exit...\n";
        cin>>choice;
        switch(choice){
            case 0:
                exit(0);
            case 1:
                sameProgramSameCode();
                break;
            case 2:
                sameProgramDifferentCode();
                break;
            case 3:
                sameProgramWaitForChildToExit();
                break;
            default:
                cout<<"ERROR: wrong choice try again...\n";
        }
    }
    return 0;
}

void sameProgramSameCode()
{
    fork();
    cout<<"pid: \n"<<getpid();
    exit(1);
}  

void sameProgramDifferentCode()
{
    cout<<"Now we will execute different code in parent and child\n";
    pid_t pid = fork();
    if(pid==0)
    {
        cout<<"Inside child with pid: \n"<<getpid();
        exit(1);
    }
    else if(pid>0)
    {
        cout<<"Inside parent with pid: \n"<<getpid();
        exit(1);
    }
    else
    {
        cout<<"ERROR: while forking";
        exit(1);
    }
}

void sameProgramWaitForChildToExit()
{
    pid_t pid = fork();
    if(pid==0)
    {
        cout<<"Inside child with pid: \n"<<getpid();
        exit(1);
    }
    else if(pid>0)
    {
        cout<<"Inside parent with pid: \n"<<getpid();
        cout<<"Parent waiting for child\n";
        wait(NULL);
        exit(1);
    }
    else
    {
        cout<<"ERROR: while forking";
        exit(1);
    }
}