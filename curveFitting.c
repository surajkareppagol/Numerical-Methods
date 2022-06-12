/* DO NOT EDIT THIS
 * AUTHOR : SHADOWW
 * LAST MODIFIED : 1/06/2022
 */

#include <stdio.h>
#include <math.h>
#define MAX 20

///////////////////////////////////////
float stat[MAX][MAX], calc[MAX][MAX], a, b, c, sum, valueA, valueB, deter[3][4], equationCalc[2][4], multiplyer;
int n, curveChoice, curveType, i, j, k, indexI, indexJ, indexNumber;

///////////////////////////////////////
void straightLine()
{
  for (i = 0; i < n; i++)
  {
    stat[i][2] = pow(stat[i][0], 2);
    stat[i][3] = stat[i][0] * stat[i][1];
  }

  for (indexI = 0; indexI < 4; indexI++)
  {
    sum = 0;
    for (indexJ = 0; indexJ < n; indexJ++)
      sum += stat[indexJ][indexI];
    stat[n][indexI] = sum;
  }

  printf("\n");
  printf("  ====================================================\n");
  printf("  |     x      |     y      |     X^2    |     xy    |\n");
  printf("  ====================================================\n");

  for (indexNumber = 0; indexNumber < n + 1; indexNumber++)
  {
    printf("  -----------------------------------------------------\n");
    printf("  |   %6.2f   |   %6.2f   |   %6.2f   |   %6.2f   |\n", stat[indexNumber][0], stat[indexNumber][1], stat[indexNumber][2], stat[indexNumber][3]);
  }
  printf("  =====================================================\n");

  if (curveType == 1)
  {
    calc[0][0] = stat[n][0];
    calc[0][1] = n;
    calc[0][2] = stat[n][1];
    calc[1][0] = stat[n][2];
    calc[1][1] = stat[n][0];
    calc[1][2] = stat[n][3];

    a = ((calc[0][2] * calc[1][1]) - (calc[1][2] * calc[0][1])) / ((calc[0][0] * calc[1][1]) - (calc[1][0] * calc[0][1]));
    b = ((calc[0][2] * calc[1][0]) - (calc[1][2] * calc[0][0])) / ((calc[0][1] * calc[1][0]) - (calc[1][1] * calc[0][0]));

    printf("\nTHE RESULT IS: y = %.2f x + %.2f\n", a, b);
  }
  else if (curveType == 2)
  {
    calc[0][0] = n;
    calc[0][1] = stat[n][0];
    calc[0][2] = stat[n][1];
    calc[1][0] = stat[n][0];
    calc[1][1] = stat[n][2];
    calc[1][2] = stat[n][3];

    a = ((calc[0][2] * calc[1][1]) - (calc[1][2] * calc[0][1])) / ((calc[0][0] * calc[1][1]) - (calc[1][0] * calc[0][1]));
    b = ((calc[0][2] * calc[1][0]) - (calc[1][2] * calc[0][0])) / ((calc[0][1] * calc[1][0]) - (calc[1][1] * calc[0][0]));

    printf("\nTHE RESULT IS: y = %.2f + %.2f x\n", a, b);
  }
}

