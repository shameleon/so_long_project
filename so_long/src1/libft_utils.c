
#include "map.h"

size_t  ft_strlen(const char *s)
{
        size_t  len;

        len = 0;
        while (s[len])
                len++;
        return (len);
}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t  i;

        i = 0;
        while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
                i++;
        if (i < n)
                return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        else
                return (0);
}

char    *ft_strchr(const char *s, int c)
{
        while (*s != (char)c)
        {
                if (*s == '\0')
                        return (NULL);
                s++;
        }
        return ((char *)s);
}

/* count the occurences of a char in a string*/
int     ft_strnchr(const char *s, int c)
{
	int     count;

	count = 0;
	while (s && *s != '\0')
        {
		s = ft_strchr(s, c);
		if (!s)
			return (count);
		count++;
		s++;
	}
	return (count);
}

char    *ft_strrchr(const char *s, int c)
{
        int     i;

        i = 0;
        while (s[i] != '\0')
                i++;
        while (i >= 0)
        {
                if (s[i] == (char)c)
                        return ((char *)(s + i));
                i--;
        }
        return (0);
}

void    ft_putendl(char *s)
{
        int     i;

        i = 0;
        if (s != 0)
        {
                while (s[i] != '\0')
                {
                        write (1, &s[i], 1);
                        i++;
                }
                write (1, "\n", 1);
        }
}
