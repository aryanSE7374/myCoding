#include <stdio.h>
#include <string.h>

int main() {
    int n = 5;
    printf("%d\n",n);
    char c = '5';
    printf("%c\n",c);
    if (n==c)
    {
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    


    /*
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        char str[101];
        scanf("%s", str);
        int len = strlen(str);
        if (len <= 10) {
            printf("%s\n", str);
        } else {
            printf("%c%d%c\n", str[0], len - 2, str[len - 1]);
        }
    }
    */
    return 0;
}
