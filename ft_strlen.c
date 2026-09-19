ft_strlen(char *str)
{
    int i;
	int	num;

    i = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] >= '0' && str[i] <= 9) || str[i] == 32))
        	return (0); 
		if (i % 2 != 0 && str[i] != 32)
            return (0);
        else if (i % 2 == 0 && (str[i] >= '0' && str[i] <= 9))
                num = str[i] + '0';
    }
    else
        write(1, " ", 1);

    i++;
}

