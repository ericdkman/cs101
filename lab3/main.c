#include <stdio.h>

int my_strlen(char* s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        *s ++;
    }
    return count;
}

int main() {
    char s[] = "Manage len";
    printf("len = %d\n",my_strlen(s));
    return 0;
}
