//#include<stdlib.h>
#include"libft.h"
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	str[ft_strlen(s1)] = '\0';
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
