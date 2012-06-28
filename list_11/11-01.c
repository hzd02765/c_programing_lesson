#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICT_DIC "dict.dic"
#define MAX_LINE 128

char *usage[] = {
  "名前",
  "  dict - 辞書検索",
  "書式",
  "  dict 英単語",
  "解説",
  " プログラム(dict)は、英単語と日本語訳の書かれたファイル（辞書ファイル）",
  " を検索し、入力された英単語の日本語訳を表示するプログラムです。",
  " 辞書ファイルとして次のようなファイル(dict.dic)を用意します。",
  "",
  " dictionary 辞書",
  " English 英語",
  " foreign 外国の",
  " home 家",
  " end 終了",
  "",
  " そして、dict home と入力すると、",
  "  home 家",
  " と画面に表示します。",
  "作者",
  " 結城浩",
  " Copyright (c) 1994 by Hiroshi Yuki.",
  NULL,
};

#define MAX_EWORD 20
#define MAX_JWORD 20
struct word{
  char eword[MAX_EWORD+1];
  char jword[MAX_JWORD+1];
};

#define MAX_WORD 100
struct word data[MAX_WORD];
int max_word = 0;

int main(int argc, char *argv[]);
void fread_word(FILE *fp);

int main(int argc, char *argv[])
{
  int i;
  char eword[MAX_EWORD+1];
  FILE *fp;

  if (argc != 2){
    for (i = 0; usage[i] != NULL; i++){
      printf("%s\n", usage[i]);
    }
    return (0);
  }

  strcpy(eword, argv[1]);

  fp = fopen(DICT_DIC, "r");
  if (fp = NULL){
    fprintf(stderr, "辞書ファイル %s が見つかりません。\n", DICT_DIC);
    return (-1);
  }

  fread_word(fp);
  fclose(fp);

  for (i = 0; i < max_word; i++){
    if (strcmp(data[i].eword, eword) == 0){
      printf("%s %s\n", data[i].eword, data[i].jword);
    }
  }
  return (0);
}

void fread_word(FILE *fp)
{
  int i;
  char buffer[MAX_LINE];
 
  for (i = 0; fgets(buffer, MAX_LINE, fp) != NULL; i++){
    if (i >= MAX_WORD){
      fprintf(stderr, "単語数が多すぎます(最大 %d 人)\n", MAX_WORD);
      fclose(fp);
      exit(-1);
    }
    if (sscanf(buffer, "%s %s\n", data[i].eword, data[i].jword) != 2){
      fprintf(stderr, "%d 行目でデータの読み書きエラーになりました。\n", i + 1);
      fclose(fp);
      exit(-1);
    }
  }
  max_word = i;
}
