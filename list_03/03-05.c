#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

int main(void);

int main(void)
{
  char buffer[MAXLINE];
  int age;

  printf("あなたの名前を入力してください。\n");
  gets(buffer);
  printf("%sさん、こんにちは。\n", buffer);

  printf("年齢を入力してください。\n");
  gets(buffer);
  age = atoi(buffer);
  printf("今　%d　歳とすると、１０年後は　%d　歳ですね。\n", age, age + 10);

  return (0);
}
