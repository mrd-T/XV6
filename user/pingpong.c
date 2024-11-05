#include "kernel/types.h"
#include "user/user.h"
int main() {
  int p[2];
  pipe(p);
    // close(p[0]);
    // close(p[1]);
//   int p1[2];
//   pipe(p1);
  int pid = fork();
  if (!pid) {
    read(p[0], &pid, 4);
    // printf("%d!!%d",p[0],p[1]);
    printf("%d: received ping\n", pid);
  } else {
    write(p[1], &pid, 4);
    wait(0);
    // printf("%d!!%d\n",p[0],p[1]);
    printf("%d: received pong\n", getpid());
  }
  exit(0);
}