#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]);
void print_greeting(int hour, int min);
void print_time(struct tm *tp);

void print_greeting(int hour, int min)
{
  if((22 <= hour && hour < 24) || (0 <= hour && hour < 4)){
    printf("遅くまでご苦労さま。\n");
  }else if(hour < 7){
    printf("ずいぶんお早いですね。\n");
  }else if(hour < 12){
    printf("おはようございます。\n");
  }else if(hour < 15){
    printf("こんにちわ。\n");
  }else if(hour < 18){
    printf("のんびりいきましょう。\n");
  }else if(hour < 22){
    printf("こんばんわ。\n");
  }else{
    printf("%02d　時　%02d　分とは変な時刻ですね。\n", hour , min);
  }
  if(0 <= min && min < 10){
    if(6 <= hour && hour < 9){
      printf("朝ごはんは食べましたか？\n");
    }else if(hour == 12){
      printf("昼ごはんは食べましたか？\n");
    }else if(18 <= hour && hour < 21){
      printf("夕ごはんは食べましたか？\n");
    }
  }
}

int main(int argc, char *argv[])
{
  time_t now;
  struct tm *tp;
  int hour, min;
  
  if(argc == 1){
    now = time(NULL);
    tp = localtime(&now);
    printf("現在は ");
    print_time(tp);
    print_greeting(tp->tm_hour, tp->tm_min);
  }else{
    sscanf(argv[1], "%02d:%02d", &hour, &min);
    printf("指定された時刻は　%02d　時　%02d　分です。\n", hour, min);
    print_greeting(hour, min);
  }
}

char *weekday[] = {"日", "月", "火", "水", "木", "金", "土"};

void print_time(struct tm *tp)
{
  printf("%d　年　%d　月　%d　日（%s）",
	 tp->tm_year + 1900,
	 tp->tm_mon + 1,
	 tp->tm_mday,
	 weekday[tp->tm_wday]);
  printf("%02d　時　%02d　分　%d　秒です。\n",
	 tp->tm_hour,
	 tp->tm_min,
	 tp->tm_sec);
}
