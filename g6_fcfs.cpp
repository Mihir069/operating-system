#include <iostream>
using namespace std;

int main() {
    
    cout << "It is a Program to implement FCFS scheduling algorithm\n";
    int twt= 0, ttt= 0;
    cout << "\nEnter the Number of Processes: ";
    int n;
    cin >> n;
    int bt[n],wt[n],at[n],tt[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the Burst Time for Process [" << i+1 << "]: ";
        cin >> bt[i];
    }
    wt[0]=0;
    for(int i = 0; i < n; i++) {
        if(i==0)    wt[i]=0;
        else    wt[i]=wt[i-1]+bt[i-1];
        tt[i]=bt[i]+wt[i];

    }
    cout << "-----------------------------------------------------\n";
    cout << "Process | Burst Time | Waiting Time | TurnAround Time\n";
    cout << "-----------------------------------------------------\n";
    for(int i = 0; i < n; i++) {
        twt+=wt[i];
        ttt+=tt[i];
        cout<<i+1<<"\t  "<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<< endl;
    }
    cout << "-----------------------------------------------------\n";
    cout << "Average Waiting Time: " << twt/n;
    cout << "\nAverage Turnaround Time: " << ttt/n << endl;
    return 0;
}