#include"libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
#include<stdio.h>
#include<string.h>
int main()
{
	char ar[10] = "";
	printf("%lu", ft_strlen(ar));
	return (0);
}
*/
