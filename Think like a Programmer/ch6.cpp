// head vs tail recursion
// in head, the minimum data is passed through the function calls. In tail, it's
// the max

// in recursion the calling functions only care about 'what' from the functions
// they call. they don't care how the functions they call reaches a conclusion.

// consequently, all recursive functions can then be distilled into a
// dispatcher.

/*
a dispatcher:
1) handles the base (most trivial) case
2) must pass a smaller version of the problem to the next call.

The big idea of recursion is to move from dispatching to recursive calls.
*/

/*
avoid these common mistakes in recursion:
-using global variables to keep track of states across recursive function calls
-passing too many params to a recursive process 
*/


int iterativeArraySum(int integers[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += integers[i];
  }
  return sum;
}

//dispatcher in action
int arraySumDelegate(int integers[], int size) {
  if (size == 0)
    return 0;
  int lastNumber = integers[size - 1];
  int allButLastSum = iterativeArraySum(integers, size - 1);
  return lastNumber + allButLastSum;
}

//dispatcher replaced by a recursive call
int arraySumRecursive(int integers[], int size) {
  if (size == 0)
    return 0;
  int lastNumber = integers[size - 1];
  int allButLastSum = arraySumRecursive(integers, size - 1);
  return lastNumber + allButLastSum;
}