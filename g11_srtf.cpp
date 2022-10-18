#include <iostream>
using namespace std;
int main(){
    int n_processor;
    cout<<"Enter the nummber of processor :";
    cin>>n_processor;
    
    int processor[n_processor],burst_time[n_processor],waiting_time[n_processor],turn_around_time[n_processor],arrival_time[n_processor];
    for(int i = 0;i<n_processor;i++){
        processor[i] = i;

        cout<<"Enter the arrival time of P"<<i+1<<" :";
        cin>>arrival_time[i];

        cout<<"Enter the burst time of P"<<i+1<<" :";
        cin>>burst_time[i];

        if(i == 0){
            waiting_time[0] = 0;
        }
        else{
            waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
        }
        turn_around_time[i] = waiting_time[i] + burst_time[i];
    }
    cout<<"Processor"<<"\t"<<"Burst Time"<<"\t"<<"Arrival Time"<<"\t"<<"Waiting Time"<<"\t"<<"Turn Around Time"<<endl;
    for(int i=0;i<n_processor;i++){
        cout<<processor[i]+1<<"\t\t"<<burst_time[i]<<"\t\t"<<arrival_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turn_around_time[i]<<endl;
    }
    int swa_p;
    for(int i=0;i<n_processor;i++){
        for(int j=i+1;j<n_processor;j++){
            if(burst_time[i]>burst_time[j]){
                swa_p = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = swa_p;
            }
        }
    }
    float wait = 0.0,turn_around = 0.0;
    for(int i=0;i<n_processor;i++){
        wait = waiting_time[i-1] + burst_time[i];
    }
    for(int i=0;i<n_processor;i++){
        turn_around +=turn_around_time[i];
    }
    cout<<"\nWaiting Time :"<<wait<<endl;
    cout<<"\nTurn Around Time :"<<turn_around<<endl;

    float avg_waiting_time,avg_turn_around;
    avg_waiting_time = wait/n_processor;
    avg_turn_around = turn_around/n_processor;

    cout<<"\nAVERAGE WAITING TIME :"<<avg_waiting_time;
    cout<<"\nAVERAGE TURN AROUND TIME :"<<avg_turn_around;
    return 0;
}