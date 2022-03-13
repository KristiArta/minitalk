#include "minitalk.h"

void	send_byte(char byte, int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (byte >> j & 1)
        {
			if (kill(pid, SIGUSR2) == -1)
		    {
			    ft_putstr("Error signal!\n");
			    exit(0);
		    }
        }
		else
		{
            if (kill(pid, SIGUSR1) == -1)
		    {
			    ft_putstr("Error signal!\n");
			    exit(0);
		    }
        }	
		usleep(500);
		j--;
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_byte(str[i], pid);
}

int	main(int argc, char **argv)
{
    if (argc != 3)
		error();
    if(argc == 3)
	    send_message(argv[2], ft_atoi(argv[1]));
	return (0);
}