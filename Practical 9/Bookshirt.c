#include <stdio.h>
#define pf printf
#define sf scanf

//Structures, Global Variables here
char  T[2][10] = {"Book", "Shirt"};
struct book
{
    char title[20];
    char author[15];
    int pages;
};
struct shirt
{
    char color[20];
    int size;
    char design[20];
};
union BookShirt
{
    struct book b;
    struct shirt s;
};
struct sales
{
    float price;
    int type;
    union BookShirt U;
};

//Method declarations here                     
void input(struct sales *S, int n);
void print(struct sales S);

//Method Definitions
void main()
{
    int n;
    pf("Enter the number of Items.\n");
    sf("%d", &n);
    struct sales sale[n];
    input(sale, n);
    for(int i = 0; i<n; i++)
        print(sale[i]);
}
void input(struct sales * S, int n)
{
    for(int i = 0; i<n;i++)//Number of iterations indicate no of structures
    {
        pf("Input type. Whether 0 or 1?\n");
        sf("%d", &(S->type));
        pf("Input Price. \n");
        sf("%f", &(S->price));
        if(S->type == 0)//Book
        {
            pf("Enter Title.\n");
            sf("%s", S->U.b.title);
            pf("Enter Author Name.\n");
            sf("%s", S->U.b.author);
            pf("Enter number of pages.\n");
            sf("%d", &(S->U.b.pages));
        }
        else if (S->type == 1)//Shirt
        {
            pf("Enter Color.\n");
            sf("%s", S->U.s.color);
            pf("Enter Design Name.\n");
            sf("%s", S->U.s.design);
            pf("Enter size.\n");
            sf("%d", &(S->U.s.size));
        }
        S++;
    }
}
void print(struct sales S)
{
    pf("\n");
    pf("Type: %d\n", S.type);
    pf("Type Name: %s\n", T[S.type]);
    pf("Price: %0.2f\n", S.price);
    if(S.type == 0)//Book
    {
        pf("Title: %s\n", S.U.b.title);
        pf("Author Name: %s\n", S.U.b.author);
        pf("Number of pages: %d\n", S.U.b.pages);
    }
    else if (S.type == 1)//Shirt
    {
        pf("Color: %s\n", S.U.s.color);
        pf("Design Name: %s\n", S.U.s.design);
        pf("Size: %d\n", S.U.s.size);
    }
    pf("\n");
}