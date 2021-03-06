//#include<stdlib.h>
#include"libft.h"
#include <stdio.h>  //Для printf
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new;
	int				i;

	i = 0;
	if (!(s) && c != '\0')
		return (NULL);
	new = (unsigned char *)s;
	while (n--)
	{
		if (new[i] == (unsigned char)c)
			return ((void *)&new[i]);
		i++;
	}
	return ((void *)0);
}
