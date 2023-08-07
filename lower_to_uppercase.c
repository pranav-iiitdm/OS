#include<stdio.h>
#include<string.h>

int main() {
    FILE * fp;
    char str[100];
    
    fp = fopen("Input1.txt","r");  // opening the file in read mode
    
    while(fgets(str, 10, fp) != NULL) { // fgets reads 9 characters at a time till the fp(file pointer) reaches the end of the file
        // printf("%s",str);
        for(int i=0;i<strlen(str);i++) {
            if(str[i] >= 65 && str[i] <= 90) {  // if the character is in upper case then then change it to lower case by adding 32 
                str[i] += 32;
                printf("%c",str[i]);
            }
            else if(str[i] >= 97 && str[i] <= 122) { // if the character is in lower case then then change it to upper case by subtracting 32 
                str[i] -= 32;
                printf("%c",str[i]);
            }
            else {
                printf("%c",str[i]);  // if there are any other characters like spaces,dots,digits etc they will be read by this condition
            }
        }
    }
    
    fclose(fp);  // closing the file
    
    return 0;
}