///////////////////////////////////////
void parabola()
{
  for (i = 0; i < n; i++)
  {
    stat[i][2] = pow(stat[i][0], 2);
    stat[i][3] = stat[i][0] * stat[i][1];
    stat[i][4] = pow(stat[i][0], 3);
    stat[i][5] = pow(stat[i][0], 4);
    stat[i][6] = stat[i][2] * stat[i][1];
  }

  for (indexI = 0; indexI < 7; indexI++)
  {
    sum = 0;
    for (indexJ = 0; indexJ < n; indexJ++)
      sum += stat[indexJ][indexI];
    stat[n][indexI] = sum;
  }

  printf("\n");
  printf("  ===========================================================================================================\n");
  printf("  |   x        |   y        |   X^2         |   xy          |   x^3         |   x^4         |   x^2 * y     |\n");
  printf("  ===========================================================================================================\n");

  for (indexNumber = 0; indexNumber < n + 1; indexNumber++)
  {
    printf("  -----------------------------------------------------------------------------------------------------------\n");
    printf("  |   %6.2f   |   %6.2f   |   %9.2f   |   %9.2f   |   %9.2f   |   %9.2f   |   %9.2f   |\n", stat[indexNumber][0], stat[indexNumber][1], stat[indexNumber][2], stat[indexNumber][3], stat[indexNumber][4], stat[indexNumber][5], stat[indexNumber][6]);
  }
  printf("  ===========================================================================================================\n");

  if (curveType == 1)
  {
    deter[0][0] = stat[n][2];
    deter[0][1] = stat[n][0];
    deter[0][2] = n;
    deter[0][3] = stat[n][1];
    deter[1][0] = stat[n][4];
    deter[1][1] = stat[n][2];
    deter[1][2] = stat[n][0];
    deter[1][3] = stat[n][3];
    deter[2][0] = stat[n][5];
    deter[2][1] = stat[n][4];
    deter[2][2] = stat[n][2];
    deter[2][3] = stat[n][6];

    multiplyer = deter[1][2] / deter[0][2];
    for (i = 0; i < 4; i++)
      deter[0][i] *= multiplyer;

    for (i = 0; i < 4; i++)
      equationCalc[0][i] = deter[0][i] - deter[1][i];

    multiplyer = deter[2][2] / deter[1][2];
    for (i = 0; i < 4; i++)
      deter[1][i] *= multiplyer;

    for (i = 0; i < 4; i++)
      equationCalc[1][i] = deter[1][i] - deter[2][i];

    a = ((equationCalc[0][3] * equationCalc[1][1]) - (equationCalc[1][3] * equationCalc[0][1])) / ((equationCalc[0][0] * equationCalc[1][1]) - (equationCalc[1][0] * equationCalc[0][1]));
    b = ((equationCalc[0][3] * equationCalc[1][0]) - (equationCalc[1][3] * equationCalc[0][0])) / ((equationCalc[0][1] * equationCalc[1][0]) - (equationCalc[1][1] * equationCalc[0][0]));
    c = ((deter[2][3]) - (deter[2][0] * a) - (deter[2][1] * b)) / deter[2][2];

    printf("\nTHE RESULT IS: y = %.2f x^2 + %.2f x + %.2f\n", a, b, c);
  }
  else if (curveType == 2)
  {
    deter[0][0] = n;
    deter[0][1] = stat[n][0];
    deter[0][2] = stat[n][2];
    deter[0][3] = stat[n][1];
    deter[1][0] = stat[n][0];
    deter[1][1] = stat[n][2];
    deter[1][2] = stat[n][4];
    deter[1][3] = stat[n][3];
    deter[2][0] = stat[n][2];
    deter[2][1] = stat[n][4];
    deter[2][2] = stat[n][5];
    deter[2][3] = stat[n][6];

    multiplyer = deter[1][2] / deter[0][2];
    for (i = 0; i < 4; i++)
      deter[0][i] *= multiplyer;

    for (i = 0; i < 4; i++)
      equationCalc[0][i] = deter[0][i] - deter[1][i];

    multiplyer = deter[2][2] / deter[1][2];
    for (i = 0; i < 4; i++)
      deter[1][i] *= multiplyer;

    for (i = 0; i < 4; i++)
      equationCalc[1][i] = deter[1][i] - deter[2][i];

    a = ((equationCalc[0][3] * equationCalc[1][1]) - (equationCalc[1][3] * equationCalc[0][1])) / ((equationCalc[0][0] * equationCalc[1][1]) - (equationCalc[1][0] * equationCalc[0][1]));
    b = ((equationCalc[0][3] * equationCalc[1][0]) - (equationCalc[1][3] * equationCalc[0][0])) / ((equationCalc[0][1] * equationCalc[1][0]) - (equationCalc[1][1] * equationCalc[0][0]));
    c = ((deter[2][3]) - (deter[2][0] * a) - (deter[2][1] * b)) / deter[2][2];

    printf("\nTHE RESULT IS: y = %.2f + %.2f x + %.2f x^2\n", a, b, c);
  }
}

