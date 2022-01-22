#include "../ft_ping.h"

int main(void)
{
	int	result;
	result = ft_atoi_base("25", 10);
	if (result != 25)
	{
		write(1, "not 25\n", 7);
	}
	else
	{
		write(1, "25\n", 3);
	}
}