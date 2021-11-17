#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
  int f, f2, w, status, r;
  printf("initial message: parent process started\n");

  f = fork();
  if(f) {
    f2 = fork();
  }

  if (f && f2) {
  w = wait(&status);
  printf("child process %d finished in %d seconds\n", w, WEXITSTATUS(status));
  printf("parent process done\n");
  return 0;
  }

  srand(getpid());
  r = rand() % 4 + 2;
  sleep(r);
  printf("child process finished sleeping in %d seconds\n", r);
  return r;
}
