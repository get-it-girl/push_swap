#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include<stdio.h>
int main()
{
	char ar[40] = "helloworld";
	char lol[50];
	printf("%zu\n", ft_strlcpy (lol, ar, 5));
	printf("%s", lol);
	return (0);
}
*/