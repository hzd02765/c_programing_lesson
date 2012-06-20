#include <stdio.h>

#define MAX_TEN 3

int main(void);

int main(void)
{
  int sum = 0, i;
  float heikin;
  int ten[MAX_TEN] = {65, 90, 75};
  char name[MAX_TEN][5] = {
    {'\x8D', '\x91', '\x8c', '\xEA', '\0',},
    {'\x90', '\x94', '\x8A', '\x77', '\0',},
    {'\x89', '\x70', '\x8c', '\xEA', '\0',},
  };

  for (i = 0; i < MAX_TEN; i++){
    printf("%sは　%d　点\n", &name[i][0], ten[i]);
    sum += ten[i];
  }
  heikin = (float)sum / MAX_TEN;
  printf("平均点は　%.1f　点\n", heikin);

  return (0);
}
