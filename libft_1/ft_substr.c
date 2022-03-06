#include"libft.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	if (len >= (size_t)ft_strlen(s + start))
		new = malloc (sizeof(char) * (ft_strlen(s + start) + 1));
	else
		new = malloc (sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		new[i] = s[start + i];
		i++;
	}
	new[len] = '\0';
	return (new);
}
