/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:46:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 20:53:22 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

// =============================================================================
//									ctype
// =============================================================================

// Checks whether c is either a decimal digit or an an alphabetic letter.
int			ft_isalnum(int c);
// Checks whether c is an alphabetic letter.
int			ft_isalpha(int c);
// Checks whether c is a decimal digit character.
int			ft_isdigit(int c);
// Checks whether c is a printable character.
int			ft_isprint(int c);
// Checks whether c is an ASCII character.
int			ft_isascii(int c);
// If c is uppercase return its lowercase equivalent
int			ft_tolower(int c);
// If c is lowercase return its uppercase equivalent
int			ft_toupper(int c);

// =============================================================================
//									stdlib
// =============================================================================

// Convert a string to an int
// Discards leading whitespace, optional plus/minus
int			ft_atoi(const char *str);
// Allocates memory for "num" items with "size", initialises to 0
void		*ft_calloc(size_t nitems, size_t size);

// =============================================================================
//									string
// =============================================================================

// -----------------------------------------------------------------------------
// memory

// Copies "n" bytes from memory area "src" to memory area "dest"
void		*ft_memcpy(void *dest, const void *src, size_t n);
// Copies "n" bytes from memory area "src" to memory area "dest"
// memory can overlap
void		*ft_memmove(void *dest, const void *src, size_t n);

// Sets "n" bytes from "mem" to "c"
void		*ft_memset(void *mem, int c, size_t n);
// Searches "n" bytes in "hay" for "c" returning the first occurence
void		*ft_memchr(const void *hay, int c, size_t n);
// Compares "n" bytes in "mem1" with "mem2" returns 0 on match,
// <0 if mem1 has lower value than mem2, >0 if mem1 has higher value than mem2
int			ft_memcmp(const void *mem1, const void *mem2, size_t n);

// -----------------------------------------------------------------------------
// examination

// Returns the length of "str"
size_t		ft_strlen(const char *str);
// Compares the first "n" characters from "str1" with "str2" returns 0 on match,
// <0 if str1 has lower value than str2, >0 if str1 has higher value than str2
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// Returns the first occurence of "c" in "str"
char		*ft_strchr(const char *str, int c);
// Returns the last occurence of "c" in "str"
char		*ft_strrchr(const char *s, int c);

// Returns the first occurence of "needle" in the first n characters of "hay"
char		*ft_strnstr(const char *hay, const char *needle, size_t n);

// -----------------------------------------------------------------------------
// modification

// Applies the function "f" to the index and address of each character of "str"
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

// strncat but null terminates the result unless dest is longer than n
// returns the length of the string it tried to create
size_t		ft_strlcat(char *dest, const char *src, size_t n);

// strncpy but null terminates the dest and size includes the null
size_t		ft_strlcpy(char *dest, const char *src, size_t n);

// -----------------------------------------------------------------------------
// creation

// Returns a freeable copy of str
char		*ft_strdup(const char *str);

// Returns a freeable copy of str starting at start with size len
char		*ft_substr(char const *str, unsigned int start, size_t len);

// Returns a freeable string which is the concatination of str1 and str2
char		*ft_strjoin(char const *str1, char const *str2);

// Returns a freeable string which is f applied to every char + index of str
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Returns a freeable NULL terminated array of freeable strings obtained by
// spliting "str" with 'c'.
char		**ft_split(char const *s, char c);

// returns a freeable copy of "s" trimming chars in set from front and back
char		*ft_strtrim(const char *str, const char *set);

// =============================================================================
//									output
// =============================================================================

// Outputs the char c to the file descriptor fd.
void		ft_putchar_fd(char c, int fd);
// Outputs the string str to the file descriptor fd followed by a new line.
void		ft_putendl_fd(const char *s, int fd);
// Adds a signle digit as its character representaion to the array
void		ft_putnbr_fd(int n, int fd);
// Outputs the string str to the file descriptor fd.
void		ft_putstr_fd(const char *s, int fd);

// =============================================================================
//									math
// =============================================================================

// Returns a freeable string representing the int n
char		*ft_itoa(int n);

// =============================================================================
//									don't use
// =============================================================================

// Sets "n" bytes from "mem" to 0
// Use memset(mem, 0, n) instead;
void		ft_bzero(void *mem, size_t n);

#endif
