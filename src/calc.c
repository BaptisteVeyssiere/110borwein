/*
** calc.c for borwein in /home/VEYSSI_B/rendu/Maths/110borwein
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Apr  4 13:27:39 2016 Baptiste veyssiere
** Last update Thu Apr 14 12:32:41 2016 nathan scutari
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
  double	k;
  double	FN;

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
  printf("Rectangles:\nI%d = %.10f\ndiff = ", n, REC);
  if (REC - M_PI / 2 < 0 && REC - M_PI / 2 > -0.0000000001)
    printf("0.0000000000\n");
  else
    printf("%.10f\n", REC - M_PI / 2);
  printf("\nTrapezoids:\nI%d = %.10f\ndiff = ", n, TRA);
  if (TRA - M_PI / 2 < 0 && TRA - M_PI / 2 > -0.00000000001)
    printf("0.0000000000\n");
  else
    printf("%.10f\n", TRA - M_PI / 2);
  printf("\nSimpson:\nI%d = %.10f\ndiff = ", n, SIM);
  if (SIM - M_PI / 2 < 0 && SIM - M_PI / 2 > -0.00000000001)
    printf("0.0000000000\n");
  else
    printf("%.10f\n", SIM - M_PI / 2);
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
      printf("Rectangles:\nI%d = %.10f\ndiff = ", n, REC);
      if (REC - M_PI / 2 < 0 && REC - M_PI / 2 > -0.00000000001)
	printf("0.0000000000\n");
      else
	printf("%.10f\n", REC - M_PI / 2);
      printf("\nTrapezoids:\nI%d = %.10f\ndiff = ", n, TRA);
      if (TRA - M_PI / 2 < 0 && TRA - M_PI / 2 > -0.00000000001)
	printf("0.0000000000\n");
      else
	printf("%.10f\n", TRA - M_PI / 2);
      printf("\nSimpson:\nI%d = %.10f\ndiff = ", n, SIM);
      if (SIM - M_PI / 2 < 0 && SIM - M_PI / 2 > -0.00000000001)
	printf("0.0000000000\n");
      else
	printf("%.10f\n", SIM - M_PI / 2);
    }
}
