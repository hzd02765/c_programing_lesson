#include <stdio.h>
#include <stdlib.h>

int main(void);

int main(void)
{
  char c;

  printf("あなたの好物はとれですか？\n");
  printf("（a）春巻き\n");
  printf("（b）シューマイ\n");
  printf("（c）どちらでもない\n");
  c = getchar();
  switch(c){
  case 'a':
    printf("春巻きです。\n");
    break;
  case 'b':
    printf("シューマイです。\n");
    break;
  default:
    printf("どちらでもありません。\n");
    break;
  }

  return (0);
}
