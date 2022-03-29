#include <stdio.h>
#define pf printf
#define sf scanf

void Writer(char filename[30]);

void main()
{
    char ch = 'A';
    FILE * fp1 = fopen("Sample.txt", "a");
    fseek(fp1, 0, 2);
    int size = ftell(fp1);
    fclose(fp1);
    //if(size == 0)
    Writer("Sample.txt");
    fp1 = fopen("Sample.txt", "r");
    FILE * fp2 = fopen("temp.txt", "w");
    while(1)
    {
        fscanf(fp1, "%c", &ch);
        if(feof(fp1))
            break;
        if(ch>='a'&&ch<='z')
        {
            ch-=32;
            fprintf(fp2,"%c", ch);
        }
        else
            fprintf(fp2,"%c", ch);
            pf("%c", ch);
    }
    fclose(fp1);
    fclose(fp2);
    remove("Sample.txt");
    rename("temp.txt", "Sample.txt");
}

void Writer(char filename[30])
{
    FILE * fp = fopen(filename, "w");
    //Type some text here to be printed into the file Sample.txt
    fprintf(fp, "small letters: abcdefghijklmnopqrstuvwxyz. Capital Letters: ABCDE.");
    fprintf(fp, "\0");
    fclose(fp);
}