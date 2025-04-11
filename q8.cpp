#include <stdio.h>
#include <math.h>
#include <string.h>

int BinarytoDecimal(int bin) {
    int ans = 0, i = 0, last_digit;
    while (bin > 0) {
        last_digit = bin % 10;
        ans += last_digit * pow(2, i);
        i++;
        bin /= 10;
    }
    return ans;
}

int DecimaltoBinary(int dec) {
    int binary = 0, i = 0, rem;
    while (dec > 0) {
        rem = dec % 2;
        binary += rem * pow(10, i);
        i++;
        dec /= 2;
    }
    return binary;
}

void HexadecimaltoDecimal(char hex[]) {
    int s = strlen(hex);
    int ans = 0, j = 0, d;
    for (int i = s - 1; i >= 0; i--) {
        if (hex[i] >= 'A' && hex[i] <= 'F') {
            d = hex[i] - 'A' + 10;
        } else {
            d = hex[i] - '0';
        }
        ans += d * pow(16, j);
        j++;
    }
    printf("%d", ans);
}

void DecimaltoHexadecimal(int dec) {
    int arr[30] = {0};
    char vars[17] = "0123456789ABCDEF";
    char str[31] = "";
    int n = dec, rem, i = 0, j = 0;
    while (n >= 16) {
        rem = n % 16;
        n /= 16;
        arr[i++] = rem;
    }
    arr[i] = n;
    for (int k = i; k >= 0; k--) {
        str[j++] = vars[arr[k]];
    }
    str[j] = '\0';
    printf("%s", str);
}

void BinarytoHexadecimal(int d) {
    int n = BinarytoDecimal(d);
    DecimaltoHexadecimal(n);
}

void HexadecimaltoBinary(char hex[]) {
    int s = strlen(hex);
    int ans = 0, j = 0, d;
    for (int i = s - 1; i >= 0; i--) {
        if (hex[i] >= 'A' && hex[i] <= 'F') {
            d = hex[i] - 'A' + 10;
        } else {
            d = hex[i] - '0';
        }
        ans += d * pow(16, j);
        j++;
    }
    printf("%d", DecimaltoBinary(ans));
}

int main() {
    int choice = 1, input = 0;
    char inputstr[20];
    while (choice != 0) {
        printf("\n1.DECIMAL TO BINARY\n2.BINARY TO DECIMAL\n3.DECIMAL TO HEXADECIMAL\n4.HEXADECIMAL TO DECIMAL\n5.BINARY TO HEXADECIMAL\n6.HEXADECIMAL TO BINARY\n7.EXIT\n");
        printf("\nENTER THE CHOICE :  ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("ENTER NUMBER :   ");
                scanf("%d", &input);
                printf("\nDECIMAL (%d) => BINARY (%d)\n", input, DecimaltoBinary(input));
                break;
            case 2:
                printf("ENTER NUMBER :   ");
                scanf("%d", &input);
                printf("\nBINARY (%d) => DECIMAL (%d)\n", input, BinarytoDecimal(input));
                break;
            case 3:
                printf("ENTER NUMBER :   ");
                scanf("%d", &input);
                printf("\nDECIMAL (%d) => HEXADECIMAL (", input);
                DecimaltoHexadecimal(input);
                printf(")\n");
                break;
            case 4:
                printf("ENTER HEXADECIMAL :   ");
                scanf("%s", inputstr);
                printf("\nHEXADECIMAL (%s) => DECIMAL (", inputstr);
                HexadecimaltoDecimal(inputstr);
                printf(")\n");
                break;
            case 5:
                printf("ENTER BINARY NUMBER :   ");
                scanf("%d", &input);
                printf("\nBINARY (%d) => HEXADECIMAL (", input);
                BinarytoHexadecimal(input);
                printf(")\n");
                break;
            case 6:
                printf("ENTER HEXADECIMAL :   ");
                scanf("%s", inputstr);
                printf("\nHEXADECIMAL (%s) => BINARY (", inputstr);
                HexadecimaltoBinary(inputstr);
                printf(")\n");
                break;
            case 7:
            	goto end;
            default:
                printf("Invalid choice.\n");
        }
    }
    end:
    	printf("\nPROGRAM TERMINATED......\n");
    	return 0;
}
