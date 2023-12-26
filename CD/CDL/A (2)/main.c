#include <stdio.h>
int singleLineComments = 0;
int multiLineComments = 0;
int commentFinder(char com[256])
{
    int i = 2, a = 0;
    if (com[0] == '/')
    {
        if (com[1] == '/')
        {
            printf("\nSingle Line Comment : \n");
            singleLineComments++;
            return 1;
        }
        else if (com[1] == '*')
        {
            for (i = 2; i <= 30; i++)
            {
                if (com[i] == '*' && com[i + 1] == '/')
                {
                    printf("\nMultilne Comment : \n");
                    multiLineComments++;
                    return 1;
                    a = 1;
                    break;
                }
                else
                    continue;
            }
            if (a == 0)
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}

void main(int argc, char* argv[])
{
    int cnt = 0;
    char const* const fileName = "comments.c"; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r");    /* should check the result */
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        cnt++;
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        if (commentFinder(line) == 1)
        {
            printf("%s is a comment at %d.\n", line, cnt);
        }
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */
    printf("\n------------------------------------------------------\n");
    printf("Single Line Comments Total : %d\n", singleLineComments);
    printf("Multiline Comments Total : %d\n", multiLineComments);

    fclose(file);
}
