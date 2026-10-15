/* Log helpers. Demo target for ProofPatch: intentionally vulnerable. Never deploy this code. */
#include "logtool.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void format_level(char *out, const char *level, const char *message)
{
    sprintf(out, "[%s] %s", level, message);
}

int copy_tag(char out[16], const char *tag)
{
    strcpy(out, tag);
    return (int)strlen(out);
}

int count_lines(const char *path)
{
    char command[256];
    snprintf(command, sizeof command, "wc -l < %s", path);
    FILE *pipe = popen(command, "r");
    if (!pipe)
        return -1;
    int lines = -1;
    if (fscanf(pipe, "%d", &lines) != 1)
        lines = -1;
    pclose(pipe);
    return lines;
}
