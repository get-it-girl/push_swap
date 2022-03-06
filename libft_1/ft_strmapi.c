#include"libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	unsigned int	i;
	char			*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len] = '\0';
	while (s[i] != '\0')
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
