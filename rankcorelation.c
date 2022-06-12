/* DO NOT EDIT THIS
 * AUTHOR : SHADOWW
 * LAST MODIFIED : 11/06/2022
 */

#include <stdio.h>
#include <math.h>
#define MAX 20

int n, i, j, indexI, indexJ, indexNumber, choice, rank, maxindex;
float stat[MAX][MAX], maxarray[MAX], sum, r, max;

///////////////////////////////////////
void rankOfCorelation()
{
  for (i = 0; i < n; i++)
    stat[i][2] = pow((stat[i][0] - stat[i][1]), 2);

  sum = 0;
  for (indexJ = 0; indexJ < n; indexJ++)
    sum += stat[indexJ][2];
  stat[n][2] = sum;

  printf("\n");
  printf("  ===========================================\n");
  printf("  |   x        |   y        |  (X - Y) ^ 2  |\n");
  printf("  ===========================================\n");

  for (indexNumber = 0; indexNumber < n + 1; indexNumber++)
  {
    printf("  -------------------------------------------\n");
    printf("  |   %6.2f   |   %6.2f   |   %9.2f   |\n", stat[indexNumber][0], stat[indexNumber][1], stat[indexNumber][2]);
  }
  printf("  ===========================================\n");

  r = 1 - ((6 * (stat[n][2])) / (n * (n * n - 1)));

  printf("\nRANK CO-RELATION COEFFICIENT = %.2f \n\n", r);
}

///////////////////////////////////////
void findRank()
{
  // STILL WORKING ON IT
  rankOfCorelation();
}

///////////////////////////////////////
int main()
{
  printf("\n                -------------------------------\n");
  printf("                | RANK CO-RELATION COEFFICIENT |\n");
  printf("                --------------------------------\n\n");

  printf("----------------------\n");
  printf("| 1. DATA | 2. RANKS |\n");
  printf("----------------------\n");
  printf("DON'T USE | 1. DATA | STILL WORKING ON IT\n");

  printf("CHOICE : ");
  scanf("%d", &choice);

  printf("\nEnter the value of n: ");
  scanf("%d", &n);

  printf("Enter the values of x: ");
  for (i = 0; i < n; i++)
    scanf("%f", &stat[i][0]);

  printf("Enter the values of y: ");
  for (i = 0; i < n; i++)
    scanf("%f", &stat[i][1]);

  if (choice == 1)
    findRank();
  else if (choice == 2)
    rankOfCorelation();
  else
    printf("==> INVALID CHOICE\n");
  return 0;
}
