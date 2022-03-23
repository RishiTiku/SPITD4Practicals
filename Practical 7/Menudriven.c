#include <stdio.h>
#include <conio.h>
void strcopy(char S1[1000], char S2[1000]);
void CleanString(char S[1000]);
int strleng(char S[1000]);
void ToUpper(char S[1000]);
int strcomp(char S1[1000], char S2[1000]);
void Reverse(char S[1000]);
void Concate(char S1[1000], char S2[1000]);

void main()
{
    int choice;
    char string1[1000], string2[1000];
    printf("Enter 2 strings.\n");
    fgets(string1, 1000, stdin);
    fflush(stdin);
    fgets(string2, 1000, stdin);
    //fgets(string2, 50, stdin);
    //fflush(stdin);
    CleanString(string1);
    CleanString(string2);
    do
    {
        clrscr();
        printf("Two Strings entered are %s, %s", string1, string2);
        printf("1. Copy 1 string to another. \n");
        printf("2. Find the string Length. \n");
        printf("3. Compare 2 strings. \n");
        printf("4. Reverse the string.\n");
        printf("5. Concatenate string 1 to string 2.\n");
        printf("6. Lower Case to Upper.\n");
        printf("7. Exit.\n");
        printf("Enter your choice. (1-6) \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: strcopy(string1, string2);
                    break;
            case 2: printf("Length of String1 is %d.\n", strleng(string1));
                    printf("Length of String2 is %d.\n", strleng(string2));
                    break;
            case 3: printf("Output: %d", strcomp(string1, string2));
                    break;
            case 4: Reverse(string1);
                    Reverse(string2);
                    break;
            case 5: Concate(string1, string2);
                    break;
            case 6: ToUpper(string1);
                    ToUpper(string2);
                    break;
            default: printf("Exiting.\n");
        }
    printf("Press Any Key to continue.\n");
    getch();
    } while (choice<=6&&choice>0);
}

void CleanString(char S[1000])
{
    int i = 0;
    while(1)
    {
        if(S[i] == '\n'||S[i] == '\0')
        {
            S[i] = '\0';
            break;
        }
        i++;
    }
}

void Concate(char S1[1000], char S2[1000])
{
    int i = 0; 
    int j = 0;
    while(1)
    {
        if(S1[i] == '\0')
        {
            while(1)
            {
                S1[i+j] = S2[j];
                if(S2[j]=='\0')
                {
                    printf("The concatenated string is %s.\n", S1);
                    return;
                }
                j++; 
            }
        }
        i++;
    }
    return;
}

void ToUpper(char S[1000])
{
    int i = 0; 
    while(S[i]!='\0')
    {
        if(S[i]<=122&&S[i]>=97)
            S[i] = S[i] - 32;
        i++; 
    }
    printf("New String: %s.\n", S);
}

void Reverse(char S[1000])
{
    int length = strleng(S);
    char temp;
    for(int i = 0; i<length/2; i++)
    {
        temp = S[length-1-i];
        S[length-1-i] = S[i];
        S[i] = temp;
    }
    printf("Reversed String: %s\n", S);
}

int strleng(char S[1000])
{
    int counter = 0;
    while(S[counter]!='\0')
    {
        counter++;
    }
    return counter;
}

int strcomp(char S1[1000], char S2[1000])
{
    int s1 = strleng(S1), s2 = strleng(S2), i = 0;
    while(1)
    {
        if(S1[i] == '\0')
        {
            if(s1<s2)
                return -1;
            if(s1 == s2) 
                return 0;
        }
        else if(S2[i] == '\0')
        {
            if(s1>s2)
                return +1;
            if(s1 == s2) 
                return 0;
        }
        else if(S1[i]>S2[i])
        {
            return 1;
        }
        else if(S1[i]<S2[i])
        {
            return -1;
        }
        i++;
    }
    return 0;
}

void strcopy(char S1[1000], char S2[1000])
{
    int i = 0;
    while(!S2[i]=='\0')
    {
        S1[i] = S2[i];
        i++;
    }
    S1[i] = '\0';
    printf("New Strings = %s, %s", S1, S2);
}
