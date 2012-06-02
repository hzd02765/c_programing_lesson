#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Q 20
#define MAX_LINE 128

int main(void);
void kuku(int questno);

int good_answers = 0;

int main(void)
{
  int i;
  float rate;

  srand((unsigned int)time(NULL));

  printf("これから九九の問題を　%d　問出します\n", MAX_Q);
  good_answers = 0;
  for(i = 0; i < MAX_Q; i++){
    kuku(i);
  }
  rate = good_answers * 100.0 / MAX_Q;
  printf("問題は　%d　問ありました。\n", MAX_Q);
  printf("%d　問は正しく答えられましたが、\n", good_answers);
  printf("%d　問は間違ってしまいました。\n", MAX_Q - good_answers);
  printf("正答率は　%0.1f %%です。\n", rate);
  printf("\n");
  printf("お疲れさま\n");

  return 0;
}

void kuku(int questno)
{
  int x, y, result;
  char buffer[MAX_LINE];

  x = rand() % 9 + 1;
  y = rand() % 9 + 1;
  printf("［第　%d　問］　%d × %d =", questno + 1, x, y);
  fflush(stdout);
  gets(buffer);
  result = atoi(buffer);
  if(x * y == result){
    printf("はい、正解です。\n");
    good_answers++;
  }else{
    printf("残念、まちがいです。\n");
  }
  printf("\n");
}
