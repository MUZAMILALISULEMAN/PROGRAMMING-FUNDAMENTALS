#include <stdio.h>
#include <math.h>
#include <string.h>	
			


int* freq(char arr[4]) {
    static int freq[26] = {0};
     for (int i = 0; i < 26; i++) {
        freq[i] = 0;
    }    
    for (int i = 0; i < strlen(arr); i++) {
        freq[arr[i] - 'a'] += 1;
    }
    return freq;
}

void arrcopy(int arr[], int arr2[]) {
    for (int i = 0; i < 26; i++) {
        arr[i] = arr2[i];
    }
}

int cmp(char arr1[], char arr2[]) {
    int freq1[26] = {0};
    int freq2[26] = {0};
    arrcopy(freq1, freq(arr1));
    arrcopy(freq2, freq(arr2));
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char arr[6][4]= {"eat", "tea", "tan", "ate", "nat", "bat"};
     int checkstatus[] = {0, 0, 0, 0, 0, 0};
 printf("[");
      for (int i = 5; i >=0 ; i--) {
        if (checkstatus[i] == 0) {  
            checkstatus[i] = 1;
            printf("['%s',", arr[i]);
            
            for (int j = 5; j >= 0; j--) {  
                if (checkstatus[j] == 0 && cmp(arr[i], arr[j])) {
                    checkstatus[j] = 1;  
                    printf("'%s',", arr[j]);
                    }
            }
            printf("\b]");
            printf(",");
        }
    }
        printf("\b]");
        return 0;

}
