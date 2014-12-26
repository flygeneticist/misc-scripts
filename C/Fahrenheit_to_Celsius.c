#include <stdio.h>

main()
{
  float fahr, cels;
  printf("Table of Temperature Conversions:\n");
  printf("Fahrenheit\tCelsius\n");
  
  /*  set faharenheit to 0, print out conversion values each loop,
      and adding 10 to faharenheit each time through. */
  fahr = 0;
  while (fahr <= 100)
  {
    cels = (5.0/9.0)*(fahr-32.0);
    printf("%.0f\t\t%.1f\n", fahr, cels);
    fahr += 10;
  }
  return 0;
}
