#include "solong.h"

// char	*ft_strdup(const char *s)
// {
// 	char	*newstr;
// 	int		i;

// 	i = 0;
// 	newstr = malloc(sizeof(char) * ft_strlen(s) + 1);
// 	if (newstr == NULL)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		newstr[i] = s[i];
// 		i++;
// 	}
// 	newstr[i] = '\0';
// 	return (newstr);
// }

char **ft_copy_double_char(char **tab)
{
	int i;
	int j;
	char **newtab;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	newtab = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab[i])
	{
		newtab[i] = ft_strdup(tab[i]);
		i++;
	}
	return (newtab);
}

int main(int argc, char **argv)
{
	char **result;
	int i = 0;
	if (argc >= 2)
	{
		result = ft_copy_double_char(argv);
		while (result[i])
		{
			printf("%s\n", result[i]);
			i++;
		}
	}
}