/*
** main.c for borwein in /home/VEYSSI_B/rendu/Maths/110borwein
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Apr  4 13:28:30 2016 Baptiste veyssiere
** Last update Thu Apr 14 12:05:44 2016 nathan scutari
*/

#include <stdio.h>
#include "borwein.h"

int	syntax_check(char *str)
{
  int	nbr;
  int	i;

  nbr = 0;
  i = -1;
  while (str[++i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  printf("Error : argument must be a positive integer\n");
	  return (1);
	}
      nbr++;
    }
  if (nbr == 0)
    return (1);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac < 2)
    {
      printf("Usage : ./110borwein x (x : positive integer)\n");
      return (84);
    }
  if (syntax_check(av[1]))
    return (84);
  calc(atoi(av[1]));
  return (0);
}
