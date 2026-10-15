#ifndef LOGTOOL_H
#define LOGTOOL_H

/* Writes "[LEVEL] message" into out (out must hold at least 64 bytes). */
void format_level(char *out, const char *level, const char *message);

/* Copies a short tag (at most 15 characters are expected) into a 16-byte buffer and returns its length. */
int copy_tag(char out[16], const char *tag);

/* Counts the lines of a log file using the system tool; returns -1 on error. */
int count_lines(const char *path);

#endif
