//This program can extract text from string
#include<stdio.h>
#include<string.h>
void extractor(char *string);
int main()
{
    char string[]="12A3ab56c797d757e089Zfz";
    printf("Before:%s\n",string);

    extractor(string);
    
    printf("After :%s\n",string);
    return 0;

}
void extractor(char *string){
        int newStringIndex = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        int rawStringIndex;
        rawStringIndex = string[i];

        if (rawStringIndex >= 97 && rawStringIndex <= 123)
        {
            string[newStringIndex] = string[i];
            newStringIndex++;
        }
        if (rawStringIndex>=65 && rawStringIndex <=91)
        {
            string[newStringIndex] = string[i];
            newStringIndex++;
        }
    }
    string[newStringIndex] = '\0';
}