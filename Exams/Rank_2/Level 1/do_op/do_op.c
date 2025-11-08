#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	do_op(char *num1, char ope, char *num2)
{
	int	result = 0;
	int n1 = atoi(num1);
	int n2 = atoi(num2);

	if (ope == '+')
		result = n1 + n2;
	else if (ope == '-')
		result = n1 - n2;
	else if (ope == '*')
		result = n1 * n2;
	else if (ope == '/')
		result = n1 / n2;
	else if (ope == '%')
		result = n1 % n2;
	return (result);
}

int main(int ac, char **av)
{
	if (ac == 4)
		printf("%d\n", do_op(av[1],av[2][0],av[3]));
	else
		write(1, "\n", 1);
	return (0);
}
