#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 1000

int main()
{
    char str[MAXSIZE];
    int size, max = 0;
    int i = 0;
    int counter = 0;
    int maxBegin = 0;
    char res[MAXSIZE];

    gets_s(str);
    size = strlen(str);

    for (i = 0; i < size; i++)
    {
        if (str[i] != ' ')
        {
            counter++;
            if (counter > max)
            {
                max = counter;
                maxBegin = i - max + 1;
            }
        }
        else
        {
            counter = 0;
        }
    }
    for (i = maxBegin; i < size - max; i++)
    {
        str[i] = str[i + max];
        
    }
    puts(str);
}

