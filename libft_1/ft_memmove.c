#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*c;
	const char	*new;
	char		*another_c;
	const char	*another_new;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (len != 0)
	{
		c = dst;
		new = src;
		if (c < new)
		{
			while (len--)
				*c++ = *new++;
		}
		else
		{
			another_c = c + (len - 1);
			another_new = new + (len - 1);
			while (len--)
				*another_c-- = *another_new--;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
char str1[40], str2[40];
strcpy(str1, "LOLLBorn to code in C/C++.");
memmove(str2, str1, strlen(str1));
printf("%s", str2);
return 0;
}
*/