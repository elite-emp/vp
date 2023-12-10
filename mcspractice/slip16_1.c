#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    if (argc != 2) 
    {
        printf("Usage: %s [Month abbreviation]\n", argv[0]);
        return 1;
    }

    char *desired_month = argv[1];
    int desired_month_index = -1;

    // Find index of the desired month in the months array
    for (int i = 0; i < 12; ++i) 
    {
        if (strcmp(desired_month, months[i]) == 0) 
        {
            desired_month_index = i;
            break;
        }
    }

    if (desired_month_index == -1) 
    {
        printf("Invalid month abbreviation\n");
        return 1;
    }

    DIR *dp;
    struct dirent *ep;
    struct stat sb;

    dp = opendir("./");

    if (dp != NULL) 
    {
        while ((ep = readdir(dp)) != NULL) 
        {
            if (stat(ep->d_name, &sb) == -1) 
            {
                perror("stat");
                exit(EXIT_FAILURE);
            }

            struct tm *creation_time = localtime(&sb.st_ctime);
            int creation_month = creation_time->tm_mon;

            if (creation_month == desired_month_index) 
            {
                printf("%s\n", ep->d_name);
            }
        }
        closedir(dp);
    } else {
        perror("Couldn't open the directory");
        return EXIT_FAILURE;
    }

    return 0;
}

