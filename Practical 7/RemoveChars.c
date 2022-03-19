#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

void main()
{
    char * istr = (char* ) malloc(100),* ostr = (char*) malloc(100), t = ' ';
    pf("Enter a String.\n");
    fgets(istr, 100, stdin);
    for(int i = 0, ctr = 0; t!='\0'; i++)
    {
        t  = istr[i];
        if((t>'A'&&t<'Z')||(t>'a'&&t<'z')||t=='\0')
        {
            ostr[ctr] = t;
            ctr++;
        }
    }
    pf("%s", ostr);
    free(istr);
    free(ostr);
}