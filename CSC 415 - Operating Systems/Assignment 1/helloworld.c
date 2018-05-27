#include <stdio.h>
#include <unistd.h>

#define NAME "Parker" 

int main()
{
char buf[100]; //character array

sprintf(buf, "Hello CSC415, I am %s!\n", NAME);

write(1, buf, 28);

return 0;
}
