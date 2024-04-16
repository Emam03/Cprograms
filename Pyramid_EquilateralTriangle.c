/*

    *
   * *
  * * * 
 * * * *
* * * * *
*/
#include <stdio.h>
int main()
{
    int i, j, k, rows;
    // i = length y axis
    // j= print stars
    // k print spaces before star
    printf("enter number of rows you want in pyramid:");
    scanf("%d", &rows);
    for (i = 1; i <= rows; i++)
    {
        for (k = 1; k <= rows-i; k++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
