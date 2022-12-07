#include <stdio.h>

void enc(char *, char *);
void enc_mod(char *, char *);
void dec(char *, char *);

int main(int argc, char *argv[])
{
    char *srcstr = argv[1];
    char dststr[256];
    char dstmodstr[256];
    char decstr[256];

    enc(srcstr, dststr);
    enc_mod(srcstr, dstmodstr);
    dec(dststr, decstr);

    printf("src: %s\ndst   : %s\ndstmod: %s\ndec: %s\n", srcstr, dststr, dstmodstr, decstr);

    return 0;
}

void enc_mod(char *src, char *dst)
{
    char c;
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        c = src[i];
        if ('a' <= c && c <= 'z')
        {
            c = (c - 'a' + 13) % 26 + 'a';
        }
        else if ('A' <= c && c <= 'Z')
        {
            c = (c - 'A' + 13) % 26 + 'A';
        }
        dst[i] = c;
    }
    dst[i] = '\0';
}

void enc(char *src, char *dst)
{
    char c;
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        c = src[i];
        if ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z')
        {
            if ('a' <= c && c <= 'm' || 'A' <= c && c <= 'M')
                c = c + 13;
            else
                c = c - 13;
        }
        dst[i] = c;
    }
    dst[i] = '\0';
}

void dec(char *src, char *dst)
{
    enc(src, dst);
}
