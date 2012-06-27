#include <stdio.h>
#include <stdlib.h>

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

int main(void);
void read_data(void);
void sort_by_id(void);
void sort_by_total(void);
void print_data(void);
void print_stat(void);

int main(void)
{
  read_data();
  printf("\n");
  printf("== 学生数 ==\n");
  printf("%d 人\n", max_student);

  if (max_student <= 0){
    printf("データ数が少なすぎます。\n");
    return (-1);
  }

  printf("\n");
  printf("== 出席番号順の名簿 ==\n");
  sort_by_id();
  print_data();

  printf("\n");
  printf("== 合計点による成績順位表 ==\n");
  sort_by_total();
  print_data();

  printf("\n");
  printf("== 平均点・最高点・最底辺 ==\n");
  print_stat();

  return (0);
}

void read_data(void)
{
  int i = 0, j;
  char buffer[MAX_LINE];

  while (gets(buffer) != NULL){
    if (i >= MAX_DATA){
      printf("学生数が多すぎます(最大 %d 人)\n", MAX_DATA);
    }
    
    if (sscanf(buffer, "%d %s %d %d %d %d %d\n",
	       &data[i].id,
	       &data[i].name[0],
	       &data[i].ten[0],
	       &data[i].ten[1],
	       &data[i].ten[2],
	       &data[i].ten[3],
	       &data[i].ten[4] ) != 7){
      printf("%d 行目でデータの読み込みエラーになりました。\n", i + 1);
      printf("%s", buffer);
      exit(-1);
    }

    data[i].total = 0;
    for (j = 0; j < MAX_TEN; j++){
      data[i].total += data[i].ten[j];
    }
    i++;
  }
  max_student = i;
}

void sort_by_id(void)
{
  int i, j;
  struct student tmp;

  for (i = 0; i < max_student - 1; i++){
    for (j = i + 1; j < max_student; j++){
      if (data[i].id > data[j].id){
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
      if(data[i].total < data[j].total){
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
      }
    }
  }
}

void print_data(void)
{
  int i, j;
  
  for (i = 0; i < max_student; i++){
    printf("%3d) %3d %-10s ", i + 1, data[i].id, data[i].name);
    for (j = 0; j < MAX_TEN; j++){
      printf("%3d ", data[i].ten[j]);
    }

    printf(" 合計点 %3.0f", data[i].total);
    printf(" 平均的 %3.1f", data[i].total / MAX_TEN);
    printf("\n");
  }
}

void print_stat(void)
{
  int max[MAX_TEN];
  int min[MAX_TEN];
  double ten[MAX_TEN];
  double total;
  int i, j;

  for (j = 0; j < MAX_TEN; j++){
    max[j] = data[0].ten[j];
    min[j] = data[0].ten[j];
    ten[j] = data[0].ten[j];
  }

  total = data[0].total;

  for ( i = 1; i < max_student; i++){
    for (j = 0; j < MAX_TEN; j++){
      if (max[j] < data[i].ten[j]){
	max[j] = data[i].ten[j];
      }
      if (min[j] > data[i].ten[j]){
	min[j] = data[i].ten[j];
      }
      ten[j] += data[i].ten[j];
    }
    total += data[i].total;
  }

  for (j = 0; j < MAX_TEN; j++){
    printf("教科 %d : 最高点 %3d, 最低点 %3d, 平均点 %3.1f\n",
	   j + 1, max[j], min[j], ten[j] / max_student);
  }
  printf("合計点の平均 %3.1f\n", total / max_student);
}
