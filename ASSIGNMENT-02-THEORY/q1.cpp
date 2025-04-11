#include<stdio.h>
#include<math.h>

int main(){

int n =5;
//printf("ENTER NUMBER OF ELEMENTS :  ");
//scanf("%d",&n);
int values[n];
for(int i=0;i<n;i++){
	printf("Element %d :  ",i);
	scanf("%d",&values[i]);
	if(values[i] > 9999){
		printf("INVALID INPUT\n");
		printf("ELEMENT %d  :  ",i);
		scanf("%d",&values[i]);
	}
}

int s1 =values[0] ,max =9999,s2;
for(int i=0;i<n;i++){
	
	if(values[i] < s1){
	s1 = values[i];

	}
}

for(int i=0;i<n;i++){
	
	
	if(values[i] < max && values[i] > s1){
	s2 = values[i];

	}

}
if(n==1){
printf("Min = %d",s1);
}else{
printf("The Second smallest element in the array is : %d",s2);
			
	}

	return 0 ;
}
