#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
    if(argc!=3){
        cout<<stderr<<"ERROR"<<argv[0];
        return 1;
    }
    cout<<argv[1]<<argv[2];
    return 0;
}
void copy(char *src,char *dst){
    int sfd, dfd,count;
    if(!sfd){
        cout<<stderr<<"ERROR"<<src;
        exit(1);
    }
}