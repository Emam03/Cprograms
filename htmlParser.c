#include<stdio.h>
#include<string.h>
void parser(char* string);

int main()
{
    char str[]="</h1>        www.google.com     <h1>"; // paste the html in double quotes which you want to parse
    printf("Before:%s\n",str);
    parser(str);
    printf("After :~~%s~~\n",str);
    return 0;
}
void parser(char* string){
    int newStringIndex = 0;
        int in;
        in = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '<')
        {
            in = 0;
            continue;
        }
        else if (string[i] == '>')    
        {
            in = 1;
            continue;
        }
        if (in == 1)
        {
            string[newStringIndex] = string[i];
            newStringIndex++;
        }
        
    }
    string[newStringIndex] = '\0';
    while (string[0] == ' ')
    {
        for (int i = 0; i < strlen(string); i++)
        {
            string[i] = string[i+1];
        }
        
    }

    while (string[strlen(string)- 1]== ' ')
    {
        string[strlen(string)- 1] = '\0';
    }
    
    
    // string[4] = '\0';
}
