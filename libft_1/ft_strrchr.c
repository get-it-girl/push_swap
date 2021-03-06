char	*ft_strrchr(const char *s, int c)
{
	int				size;
	unsigned char	*new;

	size = 0;
	new = (unsigned char *)s;
	while (new[size] != '\0')
		size++;
	while (size >= 0)
	{
		if (new[size] == (unsigned char)c)
			return ((char *)&new[size]);
		size--;
	}
	return ((void *)0);
}
