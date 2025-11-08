#include <unistd.h>

void    wdmatch(char *s1,char *s2)
{
    int i = 0;
    int j = 0;
    int len = 0;

    while (s1[len])
        len++;
    while (i < len && s2[j])
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    if (i == len)
        write(1, s1, len);
}

int main(int ac, char **av)
{
    if (ac == 3)
        wdmatch(av[1], av[2]);
    write(1, "\n", 1);
    return (0);
}