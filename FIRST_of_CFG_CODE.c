#include<stdio.h>
#include<ctype.h>

void FIRST(char);
int count, n = 0;
char prodn[10][10], first[10];

int main() {
    int i, choice;
    char c, ch;
    printf("How many productions ? :");
    scanf("%d", &count);
    printf("Enter %d productions epsilon= $ :\n\n", count);
    for(i = 0; i < count; i++)
        scanf("%s%c", prodn[i], &ch);
    do {
        n = 0;
        printf("Element :");
        scanf("%c", &c);
        FIRST(c);
        printf("\n FIRST(%c)= { ", c);
        for(i = 0; i < n; i++)
            printf("%c ", first[i]);
        printf("}\n");
        printf("press 1 to continue : ");
        scanf("%d%c", &choice, &ch);
    } while(choice == 1);
    return 0;
}

void FIRST(char c) {
    int j;
    if(!(isupper(c)))
        first[n++] = c;
    for(j = 0; j < count; j++) {
        if(prodn[j][0] == c) {
            if(prodn[j][2] == '$')
                first[n++] = '$';
            else if(islower(prodn[j][2]))
                first[n++] = prodn[j][2];
            else
                FIRST(prodn[j][2]);
        }
    }
}

/*OUTPUT
How many productions ? :8
Enter 8 productions epsilon= $ :

E=TD
D=+TD
D=$
T=FS
S=*FS
S=$
F=<E>
F=a
Element :E

 FIRST(E)= { < a }
press 1 to continue : 1
Element :D

 FIRST(D)= { + $ }
press 1 to continue : 1
Element :T

 FIRST(T)= { < a }
press 1 to continue : 1
Element :S

 FIRST(S)= { * $ }
press 1 to continue :
*/