#include <iostream>
using namespace std;

int main(int argc,char *argv[]){
    char command[1024];
    if(argc != 2){
        cout<<stderr<<argv[0];
    }
    system(command);
    return 0;
}