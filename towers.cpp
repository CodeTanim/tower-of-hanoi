// CSc103 Project 7: Towers of Hanoi

#include <iostream>

using std::cin;
using std::cout;
using std::endl;#include <getopt.h> // to parse long arguments.

#include <cstdlib> // for atoi function

/*This is a program that computes the most moves needed for the Tower of hanoi puzzle. It works for any number of disks, irregardless of starting point. You need to input the number of disks, starting point and ending point from the command line*/

//Command line example input: ./towers -n 3 -s 1 -e 3

/* a very brief explanation of the algorithm would be to make a situation where u can move the nth disk from the starting tower to the ending tower in one move.
 You would move the n-1 disks to some tower in between the ending and starting towers, so you can make a situation where you can move the nth disk to the
  final destination AND THEN the rest of the towers as well. */

/* the main function call's order is basically preserved but the values of the parameters are changed around with respect to the puzzle's algorithm. 
for example value associated with "b", a tower in between the starting tower and the ending tower can become the new ending tower "e" or vice versa. 
The starting tower  "s" can become the new "b" and vice versa. The loop or "recursion" will stop after 
the base case has been reached for both of the recursive function calls in "puzzle"*/

void puzzle(int disk, int s, int b, int e) {

  static size_t step = 0;

  if (disk == 1) { // the base case

    cout << ++step << ")  Move disk from tower " << s << " to tower " << e << endl;
    
    cout << endl;
    return;
  }

  puzzle(disk - 1, s, e, b); /* notice how the parameters are switched. the order of s,b,e as it was in the original function call stays the same but the "values" associated with those numbers can get switched around */

  cout << ++step << ")  Move disk from tower " << s << " to tower " << e << endl;
  
  cout << endl;
  puzzle(disk - 1, b, s, e);

}

/* Here's a skeleton main function for processing the arguments. */

int main(int argc, char * argv[]) {
  // define long options
  static struct option long_opts[] = {
    {
      "start",
      required_argument,
      0,
      's'
    },
    {
      "end",
      required_argument,
      0,
      'e'
    },
    {
      "num-disks",
      required_argument,
      0,
      'n'
    },
    {
      0,
      0,
      0,
      0
    } // this denotes the end of our options.
  };
  // now process the options:
  char c; // to hold the option
  int opt_index = 0;
  short n = 0, start = 0, end = 0; /* to store inputs to the towers function. */
  while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, & opt_index)) != -1) {
    switch (c) {
    case 's': // process option s
      start = atoi(optarg);
      break;
    case 'e': // process option e
      end = atoi(optarg);
      break;
    case 'n': // process option n
      n = atoi(optarg);
      break;
    case '?': // this will catch unknown options.
      // here is where you would yell at the user.
      // although, getopt will already print an error message.
      return 1;
    }
  }

  /* TODO: now that you have the options and arguments,
   * solve the puzzle. */

  int disk = n; //The number of disks
  int s = start; //the starting tower
  int e = end; // the ending tower
  int b = end - start; // some tower in between or an auxilary tower. 

  // The if statements are reserved for some special cases of starting and ending points. Especially important for cases when when the starting point is NOT the first tower.

  if ((s == 1 && e == 2) || (s == 2 && e == 1)) {

    b = 3;

    puzzle(disk, s, b, e);

  } else if (s > e) {

    b = s - e;

    puzzle(disk, s, b, e);

  } else {

    puzzle(disk, s, b, e); // this is for every other case where the starting point is 1 and ending point is some value greater than the starting point.
  }

  return 0;
}
