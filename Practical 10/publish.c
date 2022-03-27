#include <stdio.h>
#define pf printf
#define sf scanf
#define fpf fprintf
#define fsf fscanf
struct book
{
    char type;//h or p
    float price;
};

void Enter_Records(char A[30]);
void Reader(char A[30]);

void main()
{
    Enter_Records("Records.dat");
    Reader("Records.dat");
}

void Enter_Records(char A[30])
{
    FILE * fp1;
    fp1 = fopen(A, "a");
    struct book b;
    for(;;)
    {
        fflush(stdin);
        pf("Enter Type. (h / p)\n");
        sf("%c", &b.type);
        if(b.type!='h'&&b.type!='p'&&b.type!='b')
            break;
        pf("Enter Price. \n");
        sf("%f", &b.price);
        fpf(fp1, "%c%0.2f", b.type, b.price);
    }
    fclose(fp1);    
}

void Reader(char A[30])
{
    FILE * fp1, *fp2, *fp3;
    fp1 = fopen(A,"r");
    fp2 = fopen("Hardback.dat", "w");
    fp3 = fopen("Paperback.dat", "w");
    struct book b1;
    while(!feof(fp1))
    {
        fsf(fp1, "%c%f", &b1.type, &b1.price);
        if(b1.type == 'h'||b1.type == 'b')
        {
            fpf(fp2, "%c%0.2f", b1.type, b1.price);
        }
        if(b1.type == 'p'||b1.type == 'b')
        {
            fpf(fp3, "%c%0.2f", b1.type, b1.price);
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}