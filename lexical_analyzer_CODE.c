#include <stdio.h>
#include <ctype.h>
#include <string.h>

void keyword(char str[10])
{
    if(strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 ||
       strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 ||
       strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 ||
       strcmp("case", str) == 0)
    {
        printf("\n%s is a keyword", str);
    }
    else
    {
        printf("\n%s is an identifier", str);
    }
}

int main()
{
    FILE *f1, *f2, *f3;
    char c, str[10];
    int num[100], lineno = 1, tokenvalue = 0, i = 0, j = 0, k = 0;

    printf("\n Enter the C program (press Ctrl+D to end input):\n");

    f1 = fopen("input", "w");

    while ((c = getchar()) != EOF)
    {
        putc(c, f1);
    }

    fclose(f1);
    f1 = fopen("input", "r");
    f2 = fopen("identifier", "w");
    f3 = fopen("specialchar", "w");

    while ((c = getc(f1)) != EOF)
    {
        if (isdigit(c))
        {
            tokenvalue = c - '0';
            c = getc(f1);
            while (isdigit(c))
            {
                tokenvalue = tokenvalue * 10 + (c - '0');
                c = getc(f1);
            }
            num[i++] = tokenvalue;
            ungetc(c, f1);
        }
        else if (isalpha(c))
        {
            putc(c, f2);
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$')
            {
                putc(c, f2);
                c = getc(f1);
            }
            putc(' ', f2);
            ungetc(c, f1);
        }
        else if (c == ' ' || c == '\t')
        {
            
        }
        else if (c == '\n')
        {
            lineno++;
        }
        else
        {
            putc(c, f3);
        }
    }

    fclose(f2);
    fclose(f3);
    fclose(f1);

    printf("\n The numbers in the program are: ");
    for (j = 0; j < i; j++)
    {
        printf("%d ", num[j]);
    }
    printf("\n");

    f2 = fopen("identifier", "r");
    k = 0;
    printf("The keywords and identifiers are:");
    while ((c = getc(f2)) != EOF)
    {
        if (c != ' ')
        {
            str[k++] = c;
        }
        else
        {
            str[k] = '\0';
            keyword(str);
            k = 0;
        }
    }
    fclose(f2);

    f3 = fopen("specialchar", "r");
    printf("\nSpecial characters are: ");
    while ((c = getc(f3)) != EOF)
    {
        printf("%c ", c);
    }
    printf("\n");
    fclose(f3);

    printf("Total number of lines are: %d\n", lineno);

    return 0;
}

/* OUTPUT 
(NOTE : don't run the program it doesn't work just cut & paste the output in online c compiler)


Enter the C program (press Ctrl+D to end input):
#include <stdio.h>

int main() {
    int a = 10, b = 20;
    float c = 3.14;
    char d = 'A';
    if (a < b) {
        printf("a is less than b\n");
    }
    return 0;
}

The numbers in the program are: 10 20 3 14

The keywords and identifiers are:
int is a keyword
main is an identifier
int is a keyword
a is an identifier
b is an identifier
float is a keyword
c is an identifier
char is a keyword
d is an identifier
if is a keyword
a is an identifier
b is an identifier
printf is an identifier
return is a keyword

Special characters are: # < > ( ) { } = , ; = , ; = ' ' ( ) { < ) { ( ) " } } }

Total number of lines are: 12

*/