#include "stdio.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  if(argc != 3){
    printf("yo not 3 args.... you failed\n" );
    return 1;
  }

  int f = open(argv[1], O_RDONLY);
  int f2 = open(argv[2], O_WRONLY);
  if(f < 0 )return 1;
  if(f2 < 0){
    f2 = open(argv[2], O_CREAT | O_WRONLY);
    if(f2<0)return 1;
  }

  int s = lseek(f, 0, SEEK_END);
  char buf[s];
  lseek(f, 0, SEEK_SET);

  int ok = read(f, &buf, sizeof(buf));
  if(ok == -1)return 1;
  ok = write(f2, buf, sizeof(buf));
  if(ok == -1)return 1;

  close(f);
  close(f2);
  return 0;
}
