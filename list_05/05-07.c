#include <stdio.h>
#include <stdlib.h>

#define WIN_MENU 0

#if WIN_MENU

#define CMD_DIR "dir"
#define CMD_DATE "date"
#define CMD_PWD "cd"

#else

#define CMD_DIR "ls"
#define CMD_DATE "date"
#define CMD_PWD "pwd"

#endif

#define MAX_LINE 128

int main(void);

int main(void)
{
  char buf[MAX_LINE];

  for(;;){
    printf("メニュープログラム\n");
    printf("-----\n");
    printf("0 = 終了\n");
    printf("1 = ファイルの一覧表示(%s)\n", CMD_DIR);
    printf("2 = 今日の日付の表示(%s)\n", CMD_DATE);
    printf("3 = カレントディレクトリの表示(%s)\n", CMD_PWD);
    printf("-----\n");
    printf("番号でコマンドを入力してください。：");
    fflush(stdout);

    gets(buf);
    switch(atoi(buf)){
    case 0:
      return (0);
      break;
    case 1:
      system(CMD_DIR);
      break;
    case 2:
      system(CMD_DATE);
      break;
    case 3:
      system(CMD_PWD);
      break;
    default:
      printf("0　〜　3　の範囲で入力してください。\n");
      break;
    }
  }


  return (-1);
}
