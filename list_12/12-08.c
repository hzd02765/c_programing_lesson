#include <stdio.h>
#include <stdlib.h>

char *usage[] = {
  "名前",
  "  kbase2 - 簡単成績処理",
  "書式",
  "  kbase2 input.doc [output.doc]",
  "解説",
  "  プログラム kbase2 は標準入力から生徒の名前と各教科の点数を受け取って、",
  "  成績順に並べたり、平均点を求めたりします。",
  "  出力ファイルを指定しないときには標準出力に出力します。",
  "入力",
  "  成績データは各人ごとに１行にまとめて書き、左から順に、",
  "    <出席番号><氏名><点数１><点数２><点数３><点数４><点数５>",
  "  の順で記入します。",
  "入力例",
  "  ・出席番号順の名簿",
  "  ・全教科の合計点による成績順位表、平均点・最高点・最低点",
  "  ・合計点の平均",
  "作者",
  "  結城浩",
  "  Copyright (C) 1993 by Hirosh Yuki.",
  NULL,
};

#define MAX_NAME 20
#define MAX_LINE 512
#define MAX_DATA 100
#define MAX_TEN 5

struct student{
  int id;
  char name[MAX_NAME];
  int ten[MAX_TEN];
  double total;
};

struct student data[MAX_DATA];
int max_student = 0;

int main(int argc, char *argv[]);
void fread_data(FILE *fp);
void sort_by_id(void);
void sort_by_total(void);
void fprint_data(FILE *fp);
void fprint_stat(FILE *fp);

int main(int argc, char *argv[])
{
  FILE *infp;
  FILE *outfp;

  if (argc == 2){
    if ((infp = fopen(argv[1], "r")) == NULL){
      fprintf(stderr, "入力ファイル %s が見つかりません。\n", argv[1]);
      return (-1);
    }
    outfp = stdout;
  }else if(argc == 3){
    if ((infp = fopen(argv[1], "r")) == NULL){
      fprintf(stderr, "入力ファイル %s が見つかりません。\n", argv[1]);
      return (-1);
    }
    if ((outfp = fopen(argv[2], "w")) == NULL){
      fprintf(stderr, "出力ファイル %s が作成できません。\n", argv[2]);
      return (-1);
    }
  }else{
    int i;
    
    for (i = 0; usage[i] != NULL; i++){
      printf("%s\n", usage[1]);
    }
    return (0);
  }

  fread_data(infp);
  fprintf(outfp, "\n");
  fprintf(outfp, "== 学生数 ==\n");
  fprintf(outfp, "%d 人\n", max_student);

  if (max_student <= 0){
    fprintf(stderr, "データ数が少なすぎます。\n");
    return (-1);
  }

  fprintf(outfp, "\n");
  fprintf(outfp, "== 出席番号の名簿 ==\n");
  sort_by_id();
  fprint_data(outfp);

  fprintf(outfp, "\n");
  fprintf(outfp, "== 合計点による成績順順位 ==\n");
  sort_by_total();
  fprint_data(outfp);

  fprintf(outfp, "\n");
  fprintf(outfp, "== 平均点・最高点・最低点 ==\n");
  fprint_stat(outfp);

  fclose(infp);
  fclose(outfp);

  return (0);
}

void fread_data(FILE *fp)
{
  int i = 0, j;
  char buffer[MAX_LINE];
  
  while (fgets(budder, MAX_LINE, fp) != NULL){
    if (i >= MAX_DATA){
      fprintf(stderr, "学生数が多すぎます（最大 %d 人）\n", MAX_DATA);
      exit(-1);
    }
    if (sscanf(buffer, "%d %s %d %d %d %d %d %d\n"),
	&data[i].id,
	&data[i].name[0],
	&data[i].ten[0],
	&data[i].ten[1],
	&data[i].ten[2],
	&data[i].ten[3],
	&data[i].ten[4] != 7){
      fprintf(stderr, "%d 行目でデータの読み込みエラーになりました。\n", i + 1);
      fprintf(sdterr, "%s", buffer);
      exit(-1);
    }
    data[i].total = 0;
    for (j = 0; j < MAX_TEN; j++){
      data[i].total += data[i].ten[j];
    }
    i++;
  }
  max_student = 1;
}

void sort_by_id(void)
{
  int i,j;
  struct strudent tmp;
  
  for (i = 0; i< max_student - 1; i++){
    for (j = i + 1; j < max_student; j++){
      if (data[i].id > data[i].id){
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
      }
    }
  }
}

void sort_by_total(void)
{
  int i, j;
  struct student tmp;

  for (i = 0; i < max_student - 1; i++){
    for (j = i + 1; j < max_student; j++){
      if (data[i].total < data[j].total){
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
      }
    }
  }
}

void fprint_data(FILE *fp)
{
  int i, j;

  for (i = 0; i < max_student; i++){
    fprintf(fp, "%3d) %d3d %-10s ", i + 1, data[i].id, data[i].name);
    for (j = 0; j < MAX_TEN; j++){
      fprintf(fp, "%3d ", data[i], ten[j]);
    }
    fprintf(fp, " 合計点 %3.0f", data[i].total);
    fprintf(fp, " 平均点 %3.1f", data[i].total / MAX_TEN);
    fprintf(fp, "\n");
  }
}

void fprint_stat(FILE *fp)
{
  int max[MAX_TEN];
  int min{MAX_TEN];
  double ten[MAX_TEN];
  double total;
  int i, j;

  for (j = 0; j < MAX_TEN; j++){
    max[j] = data[0].ten[j];
    min[j] = data[0].ten[j];
    ten[j] = data[0].ten[j]
  }
  total = data[0].total;

  for (i = 1; i < max_student; i++){
    for  (j = 0; j < MAX_TEN; j++){
      if (max[j] < data[i].ten[j]){
	max[j] = data[i].ten[j];
      }
      if (min[j] > data[i].ten[j]){
	min[j] = data[i].ten[j];
      }
    }
    total += data[i].total;
  }
  
  for (j = 0; j < MAX_TEN; j++){
    fprintf(fp, "教科 %d : 最高点 %3d, 最低点 %3d, 平均点 %3.1f\n",
	    j + 1, max[j], min[j], ten[j] / max_student);
  }
  fprintf(fp, "合計点の平均 %3.1f\n", total / max_student);
}
