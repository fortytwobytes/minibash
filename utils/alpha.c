
int is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}