🔹 b) mv Command in C
(Moves or renames a file)

🛠 Create files first:
$ cat >> file2
1
2
3
^D

$ cat >> jerry
A
B
C
^D

----------------------------------------------

CODE:
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
   
    if (rename(argv[1], argv[2]) != 0) {
        perror("rename failed");
        return 1;
    }

    return 0;
}
----------------------------------------
OUTPUT:

$ gcc mv_program.c
$ ./a.out file2 jerry

$ cat file2
cat: file2: No such file or directory

$ cat jerry
1
2
3
