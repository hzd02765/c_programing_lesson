#include <stdio.h>

int main(void);

int main(void)
{
  int c;
  long lines = 0L;

  while ((e = getchar() != EOF){
      if( e == '\n'){
	lines++;
      }
    }
    printf("Lines = %d\n", lines);

  return (0);
}
