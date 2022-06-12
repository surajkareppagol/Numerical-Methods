/* DO NOT EDIT THIS
 * AUTHOR : SHADOWW
 * LAST MODIFIED : 1/06/2022
 */

#include <stdio.h>
#include <math.h>
#define MAX 20

int choice, n, i, j, indexI, indexJ, indexNumber;
float stat[MAX][MAX], sum, xBar, yBar, zBar, r, a, b, c, d, sdX, sdY, sdZ;

///////////////////////////////////////
void firstMethod()
{
  for (indexI = 0; indexI < 2; indexI++)
  {
    sum = 0;
    for (indexJ = 0; indexJ < n; indexJ++)
      sum += stat[indexJ][indexI];
    stat[n][indexI] = sum;
  }

  xBar = stat[n][0] / n;

  yBar = stat[n][1] / n;

  printf("------------------------------\n");
  printf("| xBar = %.2f | yBar = %.2f |\n", xBar, yBar);
  printf("------------------------------\n");

  for (i = 0; i < n; i++)
  {
    stat[i][2] = stat[i][0] - xBar; // FIND X
    stat[i][3] = stat[i][1] - yBar; // FIND Y
  }

  for (i = 0; i < n; i++)
  {
    stat[i][4] = pow(stat[i][2], 2); // FIND X ^ 2
    stat[i][5] = pow(stat[i][3], 2); // FIND Y ^ 2
  }

  for (i = 0; i < n; i++)
    stat[i][6] = stat[i][2] * stat[i][3]; // FIND X * Y

  for (indexI = 2; indexI < 7; indexI++)
  {
    sum = 0;
    for (indexJ = 0; indexJ < n; indexJ++)
      sum += stat[indexJ][indexI];
    stat[n][indexI] = sum;
  }

  printf("\n");
  printf("  ===========================================================================================================\n");
  printf("  |   x        |   y        |   X          |   Y            |   X^2         |   Y^2         |  X * Y        |\n");
  printf("  ===========================================================================================================\n");

  for (indexNumber = 0; indexNumber < n + 1; indexNumber++)
  {
    printf("  -----------------------------------------------------------------------------------------------------------\n");
    printf("  |   %6.2f   |   %6.2f   |   %9.2f   |   %9.2f   |   %9.2f   |   %9.2f   |   %9.2f   |\n", stat[indexNumber][0], stat[indexNumber][1], stat[indexNumber][2], stat[indexNumber][3], stat[indexNumber][4], stat[indexNumber][5], stat[indexNumber][6]);
  }
  printf("  ===========================================================================================================\n");

  r = stat[n][6] / (sqrt(stat[n][4]) * sqrt(stat[n][5]));

  printf("\nREGRESSION CO-EFFICIENT (r) = %.2f \n\n", r);

  a = stat[n][6] / stat[n][4];
  b = (a * xBar * -1) + yBar;
  c = stat[n][6] / stat[n][5];
  d = (c * yBar * -1) + xBar;

  printf("THE REGRESSION LINES ARE : \n");
  printf("-----------------------------------------\n");
  printf("| y = %.2f x + %.2f | x = %.2f y + %.2f |\n", a, b, c, d);
  printf("-----------------------------------------\n");
}

void secondMethod()
{
  for (i = 0; i < n; i++)
    stat[i][2] = stat[i][0] - stat[i][1];

  for (indexI = 0; indexI < 3; indexI++)
  {
    sum = 0;
    for (indexJ = 0; indexJ < n; indexJ++)
      sum += stat[indexJ][indexI];
    stat[n][indexI] = sum;
  }

  xBar = stat[n][0] / n;
  yBar = stat[n][1] / n;
  zBar = stat[n][2] / n;

  printf("----------------------------------------------\n");
  printf("| xBar = %.2f | yBar = %.2f | zBar = %.2f |\n", xBar, yBar, zBar);
  printf("----------------------------------------------\n");

  for (i = 0; i < n; i++)
  {
    stat[i][3] = pow(stat[i][0], 2); // FIND x ^ 2
    stat[i][4] = pow(stat[i][1], 2); // FIND y ^ 2
    stat[i][5] = pow(stat[i][2], 2); // FIND z ^ 2
  }

  for (indexI = 3; indexI < 6; indexI++)
  {
    sum = 0;
    for (indexJ = 0; indexJ < n; indexJ++)
      sum += stat[indexJ][indexI];
    stat[n][indexI] = sum;
  }

  sdX = (stat[n][3] / n) - pow(xBar, 2);
  sdY = (stat[n][4] / n) - pow(yBar, 2);
  sdZ = (stat[n][5] / n) - pow(zBar, 2);

  printf("\n");
  printf("  ===========================================================================================\n");
  printf("  |   x        |   y        |   z          |   x^2          |   y^2         |   z^2         |\n");
  printf("  ===========================================================================================\n");

  for (indexNumber = 0; indexNumber < n + 1; indexNumber++)
  {
    printf("  -------------------------------------------------------------------------------------------\n");
    printf("  |   %6.2f   |   %6.2f   |   %9.2f   |   %9.2f   |   %9.2f   |   %9.2f   |\n", stat[indexNumber][0], stat[indexNumber][1], stat[indexNumber][2], stat[indexNumber][3], stat[indexNumber][4], stat[indexNumber][5]);
  }
  printf("  ===========================================================================================\n");

  r = (sdX + sdY - sdZ) / (2 * sqrt(sdX) * sqrt(sdY));

  printf("\nREGRESSION CO-EFFICIENT (r) = %.2f \n\n", r);

  a = r * (sqrt(sdY) / sqrt(sdX));
  b = (a * xBar * -1) + yBar;
  c = r * (sqrt(sdX) / sqrt(sdY));
  d = (c * yBar * -1) + xBar;

  printf("THE REGRESSION LINES ARE : \n");
  printf("-----------------------------------------\n");
  printf("| y = %.2f x + %.2f | x = %.2f y + %.2f |\n", a, b, c, d);
  printf("-----------------------------------------\n");
}

///////////////////////////////////////
int main()
{
  printf("\n                -----------------------------------------------\n");
  printf("                | REGRESSION CO-EFFICIENT AND REGRESSION LINES |\n");
  printf("                ------------------------------------------------\n\n");

  printf("----------------------------------------------------------------------\n");
  printf("| 1. FIRST METHOD (INTEGER VALUE) | 2. SECOND METHOD (DECIMAL VALUE) |\n");
  printf("----------------------------------------------------------------------\n\n");

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
  {
    printf("\n");
    firstMethod();
  }
  else if (choice == 2)
  {
    printf("\n");
    secondMethod();
  }
  else
    printf("==> INVALID CHOICE\n");
  return 0;
}
