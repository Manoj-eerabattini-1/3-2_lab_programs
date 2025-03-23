#include<stdio.h>
#include<string.h>
char str[100];
void sort() {
    int i = 0, j = 0;
    int n = strlen(str);
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(str[j + 1] < str[j]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}
int main() {
    scanf("%s", &str);
    sort();
    for(int i = 0; i < strlen(str); i++) {
        printf("%c",str[i]);
    }
    return 0;
}