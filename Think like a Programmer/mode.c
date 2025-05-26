#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int freqChar(char c, const char *str)
{
    if (str == NULL)
    {
        return 0;
    }
    int f = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (c == *str)
        {
            f++;
        }
        str++;
    }

    return f;
}

char Teststr[] = "dfaajkajbsbdasjbjjjasdjaltlhshaaaajjjdddddddddddddd";
char getMaxChar(const char *str)
{
    if (str == NULL)
    {
        return 0;
    }
    char outputChar;
    int maxF = 0;
    int len = strlen(str);
    char *characters = (char *)malloc(len + 1);
    char temp[2] = {0};

    for (int i = 0; i < len; i++)
    {
        temp[0] = str[i];
        if (strstr(characters, temp) != NULL)
        {
            continue;
        }
        else
        {
            strcat(characters, temp);
            int f = freqChar(str[i], str);
            printf("Char= %c,F= %d \r\n", str[i], f);
            if (f > maxF)
            {
                maxF = f;
                outputChar = str[i];
            }
        }
    }

    return outputChar;
}

int main()
{
    char maxfreq = getMaxChar(Teststr);

    printf("Most occured Char = %c", maxfreq);

    return 0;
}