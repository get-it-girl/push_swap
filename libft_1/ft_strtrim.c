#include"libft.h"

int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		begin;
	int		end;
	int		i;

	begin = 0;
	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[begin] != '\0' && check_set(s1[begin], set) == 1)
		begin++;
	while (end > begin && check_set(s1[end - 1], set))
		end--;
	new = malloc (sizeof(char) * (end - begin + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (begin < end)
	{
		new[i] = s1[begin];
		i++;
		begin++;
	}
	new[i] = '\0';
	return (new);
}

/*
#include<stdio.h>
int main()
{
	char const s1[100] = "hhhhhhhheeellooo worlddddddddqwwww";
	printf("%s", ft_strtrim(s1, "hqqwww"));
	return (0);
}
*/