#include <iostream>
using namespace std;
int main(){
    int process[10],arrival_time[10],burst_time[10],waiting[10],wait_time[10];
    float st = 0.0,turn_around = 0.0,wat = 0.0;
    int num_processe;
    cout<<"Enter the number of processes :";
    cin>>num_processe;
    for(int i =0;i<num_processe;i++){
        process[i] = i;

        cout<<"Enter Burst time p"<<i+1<<":";
        cin>>burst_time[i];

        waiting[i];
        wait_time[i];
    }
    int t;
    int max;
    int max1;
    cout<<"Enter time :";
    cin>>t;

    for(int i=0;i<num_processe;i++){
        cout<<"\nProcesses :"<<process[i]<<"\nArrival Time"
        <<arrival_time[i]<<"\nBurst Time"
        <<burst_time[i]<<"\n";

    }
    max = burst_time[0];
    max1 = 0;
    for(int i=0;i<num_processe;i++){
        if(max<burst_time[i]){
            max = burst_time[i];
            max1 = i;
        }
    }
    int y;
    while(y>0){
        for(int i=0;i<num_processe;i++){
            if(burst_time[i]>0){
                if(burst_time[i]>t){
                    burst_time[i] -=t;
                    st += t;
                    waiting[i] +=t;
                }
                else{
                    wait_time[i] = st -wait_time[i];
                    st +=burst_time[i];
                    cout<<"waiting is "<<wait_time[i];
                    wat = wat+wait_time[i] 
                    turn_around = turn_around+st-arrival_time[i];
                    burst_time[i] = 0;
                }
                if(burst_time[max1] ==0){
                    y=0;
                }
            }
        }
        cout<<"\nWaiting Time :"<<wat<<endl;
        cout<<"\nTurn around Time :"<<turn_around<<endl;
    }

}