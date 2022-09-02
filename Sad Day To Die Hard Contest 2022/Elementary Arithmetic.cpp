#include<iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char a[100000009], b[100000009], r[100000009];

int main()
{

    int i, j, len1 = 0, len2 = 0, k = 0, s = 0, c = 0;
    scanf("%s", &a);
    scanf("%s", &b);
    len1 = strlen(a);
    len2 = strlen(b);
    i = len1 - 1;
    j = len2 - 1;
    k = len1 > len2 ? len1 : len2;
    r[k] = '\0';
    k--;
    while (i >= 0 && j >= 0)
    {
        s = (a[i] - 48) + (b[j] - 48) + c;
        r[k] = s % 10 + 48;
        c = s / 10;
        i--;
        j--;
        k--;
    }
    if (i >= 0)
    {
        while (i >= 0)
        {
            s = (a[i] - 48) + c;
            r[k] = s % 10 + 48;
            c = s / 10;
            i--;
            k--;
        }
    }
    if (j >= 0)
    {
        while (j >= 0)
        {
            s = (b[j] - 48) + c;
            r[k] = s % 10 + 48;
            c = s / 10;
            j--;
            k--;
        }
    }
    if (c > 0)
    {
        for (i = strlen(r); i >= 0; i--)
            r[i + 1] = r[i];
        r[0] = c + 48;
    }
    printf("%s\n", r);
}