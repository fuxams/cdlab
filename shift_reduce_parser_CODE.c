#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ip_sym[15], stack[15];
int ip_ptr = 0, st_ptr = 0, len, i;
char temp[2], temp2[2];
char act[15];

int check();

int main() {
    printf("\n\t\t SHIFT REDUCE PARSER\n");
    printf("\n GRAMMAR\n");
    printf("\n E->E+E\n E->E/E");
    printf("\n E->E*E\n E->a/b");
    printf("\n enter the input symbol:\t");
    gets(ip_sym);
    printf("\n\t stack implementation table");
    printf("\n stack\t\t input symbol\t\t action");
    printf("\n______\t\t ____________\t\t ______\n");
    printf("\n $\t\t%s$\t\t\t--", ip_sym);
    strcpy(act, "shift ");
    temp[0] = ip_sym[ip_ptr];
    temp[1] = '\0';
    strcat(act, temp);
    len = strlen(ip_sym);
    for (i = 0; i <= len - 1; i++) {
        stack[st_ptr] = ip_sym[ip_ptr];
        stack[st_ptr + 1] = '\0';
        ip_sym[ip_ptr] = ' ';
        ip_ptr++;
        printf("\n $%s\t\t%s$\t\t\t%s", stack, ip_sym, act);
        strcpy(act, "shift ");
        temp[0] = ip_sym[ip_ptr];
        temp[1] = '\0';
        strcat(act, temp);
        check();
        st_ptr++;
    }
    check();
}

int check() {
    int flag = 0;
    temp2[0] = stack[st_ptr];
    temp2[1] = '\0';
    if (isalpha(temp2[0])) {
        stack[st_ptr] = 'E';
        printf("\n $%s\t\t%s$\t\t\tE->%s", stack, ip_sym, temp2);
        flag = 1;
    }
    if ((!strcmp(temp2, "+")) || (!strcmp(temp2, "*")) || (!strcmp(temp2, "/"))) {
        flag = 1;
    }
    if ((!strcmp(stack, "E+E")) || (!strcmp(stack, "E/E")) || (!strcmp(stack, "E*E"))) {
        if (!strcmp(stack, "E+E")) {
            strcpy(stack, "E");
            printf("\n $%s\t\t%s$\t\t\tE->E+E", stack, ip_sym);
        } else if (!strcmp(stack, "E/E")) {
            strcpy(stack, "E");
            printf("\n $%s\t\t %s$\t\t\tE->E/E", stack, ip_sym);
        } else {
            strcpy(stack, "E");
            printf("\n $%s\t\t%s$\t\t\tE->E*E", stack, ip_sym);
        }
        flag = 1;
        st_ptr = 0;
    }
    if (!strcmp(stack, "E") && ip_ptr == len) {
        printf("\n $%s\t\t%s$\t\t\tACCEPT", stack, ip_sym);
        exit(0);
    }
    if (flag == 0) {
        printf("\n $%s\t\t%s$\t\t\tReject", stack, ip_sym);
        exit(0);
    }
    return 0;
}

/*OUTPUT
                 SHIFT REDUCE PARSER

 GRAMMAR

 E->E+E
 E->E/E
 E->E*E
 E->a/b
 enter the input symbol:    a+a

         stack implementation table
 stack           input symbol           action
______           ____________           ______

 $               a+a$                   --
 $a              +a$                    shift +
 $E              +a$                    E->a
 $E+             a$                     shift a
 $E+a            $                      shift 
 $E+E            $                      E->E+a
 $E              $                      E->E+E
 $E              $                      ACCEPT
*/