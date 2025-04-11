#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
int validateEmail(char *email){
	int i=0;
	int atSymbol =0;
	int dotSymbol =0;
	while(*(email+i)!='\0'){
		if(*(email+i) == '@'){
			atSymbol++;
			if(*(email+i+1) == '.'){
				dotSymbol++;
			}
		}
		i++;
	}	
	if(atSymbol ==1 && dotSymbol > 0 &&  i>0){
		return 1;
	}
	return 0;
	
}int main() {
    char ch;
    char *string = (char *)malloc(sizeof(char)); 
    int size = 1;

    if (string == NULL) { 
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("ENTER STRING: ");
    while ((ch = getchar()) != '\n') { 
        string = (char *)realloc(string, (size + 1) * sizeof(char)); 
        if (string == NULL) { 
            printf("Memory allocation failed.\n");
            return 1;
        }
        string[size - 1] = ch; 
        size++;
    }

    string[size - 1] = '\0'; 
    if (validateEmail(string)) {
        printf("VALID EMAIL ADDRESS.\n");
    } else {
        printf("INVALID EMAIL ADDRESS.\n");
    }

    free(string);
    return 0;
}