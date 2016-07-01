//gcc snake.c -o snake.run -lncurses
//./snake.run

//up 65
//down 66
//right 67
//left 68
//enter 10

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#define coordinate(x,y) printf("\033[%d;%dHS", (x), (y)) + puts("")

int main(void)
{
  initscr();  //i dont know neither of them
  noecho();

  int input = 0;

  int x = 0;  //int coordinates
  int y = 0;

  char * lastAction = malloc(10);  //if snake moves down, it can't move up anymore until it goes left or right

  while(1){
    input = getch();

    switch (input) {
      case 65:
      if(x > 0 && strcmp(lastAction,"down")!=0){
        x--;
        strcpy(lastAction,"up");
      }
      break;

      case 66:
      if(strcmp(lastAction,"up")!=0){
        x++;
        strcpy(lastAction,"down");
      }
      break;

      case 67:
      if(strcmp(lastAction,"left")!=0){
        y++;
        strcpy(lastAction,"right");
      }
      break;

      case 68:
      if(y>0 && strcmp(lastAction,"right")!=0){
        y--;
        strcpy(lastAction,"left");
      }
      break;

      case 10:
      printf("%s\n", "GoodBye");
      endwin();
      nocbreak();
      exit(0);
      break;
    }
    coordinate(x, y);
  }

  return 0;
}
