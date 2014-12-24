#include <stdio.h>

main()
{
  int fahrenheit, celsius;
  printf("Table of Temperature Conversions:\n");
  printf("Fahrenheit\tCelsius\n");
  
  /*  set faharenheit to 0, print out conversion values each loop,
      and adding 10 to faharenheit each time through. */
  fahrenheit = 0;
  while (fahrenheit <= 100)
  {
    celsius = (5*(fahrenheit-32)/9);
    printf("%d\t\t%d\n", fahrenheit, celsius);
    fahrenheit += 10;
  }
  return 0;
}