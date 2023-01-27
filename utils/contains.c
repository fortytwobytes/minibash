int contains(char *s, char c)
{
	int i;
	
	i = 0;
	while (s[i])
	{
		if(s[i] == c)
			return 1;
		i++;
	}
	return 0;
}
//this is opti branch