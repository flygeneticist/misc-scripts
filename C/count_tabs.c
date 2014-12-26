#include <stdio.h>

main()
{ 
  int tab, blank, newln; // initialize counter int vars
  int c; // character holder int var
  // set counters equal to zero
  tab = 0; 
  blank = 0; 
  newln = 0;
  
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
      ++tab;
    else if (c == ' ')
      ++blank;
    else if (c == '\n')
      ++newln;
  }
  printf("Counted Results:\n");
  printf("Tabs: %d\n", tab);
  printf("Blanks: %d\n", blank);
  printf("New Lines: %d\n", newln);
  return 0;
}
