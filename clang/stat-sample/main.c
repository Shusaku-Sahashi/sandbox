#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> // lstat, struct stat のために必要
#include <unistd.h>   // lstat のために必要

int main() {
  const char *path = "./main.c";
  struct stat file_stat;

  if (lstat(path, &file_stat) == -1) {
    perror("lstat error");
    exit(EXIT_FAILURE);
  }

  if (S_ISLNK(file_stat.st_mode)) {
    printf("種類: シンボリックリンク\n");
  } else if (S_ISREG(file_stat.st_mode)) {
    printf("種類: ファイル\n");
  }

  return 0;
}
