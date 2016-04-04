/*
** calc.c for borwein in /home/VEYSSI_B/rendu/Maths/110borwein
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Apr  4 13:27:39 2016 Baptiste veyssiere
** Last update Mon Apr  4 14:33:25 2016 Baptiste veyssiere
*/

#include <math.h>
#include <stdio.h>
#include "borwein.h"

double	F(double x)
{
  double	sinus;

  sinus = x;
  sinus = sin(sinus);
  sinus /= x;
  return (sinus);
}

double  Fn(double x, int n)
{
  double        sinus;
  float		k;
  float		FN;

  if (x == 0)
      sinus = 1;
  else if (x != 0)
    {
      FN = 1;
      k = -1;
      while (++k <= n)
	FN *= sin(x / (2 * (double)k + 1)) / (x / (2 * (double)k + 1));
      sinus = FN;
    }
  return (sinus);
}

void	calc_pos(int n)
{
  int   i;
  double        A;
  double        B;
  double        REC;
  double        TRA;
  double        SIM;

  i = 0;
  REC = 0;
  TRA = 0;
  SIM = 0;
  while (++i < 10000)
    {
      A = Fn(((double)i / 2), n);
      B = Fn(((double)i / 2 + 0.25), n);
      REC += A;
      TRA += 2 * A;
      SIM += 2 * A + 4 * B;
    }
  A = Fn(5000, n);
  B = Fn(0.25, n);
  REC = 0.5 * (REC + 1);
  TRA = 0.25 * (TRA + 1 + A);
  SIM = 0.5 / 6 * (SIM + 1 + A + 4 * B);
  printf("Rectangles:\n10 = %.10f\ndiff = %.10f\n\nTrapezoids:\n10 = %.10f\ndiff = %.10f\n\nSimpson:\n10 = %.10f\ndiff = %.10f\n", REC, REC - M_PI / 2, TRA, TRA - M_PI / 2, SIM, SIM - M_PI / 2);
}

void	calc(int n)
{
  int	i;
  double	A;
  double	B;
  double	REC;
  double	TRA;
  double	SIM;

  if (n > 0)
    calc_pos(n);
  else
    {
      i = 0;
      REC = 0;
      TRA = 0;
      SIM = 0;
      while (++i < 10000)
	{
	  A = F(((double)i / 2));
	  B = F(((double)i / 2 + 0.25));
	  REC += A;
	  TRA += 2 * A;
	  SIM += 2 * A + 4 * B;
	}
      A = F(5000);
      B = F(0.25);
      REC = 0.5 * (REC + 1);
      TRA = 0.25 * (TRA + 1 + A);
      SIM = 0.5 / 6 * (SIM + 1 + A + 4 * B);
      printf("Rectangles:\n10 = %.10f\ndiff = %.10f\n\nTrapezoids:\n10 = %.10f\ndiff = %.10f\n\nSimpson:\n10 = %.10f\ndiff = %.10f\n", REC, REC - M_PI / 2, TRA, TRA - M_PI / 2, SIM, SIM - M_PI / 2);
    }
}