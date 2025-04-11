#include<stdio.h>
#include<windows.h>
#include<string.h>
struct Player {
	int totalScore =0;
	int ballScores[12];
	char playerName[20];
};
int validateScore(int score) {
	if(score <=6 && score>=0) {
		return score;
	}
	return 0;
}
void playGame(struct Player *player) {
	system("cls");
	int score;
	printf("ENTER NAME: ");
	fgets(player->playerName,20,stdin);
	if(player->playerName[strlen(player->playerName)-1] == '\n') {
		player->playerName[strlen(player->playerName)-1] =  '\0';
	}else{
		fflush(stdin);
	}
	for(int i=0; i<12; i++) {
		printf("ENTER SCORE BALL(%d): ",i+1);
		scanf("%d",&score);
		player->ballScores[i] = validateScore(score);
		player->totalScore  += player->ballScores[i];
	}
	fflush(stdin);
}
void findWinner(struct Player player1,struct Player player2) {
	if(player1.totalScore > player2.totalScore) {

		printf("\nWINNER : %s\n",player1.playerName);
	} else {
		printf("\nWINNER : %s\n",player2.playerName);
	}
}
void displayMatchScoreboard(struct Player player1,struct Player player2) {
	system("cls");
	printf("\nPLAYER 1\tPLAYER 2");
	printf("\n\n%s",player1.playerName);
	printf("\t\t%s\n\n",player2.playerName);
	printf("SCORES\t\tSCORES\n");
	for(int i=0; i<12; i++) {
		printf("%d\t\t%d\n",player1.ballScores[i],player2.ballScores[i]);
	}
	printf("\nTOTAL\t\tTOTAL\n");
	printf("%d\t\t%d\n\n",player1.totalScore,player2.totalScore);
	printf("\nAVERAGE\t\tAVERAGE\n");
	printf("%.2f\t\t%.2f\n\n",(float)(player1.totalScore)/12,(float)(player2.totalScore)/12);
}

int main() {
	struct Player player1,player2;
	playGame(&player1);
	printf("\n");
	playGame(&player2);
	findWinner(player1,player2);
	displayMatchScoreboard(player1,player2);
	return 0;
}