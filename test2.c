#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
  char key[] = "\x79\x67\x69\x75\x65";
  int fd = 0;
  int i = 0;
  char buf[256] = {0};
  char *r = buf;

  fd = open("key.txt", O_RDONLY);
  read(fd, r, 256);
  close(fd);

  while(i < 5) {
    if((*r ^ (0x22)) != key[i])
      return 1;
    r++;
    i++;
  }

  printf("Success!\n");
  return 0;
}