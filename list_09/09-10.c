#include <stdio.h>

int main(void);

int main(void)
{
  int i;
  int a[10];

  for (i = 0; i <= 10; i++){
    a[i] = a[i - 1]  + i;
  }
  printf("%d\n", a[5]);

  return (0);
}
