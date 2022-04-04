#include <stdio.h>
#define pf printf
#define sf scanf

void Writer(char filename[30]);//Writes the file and reads the new data just entered

void main()
{
    char ch = 'A';    
    Writer("Sample.txt");
    FILE * fp1 = fopen("Sample.txt", "r");
    FILE * fp2 = fopen("temp.txt", "w");
    pf("New File contains: \n");
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
    char ch;
    FILE * fp = fopen(filename, "w");
    //Type some text here to be printed into the file Sample.txt
    fprintf(fp, "small letters: abcdefghijklmnopqrstuvwxyz. ");
    fprintf(fp, "Capital Letters: ABCDEFGHIJKLMNOPQRSTUVWXYZ.");
    fprintf(fp, "\0");
    fclose(fp);
    fp = fopen(filename, "r");
    pf("Old File contains: \n");
    while(1)
    {
        fscanf(fp, "%c", &ch);
        if(feof(fp))
            break;
        pf("%c", ch);
    }
    pf("\n");
    fclose(fp);
}