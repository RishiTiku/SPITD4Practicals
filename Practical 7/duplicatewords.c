#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pf printf

void main()
{
    char * str = (char *) malloc(200), * substr = (char *) malloc(200), t = ' ', WORDS[30][200];
    int words = 0, flag = 0, ctr = 0;
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
        for(int j = 0; j<words; j++)
        {
            if(strcmpi(substr, WORDS[j])==0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            printf("%s ", substr);
            strcpy(WORDS[words], substr);
            words++;
        }
        i += ctr;
        ctr = 0;
        flag = 0;
    }
    free(str);
    free(substr);
    
}
