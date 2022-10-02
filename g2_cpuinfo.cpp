#include <iostream>
using namespace std;
int main(){
    cout<<"Kernel Information......."<<endl;
    system("cat /proc/version_signature | awk '{printf \"Kernel Version: %s\\n\", $0}'");
    cout<<" \n CPU Information......."<<endl;
    system("cat /proc/cpuinfo | awk '/processor|model/{print}'");
    return 0;
}