#include <stdio.h>

void input(int arr[], int count) {
    for (int i = 0; i < count; i++) {
        printf("ENTER VALUE (%d) : ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main() {
    int max = -1;
    int rows;
    int count;

// INPUT
printf("______ ________\n\nINPUT  HANDLING \n______ ________\n\n");
    printf("ENTER NO. OF VALUES : ");
    scanf("%d", &count);
    int n[count];
    input(n, count);


//MAX

    for (int i = 0; i < count; i++) {
        if (n[i] > max ) {
            max = n[i];
        }
    }

    rows = max;

// VERTICAL Histogram
printf("\n\n________ _________\n\nVERTICAL HISTOGRAM \n________ _________\n\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < count; j++) {
            if (n[j] >= max) {
                printf(" *");
            } else {
                printf("  ");
            }
        }
        printf("\n");
        max--;
    }
    printf("\n");
for(int i=0;i<count;i++){
	printf(" %d",n[i]);
}
// HORIZONTAL Histogram
//5 5 4 3 4 5 5
printf("\n\n__________ _________\n\nHORIZONTAL HISTOGRAM \n__________ _________\n\n");


 for (int i = 0; i < count; i++) {
 	printf("%d | ",n[i]);
        for (int j = 0; j < n[i]; j++) {
           printf(" *");
    }
    printf("\n");

}
return 0;
}