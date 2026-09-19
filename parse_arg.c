
void parse_arg(char *str, int limite[16])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        // si indice est pair (dont chiffre) on extrait et on le convertit en int
        if (i % 2 == 0)
        {
            limite[j] = str[i] - '0';
            j++;
        }
        i++;
    }
}