#include"libft.h"
#include<unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	s[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n == 0)
		write (fd, "0", 1);
	if (n < 0 && n != -2147483648)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &s[i], 1);
		i--;
	}
}
