#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;


int main(int argc,char* argv[]) {
    char a[1000000];
    int n;
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY | O_CREAT);

    if (fd1 < 0)
        cout<<"\nSource File cannot be opened.\n";

    if (fd2 < 0)
        cout<<"\nTarget File cannot be opened/created.\n";

    while ((n = read(fd1, a, 100)) > 0)
        write(fd2, a, n);

    write(fd2, "\0", 1);

    if (n < 0)
        cout<<"\nFile could not read the content.\n";

    close(fd1);
    close(fd2);


    return 0;
}