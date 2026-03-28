#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Setup syslog with LOG_USER facility
    openlog("writer", LOG_PID, LOG_USER);

    // Check for correct number of arguments
    if (argc != 3) {
        syslog(LOG_ERR, "Error: Two arguments required. Received: %d", argc - 1);
        fprintf(stderr, "Usage: %s <file_path> <string_to_write>\n", argv[0]);
        closelog();
        return 1;
    }

    const char *filename = argv[1];
    const char *text = argv[2];

    // Log the writing attempt at LOG_DEBUG level
    syslog(LOG_DEBUG, "Writing %s to %s", text, filename);

    // Open file for writing (creates or overwrites)
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Failed to open file %s: %s", filename, strerror(errno));
        perror("File error");
        closelog();
        return 1;
    }

    // Write the string to the file
    if (fputs(text, file) == EOF) {
        syslog(LOG_ERR, "Failed to write to file %s", filename);
        fclose(file);
        closelog();
        return 1;
    }

    fclose(file);
    closelog();
    return 0;
}
