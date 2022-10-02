#include <iostream>
using namespace std;
int main(){
    cout<<" Kernel Information "<<endl;
    system("cat /proc/version_signature | awk '{printf\"Kernel Version: %s\\n\",$0}'");
    cout<<"\n Memory status \n";
    system("cat /proc/meminfo | awk '/Mem/{print}'");
    return 0;
}