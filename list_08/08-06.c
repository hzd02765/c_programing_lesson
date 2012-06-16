#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GUU 0
#define CHO 1
#define PAA 2
#define HANDS 3

void learn(int lasthand, int curhand);
int guess(int curhand);
int winhand(int hand);
void printhand(int hand);
int judge(int hand1, int hand2);
void printbothands(int chand, int mhand);
int main(void);

void learn(int lasthand, int curhand)
{
}

int guess(int curhand)
{
  return (rand() % HANDS);
}

int winhand(int hand)
{
  if (hand == GUU){
    return (PAA);
  }
  else if (hand == CHO){
    return (GUU);
  }
  else if (hand == PAA){
    return (CHO);
  }
  else{
    printf("関数　winhand(%d)　に異常な値が渡されました。\n", hand);
    exit (-1);
  }
}

void printhand(int hand)
{
  if (hand == GUU){
    printf("グー");
  }
  else if (hand == CHO){
    printf("チョキ");
  }
  else if (hand == PAA){
    printf("パー");
  }
  else{
    printf("関数　printhand(%d)　に異常な値が渡されました。\n", hand);
    exit(-1);
  }
}

int judge(int hand1, int hand2)
{
  if (hand1 == hand2){
    return (0);
  }
  else if (hand1 == winhand(hand2)){
    return (1);
  }
  else if (winhand(hand1) == hand2){
    return (2);
  }
  else{
    printf("関数　judge(%d, %d)　に異常な値が渡されました。\n", hand1, hand2);
    exit(-1);
  }
}

void printbothhands(int chand, int mhand)
{
  printf("コンピュータは");
  printhand(chand);
  printf(" , ");
  printf("あなたは");
  printhand(mhand);
  printf("です。\n");
}

int main(void)
{
  int wincom = 0;
  int winman = 0;
  int ndraw = 0;
  int hand = 0;
  int lasthand = 0;
  int myhand = 0;
  int i, winner;
  char buffer[255];
  char c;
  
  printf("ジャンケンをしましょう。\n");
  printf("グーなら 1, チョキなら 2, パーなら 3 を入力してください。\n");
  printf("やめるときは　0　を入力してください。\n");

  for(i = 0; i < 1000; i++){
    myhand = winhand(guess(hand));
    printf("ジャンケン・・・\n");
    gets(buffer);
    c = buffer[0];

    hand = c - '0' - 1;
    if (c == '0'){
      printf("やめたっと\n");
      break;
    }
    else if ('1' <= c && c <= '3'){
      printf("ポン！\n");
      winner = judge(myhand, hand);
      printbothhands(myhand, hand);
      if (winner == 1){
	wincom++;
	printf("コンピュータの勝ち！\n");
      }
      else if (winner == 2){
	winman++;
	printf("あなたの勝ち！\n");
      }
      else {
	ndraw++;
	printf("あいこ・・・\n");
      }
      printf("コンピュータ　%d　勝、あなた　%d　勝、引き分け　%d\n", wincom, winman, ndraw);
      learn(lasthand, hand);
      lasthand = hand;
    }
    else {
      printf("？？？\n");
      printf("0, 1, 2, 3 のどれかのキーを押すのですよ。");
    }
    printf("\n");
  }
  if (wincom > winman * 2){
    printf("コンピュータは賢いでしょう？\n");
  }
  else if (winman > wincom * 2){
    printf("コンピュータ、完全敗北・・・\n");
  }
  else {
    printf("また遊んでね！\n");
  }

  return (0);
}
