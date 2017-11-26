int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	while ((i * i) < nb)
		i += 1;
	return (i);
}
