#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter your total number of process :";
    cin>>n;
    float p[n],twaiting =0,waiting =0,total,wait[n];
    int proc;
    int stack[n];
    float burst[n],arrival[n],sburst,temp[n],top=n,priority[n];
    int i;
    for(i=0;i<n;i++){
        p[i]=i;
        stack[i]=i;
        cout<<"\nEnter arrival time :"<<i+1<<":";
        cin>>arrival[i];
        cout<<"\nEnter burst time :"<<i+1<<":";
        cin>>burst[i];
        cout<<"\nEnter priority :"<<i+1<<":";
        cin>>priority[i];
        cout<<"\n";
        temp[i] = arrival[i];
        sburst = burst[i]+sburst;
    }
    for(i=0;i<sburst;i++){
        proc=stack[0];
        if(temp[proc] == 1){
            twaiting = 0;
        }
        else{
            twaiting = i-(temp[proc]);
         }
        temp[proc]=i+1;
        wait[proc] = wait[proc] + twaiting;
        waiting = waiting+twaiting;
        burst[proc] -=1; 
        if(burst[proc] == 0){
            for(int x=0;x<top-1;x++){
                stack[x] = stack[x+1];
            }
            top = top -1;
        }
        for(int z= 0;z<top-1;z++){
            if(priority[stack[0]]>priority[stack[z+1]]&&(arrival[stack[z+1]]<=i+1)){
                int t = stack[0];
                stack[0] = stack[z+1];
                stack[z+1] = t;
            }
        }
    }
    cout<<"\nAverage waiitng time is :"<<waiting;
    float tu=(sburst+waiting)/n;
    cout<<"\nAverage turnaround time is :"<<tu;
    return 0;
}