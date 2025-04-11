#include<stdio.h>
#include<math.h>
#include<string.h>
int counter = 0;

char *opt(char str[20]){
counter = 0;
char string[20];
strcpy(string,str);
static char cStr[20];

 for (int i = 0; i < 20; i++) {
        cStr[i] = '\0';
    }

int k =0;
int size = strlen(string);

for(int i=0;i<size;i++){
	
if(string[i] != string[i+1]){
	
	cStr[k] = string[i];
	
	k++;
	
}else{
	
	counter++;
}

cStr[k] = '\0';

}
return cStr;

}		

int main(){
int n;
printf("ENTER NUMBER OF WORDS:  ");
scanf("%d",&n);
char strings[n][20];
for(int i=0;i<n;i++){
	
	printf("ENTER WORD (%d):  ",i+1);
	scanf(" ");
	fgets(strings[i],20,stdin);
	
}






for(int i=0;i<n;i++){
	printf("\nOPTIMIZED WORD : %s",opt(strlwr(strings[i])));
	printf("\nNUMBER OF CHARACTERS REMOVED :  %d\n",counter);
}



	return 0 ;
}
