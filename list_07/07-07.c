#include <stdio.h>

#define MAX_LINES 60

#define TABS 4

int main(void);

int main(void)
{
  int c;
  int column = 0;
  long lines = 1L;

  printf("%8ld : ", lines);
  while((c = getchar()) != EOF){
    if(c == '\t'){
      do{
	putchar (' ');
	column++;
      } while (column % TABS != 0);
    }else if(c == '\n'){
	putchar(c);
	column = 0;
	lines++;
	if((lines - 1) % MAX_LINES == 0){
	  putchar('\f');
	}
	printf("%8ld : ", lines);
      }else{
	putchar(c);
	column++;
      }
  }

  putchar('\n');

  return(0);
}
