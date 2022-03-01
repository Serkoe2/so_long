#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int a;
    int b;

    a = ft_printf("fdvatyui %c dadw %p ", 1, NULL);
    printf("\n");
    b = printf("fdvatyui %c dadw %p ", 1, NULL);
    printf("\n Prtitf = %d , my = %d\n", a, b);

    a = ft_printf("fdvatyui %s dadw %s ", NULL, "45678");
    printf("\n");
    char *q;
    q = NULL;
    b = printf("fdvatyui %s dadw %s ", q, "45678");
    printf("\n Prtitf = %d , my = %d\n", a, b);

    a = ft_printf("fdvatyui %x dadw %u%i%% ", 190, 12345678, 1234);
    printf("\n");
    b = printf("fdvatyui %x dadw %u%i%% ", 190, 12345678, 1234);
    printf("\n Prtitf = %d , my = %d\n", a, b);
}