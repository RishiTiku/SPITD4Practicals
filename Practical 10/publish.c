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

char Categories[3][15] = {"Hardback", "Paperback", "Both"};

void Enter_Records(char A[30]);
void Reader(char A[30]);
int category(char ch);

void main()
{
    char ch;
    float price;
    Enter_Records("Records.dat");
    Reader("Records.dat");
    FILE * fp1 = fopen("Hardback.dat", "r");
    FILE * fp2 = fopen("Paperback.dat", "r");
    pf("\t\tContents of Hardback.dat:\n");
    for(;;)
    {
        fsf(fp1, "%c ", &ch);
        fsf(fp1, "%f\n", &price);
        pf("Category: %s\nPrice: %0.2f\n", Categories[category(ch)], price);
        if(feof(fp1))
            break;
    }
    pf("\n\t\tContents of Paperback.dat:\n");
    for(;;)
    {
        fsf(fp2, "%c ", &ch);
        fsf(fp2, "%f\n", &price);
        pf("Category: %s\nPrice: %0.2f\n", Categories[category(ch)], price);
        if(feof(fp2))
            break;
    }
    fclose(fp1);
    fclose(fp2);
}

int category(char ch)
{
    if(ch == 'h'||ch == 'H')
        return 0;
    if(ch == 'p'||ch == 'P')
        return 1;
    if(ch == 'b'||ch == 'B')
        return 2;
}

void Enter_Records(char A[30])
{
    FILE * fp1;
    fp1 = fopen(A, "a");
    struct book b;
    for(;;)
    {
        fflush(stdin);
        pf("Enter Type. (h / p / b) (Any other key to End)\n");
        sf("%c", &b.type);
        if(b.type!='h'&&b.type!='p'&&b.type!='b'
        &&b.type!='H'&&b.type!='P'&&b.type!='B')
            break;
        pf("Enter Price. \n");
        sf("%f", &b.price);
        fpf(fp1, "%c %0.2f\n", b.type, b.price);
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
        fsf(fp1, "%c %f\n", &b1.type, &b1.price);
        if(b1.type == 'h'||b1.type=='H'||
        b1.type == 'b'||b1.type == 'B')
        {
            fpf(fp2, "%c %0.2f\n", b1.type, b1.price);
        }
        if(b1.type == 'p'||b1.type == 'P'
        ||b1.type == 'b'||b1.type == 'B')
        {
            fpf(fp3, "%c %0.2f\n", b1.type, b1.price);
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}