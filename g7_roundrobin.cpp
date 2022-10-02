#include <iostream>
using namespace std;

int main() {
    
    cout << "It is a Program to implement Round Robin scheduling algorithm\n";
    int twt= 0, ttt= 0, q,c=0;
    cout << "\nEnter the Number of Processes: ";
    int n;
    cin >> n;
    int bt[n],wt[n],at[n],tt[n],rbt[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the Burst Time for Process [" << i+1 << "]: ";
        cin >> bt[i];
    }
    cout<<"Enter Quantum :- ";
    cin>>q;
    for (int i = 0; i < n; i++) {
        rbt[i] = bt[i];
    }
    wt[0]=0;
    cout<<"Gantt Chart";
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (rbt[i] > 0) {
                done = false;
                if (rbt[i] > q) {
                    c += q;
                    rbt[i] = rbt[i] - q;

                } else {
                    c += rbt[i];
                    rbt[i] = 0;
                    wt[i] = c - bt[i];
                }
            }
            tt[i] = wt[i] + bt[i];
        }
        if (done) {
            break;
        }
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
    cout << "Average Waiting Time: " << (float)twt/n;
    cout << "\nAverage Turnaround Time: " << (float)ttt/n << endl;
    return 0;
}