#include <stdio.h>
int i,j;
//Function to print grid
void printGrid(char arr[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

//searching P In grid 
void search(char arr[5][5]) {
    for (int m = 0; m < 5; m++) {
        for (int n = 0; n < 5; n++) {
            if(arr[m][n] == 'P'){
            	
            	i=m;
            	j=n;
            	return;
			}
            
        }

    }
}
//Lowerize input
char tolwr(char a){
	char upr[5] = {'a','s','d','w','q'};
	if(a == upr[0] || a==upr[3]||a==upr[1]||a==upr[2] || a==upr[4]){
		return a;
	}
	switch(a){
		case 'A':
		return 'a';
		case 'S':
		return 's';
		case 'D':
		return 'd';
		case 'W':
		return 'w';
		case 'Q':
		return 'q';
	}
	return 0;
}
int main() {
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}}; 
    
	char d;
    int score = 0;
    int count = 0;
    

    // Displaying initial grid
    printGrid(grid);
    //Players position
	search(grid);

    while (d != 'q') {
        printf("ENTER THE DIRECTION (W,A,S,D,Q):  ");
        scanf(" %c", &d);
        d = tolwr(d);

        // Move up (w)....
        if (d == 'w' && i > 0 && (grid[i-1][j] == ' ' || grid[i-1][j] == 'I')) {
            if (grid[i-1][j] == 'I') {
                score++;  
            }
            grid[i-1][j] = grid[i][j];
            grid[i][j] = ' ';
            i--;  
            count++;  
            printGrid(grid);  
        }
        // Move down (s)....
        else if (d == 's' && i < 4 && (grid[i+1][j] == ' ' || grid[i+1][j] == 'I')) {
            if (grid[i+1][j] == 'I') {
                score++;
            }
            grid[i+1][j] = grid[i][j];
            grid[i][j] = ' ';
            i++;  
            count++;
            printGrid(grid);
        }
        // Move left (a)...
        else if (d == 'a' && j > 0 && (grid[i][j-1] == ' ' || grid[i][j-1] == 'I')) {
            if (grid[i][j-1] == 'I') {
                score++;
            }
            grid[i][j-1] = grid[i][j];
            grid[i][j] = ' ';
            j--;  
            count++;
            printGrid(grid);
        }
        // Move right (d)...
        else if (d == 'd' && j < 4 && (grid[i][j+1] == ' ' || grid[i][j+1] == 'I')) {
            if (grid[i][j+1] == 'I') {
                score++;
            }
            grid[i][j+1] = grid[i][j];
            grid[i][j] = ' ';
            j++;  
            count++;
            printGrid(grid);
        }
        // Result...
        else if (d == 'q') {
            printf("\n\n______________\n\n   SCORE: %d\n   STEPS: %d\n______________", score, count);
            break;
        }
        else {
            printf("\nINVALID MOVE\n");
        }
    }

    return 0;
}
