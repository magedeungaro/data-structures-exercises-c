# Data structure exercises in C

To run the exercises:
```
$ sudo docker compose run c bash

root@12345:/exercises# gcc exercise.c -o e.exe
root@12345:/exercises# ./e.exe
```

For the stack exercises (pilha-*.c), you may run
```
root@12345:exercises# bash script/stack.sh
```
This will ask the file you want to compile.
*Only for stacks exercises*

Then you can delete the executable files with
```
$ find . -type f -name "*.exe" -delete
```