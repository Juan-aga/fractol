/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:06:11 by juan-aga          #+#    #+#             */
/*   Updated: 2022/09/30 17:01:33 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*		returns zero if the character test is false and '1' if it;s true.
		*/
int		ft_isalpha(int c);
/*	
		returns zero if the character test is false and '1' if it's true.
		*/
int		ft_isdigit(int c);
/*	
 		returns '1' if isallpha or isdigit true, and zero if it's false.
		*/
int		ft_isalnum(int c);
/*	
		returns '1' if 'c' is any character between 0 and 127,
 		or zero if it's false.
		*/
int		ft_isascii(int c);
/*	
		return '1' if 'c' is any ccharacter between 32 and 126,
		or zero if it's false.
		*/
int		ft_isprint(int c);
/*
		computes the lenght of str 's'.
		returns the number of characters that precede the '\0'.
		*/
size_t	ft_strlen(const char *s);
/*

   		writes 'len; bytes of 'c' (as unsigned char) to str 'b'.
		returns str 'b'.
		*/
void	*ft_memset(void *b, int c, size_t len);
/*
		writes 'n' bytes of zeroed to str 's'
		if 'n' is zero does nothing.
		*/
void	ft_bzero(void *s, size_t n);
/*
		copies 'n' bytes from memory area 'src' to 'dst'.
		If 'dst' and 'src' overlap, the return is undefined.
		returns the original value of 'dst'.
		*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
/*
		copies 'len' bytes from 'src' to 'dst'
		The two str may overlap.
		returns the original value of 'dst'.
		*/
void	*ft_memmove(void *dst, const void *src, size_t len);
/*
		copies up to 'dstsize' -1 fromm 'src' to 'dst', 
		guarantee '\0' if 'dstsize' is not 0.
		returns the length of the str they tried to create.
		*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*
		appends 'src' to the end of 'dst'.
		It will append at most ('dstsize' - strlen(dst) -1.
		appends '\0' if 'dstsize' is not 0 or 'dstsize' > strlen(dst)'
		returns the length of the str they tried to create.
		*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/*
		converts a lower-case letter to upper-case.
		the argument must be an unsigned char or '\0'.
		returns a upper-case if 'c' is lower-case. Else returns 'c'.
		*/
int		ft_toupper(int c);
/*
		converts a upperr-case letter to lower-case.
		the argument must be an unsigned char or '\0'.
		returns a upper-case if 'c' is lower-case. Else returns 'c'.
		*/
int		ft_tolower(int c);
/*
		locates the first occurrence of 'c' (as a char) in 's'.
		the '\0' is considering a part of 's'
		return a pointer to the located character, or NULL if doesn't appear.
		*/
char	*ft_strchr(const char *s, int c);
/*
		locates the last occurrence of 'c' (as a char) in 's'.
		the '\0' is considering a part of 's'
		return a pointer to the located character, or NULL if doesn't appear.
		*/
char	*ft_strrchr(const char *s, int c);
/*
		compares the '\0' of 's1' and 's2' not more thanr 'n' characteres
		as unsigned char..
		returns as an int the diference 's1' - 's2'.
		*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*
		locates the first ocurrence of 'c' (as a unsigned char) in 's'.
		returns  a pointer to the byte located or NULL if doesn't appear
		in 'n' byter.
		*/
void	*ft_memchr(const void *s, int c, size_t n);
/*
		compares byte 's1' with byte 's2'.
		Are asumed the both are 'n' bytes long.
		return zero if are identical else returns the difference between the
		first two differents vbytes (as unsigned char).
		*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*
		locates the firs occurrence of '\0' std 'srch' in 'str' where not more than
		'len'.
		returns a pointer t othe first occurrence of 'srch' or
	   	if 'srch' is empty returns 'str'
		if 'srch' occurs nowhere in 'str' returns NULL.
		*/
char	*ft_strnstr(const char *str, const char *srch, size_t len);
/*
		converts the initial portion of 'str' to an int.
		returns the int.
		*/
int		ft_atoi(const char *str);
/*
		alllocates enought space fo 'count; objects that are 'size' bytes 
		of memmory each and filled with bytes of zero value.
		returns a pointer to the allocated memory.
		If there is any error returns a NULL pointer.
		*/
void	*ft_calloc(size_t count, size_t size);
/*
		allocates enought memory for a copy of 's1', does the copy.
		returns a pointer to it. if insufficient memory NULL returns.
		*/
char	*ft_strdup(const char *s1);
/*
		allocates memmory for an str 
		*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/*					BONUS PART			*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
