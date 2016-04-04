/*
** main.c for borwein in /home/VEYSSI_B/rendu/Maths/110borwein
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Apr  4 13:28:30 2016 Baptiste veyssiere
** Last update Mon Apr  4 14:22:57 2016 Baptiste veyssiere
*/

#include <stdio.h>
#include "borwein.h"

int	main(int ac, char **av)
{
  if (ac != 2)
    return (84);
  calc(atoi(av[1]));
  return (0);
}
