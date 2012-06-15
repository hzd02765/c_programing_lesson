#include <stdio.h>

int get_power(int x, int n);
int main(void);

int get_power(int x, int n)
{
  int i, y = 1;

  for(i = 0; i < n; i++){
    y = y * x;
  }

  return (y);
}

int main(void)
{
  printf("%d\n", get_power(8, 2));

  return (0);
}
