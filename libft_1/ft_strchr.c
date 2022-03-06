#include"libft.h"
char	*ft_strchr(const char *s, int c)
{
	unsigned char	*new;
	int				i;

	i = 0;
	new = (unsigned char *)s;
	while (new[i] != '\0')
	{
		if (new[i] == (unsigned char)c)
			return ((char *)&new[i]);
		i++;
	}
	if (new[i] == (unsigned char)c)
		return ((char *)&new[i]);
	return ((void *) 0);
}
