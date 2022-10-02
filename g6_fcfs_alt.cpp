#include <iostream>
using namespace std;
void wait_time(int processes[],int burst[],int waiting[],int size){
    waiting[0] = 0;
    for(int i=0;i<size;i++){
        waiting[i] = burst[i-1] + waiting[i-1];
    }
}
void turn_around_time(int processes[],int burst[],int size,int turn[]){
    for(int i=0;i<size;i++){
        turn[i] = burst[i] + waiting[i];
    }
}
void avg_time(int processes[],int size,int burst[]){
    int t_wait=0;
    int t_turn=0;
    int waiting[size];
    int turn[size];

    wait_time(processes,burst,waiting,size);
    turn_around_time(processes,burst,size,turn);
    cout<<"Processes"<<"\t"<<"Burst"<<"\t"<<"Waiting"<<"\t"<<"Turn Around"<<"\t"<<endl;
    for(int i=0;i<size;i++){
        t_wait = t_wait + waiting[i];
        t_turn = t_turn + turn[i];
        cout<<processes[i]<<"\t\t"<<burst[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turn[i]<<endl;
    }
    cout<<"Average waiting time :"<<(float)t_wait/(float)size<<endl;
    cout<<"Average turn around time :"<<(float)t_turn/(float)size<<endl;
}
int main(){
    int waiting;
    int turn;
    int processes[5];
    int burst[5];
    int size = sizeof processes/sizeof processes[0];
    cout<<"Enter element for process :";
    for(int i=0;i<5;i++){
        cin>>processes[i];
    }
    cout<<endl;
    cout<<"Enter elements for burst time :";
    for(int i=0;i<5;i++){
        cin>>burst[i];
    }
    avg_time(processes,size,burst);
    return 0;
}