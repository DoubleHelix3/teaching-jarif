#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "os.h"

int main() {
    OS os = getOS();
    if(!os) return 1;
    
    char *cmd = malloc(200);
    *cmd = 0;
    char *comp = defaultCompiler(os);
    sprintf(cmd, "%s -c main.c && %s -o temp .internal/thisExercise.c main.o && ", comp, comp);
    strcat(cmd, executable(os, "temp"));
    system(cmd);

    // remove the garbage files generated by a compiler
    *cmd = 0;
    sprintf(cmd, "%s main.o && %s %s", rm(os), rm(os), executableFile(os, "temp"));
    system(cmd);

    return 0;
}