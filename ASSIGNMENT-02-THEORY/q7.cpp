#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
char randChar(){
	int n = rand()%26;
	char ch = 'A' + n;
	
	return ch;
}

void fillGrid(char grid[6][5]){
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			grid[i][j] = randChar();
			
		}
		
	}
	
	grid[5][4] = 'K';
	grid[5][0] = '1';
	grid[5][1] = '0';
	grid[5][2] = '2';
	grid[5][3] = '3';
	
}

void printGrid(char grid[6][5]){
	for(int i=0;i<6;i++){
		for(int j=0;j<5;j++){
			printf("%c ",grid[i][j]);		
		}
		printf("\n");
	}
}


int inBound(int i, int j, int n,int k) {
  return (i >= 0 && i < n) && (j >= 0 && j < k);
}

int main() {

srand(time(NULL));
char grid[6][5];
fillGrid(grid);
printGrid(grid);


  char target[101], t = target[0];
  int check = 0, k = 0,p=0, found = 0, choice = 1,score = 0;

  while (choice != 0) {

    printf("\n\nDO YOU WANT TO PLAY(1,0) :  ");
    scanf("%d", &choice);
    if (choice != 1) {
      break;
    }
    printf("\nENTER THE SUBSTRING(CHARACTERS > 1) :  ");
    scanf("%s", &target);
    strupr(target);
    t = target[0];
    if(!(strcmp(target,"END"))){
    	fillGrid(grid);
    	printf("\n");
    	printGrid(grid);
		break;
	}
    
    

int size = strlen(target);
for (int i = 0; i < 6; i++) {
  for (int j = 0; j < 5; j++) {
    if (grid[i][j] == t) {
      k = 0;
      check = 0;
      //checking downwards
      for (int row = i; row <size; I++) {
        if (!inBound(row, j, 6,5)) {
          break;
        }
        if (grid[I][j] == target[k]) {
          k++;
          check++;
        } else {
          break;
        }
      }
      if (check == size && size > 1) {
        found = 1;
        goto out;
      }

      
       k=0;
      check = 0;
      for (int I = j; I < size ; I++) {
        if (!inBound(i, I, 6,5)) { 
          break;
        }
        if (grid[i][I] == target[k]) {
          k++;
          check++;
        } else {
          break;
        }
      }
      if (check == size && size > 1) {
        found = 1;
        goto out;
      }
    }
  }
}


    out:
      if (found == 1) {

        printf("\nFOUND\n");
        found = 0;

        score++;
        printf("\nSCORE :  %d", score);
      } else if (found == 0) {

      printf("\nNOT FOUND!\n");
      if (score > 0) {
        score--;
      }
      printf("\nSCORE :  %d", score);

    }

  }
  return 0;
}