#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pf printf

void main()
{
    char * str = (char *) malloc(200), * substr = (char *) malloc(200), t = ' ';
    int flag = 0, ctr = 0;
    pf("Enter a String.\n");
    fgets(str, 200, stdin);
    for(int i = 0; t!='\0'&&t!='\n'; i++)
    {
        t = str[i];
        while(t!=' '&&t!='\0'&&t!='\n')//gets the subarray
        {
            substr[ctr] = t;
            t = str[i+(++ctr)]; 
        }
        substr[ctr] = '\0';
        for(int j = 0; j<ctr/2; j++)
        {
            if(substr[j] != substr[ctr-1-j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            pf("%s ", substr);
        }
        i+=ctr;
        ctr = 0;
        flag = 0;
        free(str);
        free(substr);
    }
}