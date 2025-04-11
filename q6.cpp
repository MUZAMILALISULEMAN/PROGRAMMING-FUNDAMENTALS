#include<stdio.h>
#include<math.h>
int AtoWin(int n){
	if(n%5==0){
		return -1;
	}else{
		return n%5;
	}
}

int main(){
	int N;
	printf("ENTER NUMBER OF STICKS:  ");
	scanf("%d",&N);
	if(AtoWin(N) == -1){
		printf("IMPOSSIBLE FOR PLAYER 1 TO WIN");
	}else{
		printf("POSSIBLE FOR PLAYER 1 TO WIN");
	}
	return 0 ;
}
