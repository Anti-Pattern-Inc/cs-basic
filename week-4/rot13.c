#include <stdio.h>
#include <ctype.h>

void rot13(char *, char *);

int main(int argc, char *argv[])
{
    char *srcstr = argv[1];
    char dststr[256];

    rot13(srcstr, dststr);

    printf("src: %s\ndst: %s\n", srcstr, dststr);

    return 0;
}

void rot13(char *src, char *dst)
{
    char c;
    for (int i = 0; src[i] != '\0'; i++)
    {
        c = src[i];
        if (isalpha(c))
        {
            if ('a' <= c && c <= 'm' || 'A' <= c && c <= 'M')
                c = c + 13;
            else
                c = c - 13;
        }
        dst[i] = c;
        dst[i+1] = '\0';
    }
}
