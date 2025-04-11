#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
void print(char data[]){
int freq[27] = {0};
char alphabets[27] = {0};
char k =  'a';

for(int i =0;data[i] != '\0';i++){
	
		if(data[i] >= 'a' && data[i] <= 'z'){
			freq[data[i] - k]++;
				
		}else if(data[i] == ' '){
			freq[26]++;
		}
}
	
for(int i=0;data[i]!='\0';i++){
	if(i==0){
		printf("{");
	}
	
if(data[i] >= 'a' && data[i] <= 'z'){
if(alphabets[data[i] - k]  == 0){
	alphabets[data[i]-k] = 1;
	printf(" '%c':%d",data[i],freq[data[i]-k]);
} 
}else{
	if(data[i] == ' ' && alphabets[26] == 0){
		alphabets[26] = 1;
		printf(" ' ':%d",freq[26]);
	}
}
}
printf(" }\n");
	
	
}



int main(){
int n;
printf("ENTER NO. OF SLOGANS:  ");
scanf("%d",&n);
char slogans[n][100];

for(int i=0;i<n;i++){
	
	printf("\nENTER SLOGAN(%d) :  ",i+1);
	scanf(" ");
	fgets(slogans[i], 100,stdin); 
	strcpy(slogans[i],strlwr(slogans[i]));
}
printf("\n");

for(int i=0;i<n;i++){
	print(slogans[i]);
}
return 0;
}
