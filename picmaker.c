#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  int r, g, b, x, y;
  char head = "P3 500 500 255\n";
  char in[30];
  int fd = open("pic.ppm", O_CREAT|O_WRONLY);
  write(fd, head, sizeof(head));
  for (y=0; y<500; y++){
    for (x=0; x<500; x++){
      r = x;
      g = y;
      b = (x+y)%255;
      snprintf(in, sizeof(in), "%d %d %d\n", r, g, b);
      write(fd, head, sizeof(head));
    }
  }
  return 0;
}
