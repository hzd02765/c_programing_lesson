#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE 256

#define MAX_DATA 500

double data[MAX_DATA];
int index = 0;
double sum_data;
double ave_data;
double max_data;
double min_data;
double mid_data;

int main(void);
void input_data(void);
void calc_stats(void);
void output_data(void);

int main(void)
{
  input_data();
  calc_stats();
  output_data();

  return (0);
}

void input_data(void)
{
  char buffer[MAX_LINE];

  while (gets(buffer) != NULL){
    if (index >= MAX_DATA){
      printf("処理できるデータ数を超えました。\n");
      printf("データ数は最大%d個です。\n", MAX_DATA);
      exit (-1);
    }else if(isdigit(buffer[0]) || buffer[0] == '.'){
      data[index] = (double)atof(buffer);
      index++;
    }else{
      printf("%s", buffer);
    }
  }
}

void calc_stats(void)
{
  int i, j;
  double tmp;

  sum_data = 0.0;
  for (i = 0; i < index; i++){
    sum_data += data[i];
  }

  ave_data = sum_data / index;

  if (index > 0){
    min_data = data[0];
    max_data = data[0];
  }

  for (i = 0; i < index; i++){
    if (min_data > data[i]){
      min_data = data[i];
    }
    if (max_data < data[i]){
      max_data = data[i];
    }
  }

  for (i = 0; i < index - 1; i++){
    for (j = i + 1; j < index; j++){
      if (data[i] > data[j]){
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
      }
    }
  }
  mid_data = data[index / 2];
}

void output_data(void)
{
  printf("データの個数　%d　\n", index);
  printf("合計　%g　\n", sum_data);
  printf("平均値　%g　\n", ave_data);
  printf("最大値　%g　\n", max_data);
  printf("最小値　%g　\n", min_data);
  printf("中央値　%g　\n", mid_data);
}
