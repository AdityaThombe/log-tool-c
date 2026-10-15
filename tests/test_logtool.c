#include "logtool.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int check(int ok, const char *what)
{
    if (!ok)
        fprintf(stderr, "FAILED: %s\n", what);
    return ok ? 0 : 1;
}

int main(int argc, char **argv)
{
    const char *which = argc > 1 ? argv[1] : "";
    if (strcmp(which, "level") == 0) {
        char out[64];
        format_level(out, "INFO", "started");
        return check(strcmp(out, "[INFO] started") == 0, "format_level");
    }
    if (strcmp(which, "tag") == 0) {
        char out[16];
        return check(copy_tag(out, "api") == 3 && strcmp(out, "api") == 0, "copy_tag");
    }
    if (strcmp(which, "lines") == 0) {
        char path[] = "/tmp/logtool-XXXXXX";
        int fd = mkstemp(path);
        if (fd < 0)
            return 1;
        FILE *f = fdopen(fd, "w");
        fputs("a\nb\nc\n", f);
        fclose(f);
        int lines = count_lines(path);
        remove(path);
        return check(lines == 3, "count_lines");
    }
    fprintf(stderr, "unknown test %s\n", which);
    return 2;
}
