// This program builds pascal's triangle up to a certain level that the user
// inputs
#include <stdio.h>

void BuildTriangle(int levels, int triangle[29][29]) {
  /*
BuildTriangle inputs elements into a 2D array. The elements inputted are the
user inputs level and the values in pascals triangle up to said level
@levels - the level pascals triangle needs to go up to
@triangle - the array that is being modified to store the elements
@returns: nothing
  */
  triangle[0][0] = 1;
  for (int i = 1; i <= levels; i++) {
    for (int j = 1; j <= i; j++) {
      triangle[i][0] = 1;
      if (i == 1) {
        triangle[i][j] = 1;
        continue;
      }
      if (j == i) {
        triangle[i][j] = 1;
      } else {
        triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
      }
    }
  }
}

void PrintArray(int levels, int array[29][29]) {
  /*
PrintArray prints all the elements of this 2D array, however, it only prints the
necessary numbers that were modified not the random values stored in memory
@levels - the level pascals triangle goes up to
@array - the 2D array that needs to be printed
@returns: nothing

          */
  for (int i = 0; i < levels; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d ", array[i][j]);
    }
  }
}
int main(void) {
  /*
Main gets the number of levels from the user and initializes variables necessary
to call functions

@returns: 0 if the program runs all the way through
          */

  int pascalTri[29][29];
  int levels;
  printf("Please enter how many levels of Pascal's Triangle you would like to "
         "see: ");
  scanf("%d", &levels);

  BuildTriangle(levels, pascalTri);
  PrintArray(levels, pascalTri);
  return 0;
}