///////////////////////////////////////
void exponential()
{
  for (i = 0; i < n; i++)
  {
    k = 0;
    for (j = 2; j < 4; j++)
    {
      stat[i][j] = log(stat[i][k]);
      k++;
    }
  }

  for (i = 0; i < n; i++)
  {
    stat[i][4] = pow(stat[i][2], 2);
    stat[i][5] = stat[i][2] * stat[i][3];
  }

  for (indexI = 0; indexI < 6; indexI++)
  {
    sum = 0;
    for (indexJ = 0; indexJ < n; indexJ++)
      sum += stat[indexJ][indexI];
    stat[n][indexI] = sum;
  }

  printf("\n");
  printf("  ==============================================================================\n");
  printf("  |     x      |     y      |     X      |     Y      |     X^2    |     XY    |\n");
  printf("  ==============================================================================\n");

  for (indexNumber = 0; indexNumber < n + 1; indexNumber++)
  {
    printf("  -------------------------------------------------------------------------------\n");
    printf("  |   %6.2f   |   %6.2f   |   %6.4f   |   %6.4f   |   %6.4f   |   %6.4f   |\n", stat[indexNumber][0], stat[indexNumber][1], stat[indexNumber][2], stat[indexNumber][3], stat[indexNumber][4], stat[indexNumber][5]);
  }
  printf("  ===============================================================================\n");

  if (curveType == 1)
  {
    calc[0][0] = n;
    calc[0][1] = stat[n][2];
    calc[0][2] = stat[n][3];
    calc[1][0] = stat[n][2];
    calc[1][1] = stat[n][4];
    calc[1][2] = stat[n][5];

    valueA = ((calc[0][2] * calc[1][1]) - (calc[1][2] * calc[0][1])) / ((calc[0][0] * calc[1][1]) - (calc[1][0] * calc[0][1]));
    valueB = ((calc[0][2] * calc[1][0]) - (calc[1][2] * calc[0][0])) / ((calc[0][1] * calc[1][0]) - (calc[1][1] * calc[0][0]));

    a = exp(valueA);
    b = valueB;

    printf("\nTHE RESULT IS: y = %.2f * x ^ %.2f\n", a, b);
  }
  else if (curveType == 2)
  {
    calc[0][0] = stat[n][2];
    calc[0][1] = n;
    calc[0][2] = stat[n][3];
    calc[1][0] = stat[n][4];
    calc[1][1] = stat[n][2];
    calc[1][2] = stat[n][5];

    valueA = ((calc[0][2] * calc[1][1]) - (calc[1][2] * calc[0][1])) / ((calc[0][0] * calc[1][1]) - (calc[1][0] * calc[0][1]));
    valueB = ((calc[0][2] * calc[1][0]) - (calc[1][2] * calc[0][0])) / ((calc[0][1] * calc[1][0]) - (calc[1][1] * calc[0][0]));

    a = valueA;
    b = exp(valueB);

    printf("\nTHE RESULT IS: y = %.2f * x ^ %.2f\n", b, a);
  }
}

///////////////////////////////////////
int main()
{
  printf("\n                -----------------\n");
  printf("                | CURVE FITTING |\n");
  printf("                -----------------\n\n");

  printf("-------------------------------------------------------------------------\n");
  printf("| 1.Straight Line | 2.Second Degree Parabola(SUD) | 3.Exponential Curve |\n");
  printf("-------------------------------------------------------------------------\n\n");

  printf("CHOICE : ");
  scanf("%d", &curveChoice);

  printf("\nEnter the value of n: ");
  scanf("%d", &n);
  printf("Enter the values of x: ");
  for (i = 0; i < n; i++)
    scanf("%f", &stat[i][0]);

  printf("Enter the values of y: ");
  for (i = 0; i < n; i++)
    scanf("%f", &stat[i][1]);

  if (curveChoice == 1)
  {
    printf("\n");
    printf("---------------------------------\n");
    printf("| 1. y = ax + b | 2. y = a + bx |\n");
    printf("---------------------------------\n");
    printf("CHOICE : ");
    scanf("%d", &curveType);
    straightLine();
  }
  else if (curveChoice == 2)
  {
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("| 1. y = ax^2 + bx + c | 2. y = a + bx + cx^2 |\n");
    printf("-----------------------------------------------\n");
    printf("CHOICE : ");
    scanf("%d", &curveType);
    parabola();
  }
  else if (curveChoice == 3)
  {
    printf("\n");
    printf("-----------------------------\n");
    printf("| 1. y = ax^b | 2. y = bx^a |\n");
    printf("-----------------------------\n");
    printf("CHOICE : ");
    scanf("%d", &curveType);
    exponential();
  }
  else
    printf("==> INVALID CHOICE\n");
  return 0;
}