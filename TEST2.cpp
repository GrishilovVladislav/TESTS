# include <stdio.h>
# define LEN 1000
void main(void)
{
    char line[LEN];
    int i = 0;
    int start;
    int counter = 0;
    int max = 0;
    fgets(line, 1000, stdin);
    while (line[i] != '\0') 
    {
        if ((line[i] != ' ') && (line[i] != '.') && (line[i] != ','))
        {
            counter++;
            if (counter > max)
            {
                max = counter;
                start = i - max + 1;
            }
        }
        else
            counter = 0;
        i++;
    }
    i = start;
    while (i < (LEN - max))
    {
        line[i] = line[i + max];
        i++;
    }
    puts(line);
}