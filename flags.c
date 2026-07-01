#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    /*
    for (int i=1; i<argc; i++)
    {
        //if (strcmp(argv[i], "-n") != 0 && argv[i] != "-u" && argv[i] != "-h")
        //{
          //  printf("no flags\n");
        //}
        //else
        //{

            if (strcmp(argv[i], "-n") == 0)
            {
                int num = *argv[i+1] - '0';
                for (int j = 0; j<num;j++)
                {
                    printf("%s\n", argv[argc-1]); //last arguments is the one applied
                }
            }
            if (strcmp(argv[i], "-u") == 0)
            {
                for (int k = 0; k<(strlen(argv[argc-1])); k++)
                {
                    *(argv[argc - 1] + k) = toupper(*(argv[argc-1] + k));
                }

            }
            if (strcmp(argv[i], "-h") == 0)
            {
                return 1;
            }
    }
    */
    int opt;
    int flag_u = 0;
    int flag_h = 0;
    int n = 1;
    while ((opt = getopt(argc, argv, "n:uhs")) != -1)
    {
        switch (opt)
        {
        case 'n':
            n = atoi(optarg);
            break;

        case 'u':
            flag_u = 1;
            break;

        case 'h':
            flag_h = 1;;
            break;

        case 's':
            printf("Nothing. Stopping program\n");
            return 0;

        default:
            printf("unknown option.\n"
                   "Please enter:\n"
                   "-h : to ask for help for commands.\n");
            return 1;
        }
    }


        //char *message = argv[argc-1];

        char *message = NULL;

        //if index of the input is less than total of arguments including the flags (this means if there is no flag)
        //get argument if it's suppose to be a flag - turn flag into argument
        if (optind < argc) {
            message = argv[optind];
        }

        if (flag_u)
        {
            int j;
            for (j = 0; *(message + j) != '\0'; j++)
            {
                *(message + j) = toupper(*(message + j));
            }

        }

        if (flag_h) {
            printf("All commands:\n"
            "-n n(number) (statement) : This repeats your statement n times.\n"
            "-u (statement) : This converts your statement to upper case.\n"
            "-s : to stop the program.\n"
            "-h : to ask for help for commands.\n");
        }

        //this makes sure if there is actually an argument to print
        if (message) {
            int i;
            for (i = 0; i < n; i++)
            {
                printf("%s\n", message);  //repeat n times
            }
        }


}