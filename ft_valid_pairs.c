
int	valid_pairs(int *pair)
{
	int	validpairs[5][2];

	validpairs[0][0] = 4;
	validpairs[0][1] = 1;
	validpairs[1][0] = 3;
	validpairs[1][1] = 2;
	validpairs[2][0] = 3;
	validpairs[2][1] = 1;
	validpairs[3][0] = 2;
	validpairs[3][1] = 2;
	validpairs[4][0] = 2;
	validpairs[4][1] = 1;
}





int	**ft_pairscheck(char *str)
{
	int	i;
	int	j;
	int	k;
	int	pos1;
	int	pos2;
	int	allpairs[16];



	// Step 1: fill array
	i = 0;// which row/column
	j = 0;// where in the row/column
	k = 0;// where in allpairs
	pos1 = i + j;
	pos2 = i + 4 + j;
	while (i < 4 && j < 4)
	{
		while (i < 2 && j < 4)	
		{
			allpairs[pos]str[pos1]
	}

	// How do I check the pairs?? 
}