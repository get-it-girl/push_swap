#include"libft.h"
void	*ft_memset(void *dest, int c, size_t n)
{
	char	*new;

	new = dest;
	while (n--)
	{
		*new = c;
		new++;
	}
	return (dest);
}
