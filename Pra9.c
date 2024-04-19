#include <stdio.h>
#include <math.h>

// Function to round off float to int
int fround(float x)
{
  int a;
  x = x + 0.5;
  a = (int)x;
  return a;
}

// Function to calculate parameters of Basic COCOMO
void calculate(float table[][4], char mode[][15], int size)
{
  float effort, time, staff;
  int model;

  // Check the mode according to size
  // organic
  if (size >= 2 && size <= 50)
    model = 0;
  // semi-detached
  else if (size > 50 && size <= 300)
    model = 1;
  // embedded
  else if (size > 300)
    model = 2;

  printf("The mode is %s\n", mode[model]);

  // Calculate Effort
  effort = table[model][0] * pow(size, table[model][1]);

  // Calculate Time
  time = table[model][2] * pow(effort, table[model][3]);

  // Calculate Persons Required
  staff = effort / time;

  // Output the values calculated
  printf("Effort = %.2f Person-Month\n", effort);
  printf("Development Time = %.2f Months\n", time);
  printf("Average Staff Required = %d Persons\n", fround(staff));
}

int main()
{
  float table[3][4] = {{2.4, 1.05, 2.5, 0.38},
                       {3.0, 1.12, 2.5, 0.35},
                       {3.6, 1.20, 2.5, 0.32}};
  char mode[3][15] = {"Organic", "Semi-detached", "Embedded"};

  int size;

  // Taking input from the user for size of project in Kilo Lines of Code
  printf("Enter Kilo Lines of Code: ");
  scanf("%d", &size);

  // Calculate parameters
  calculate(table, mode, size);

  return 0;
}
