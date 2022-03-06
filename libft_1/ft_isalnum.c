int	ft_isalnum(int arg)
{
	if ((arg >= 'A' && arg <= 'Z') || (arg >= 'a' && arg <= 'z')
		|| (arg >= '0' && arg <= '9'))
		return (1);
	return (0);
}
