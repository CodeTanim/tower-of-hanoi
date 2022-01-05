# Tower of Hanoi 

Tower of Hanoi is a mathmatical game/puzzle that usually consists of three towers/sticks and a n number of disks with various diameters. The puzzle is usually sorted with a set of disks on one tower in order of decreasing size, with the smallest at the top. The main objective of the puzzle is to move the entire set of disks from the starting tower to the last tower. 


## Rules

When moving the disks, the player must follow a set of rules:

1) Only one disk may be moved at at time.
2) You cannot place a bigger disk on top of a smaller one.

If you want to play the game click [here](https://www.mathsisfun.com/games/towerofhanoi.html). 



# The recursive program

The C++ program in this repository can output the solution for any number of disks or towers using recursion. After cloning this repository, the program has to be run from a command-line terminal as it takes in arguments from there. Below is an example of how you would output a solution set for 4 disks, and 3 towers. The n argument takes in the number of disks you want to find solutions for, the s argument takes the starting tower number, and the e argument takes the ending tower number.


  ```./towers -n 4 -s 1 -e 3```
 ``` 
 
1)  Move disk from tower 1 to tower 2 

2)  Move disk from tower 1 to tower 3 

3)  Move disk from tower 2 to tower 3 

4)  Move disk from tower 1 to tower 2 

5)  Move disk from tower 3 to tower 1 

6)  Move disk from tower 3 to tower 2 

7)  Move disk from tower 1 to tower 2 

8)  Move disk from tower 1 to tower 3 

9)  Move disk from tower 2 to tower 3 

10)  Move disk from tower 2 to tower 1

11)  Move disk from tower 3 to tower 1

12)  Move disk from tower 2 to tower 3

13)  Move disk from tower 1 to tower 2

14)  Move disk from tower 1 to tower 3

15)  Move disk from tower 2 to tower 3 

```


<img src="http://upload.wikimedia.org/wikipedia/commons/6/60/Tower_of_Hanoi_4.gif" alt="Fig. 1: Animation for 4 disks" /><figcaption aria-hidden="true"> An animation for the solution to a set up involving 4 disks</figcaption>

# Other notes

The starting point for the argument can be any arbitrary number (it doesnt have to be 1), and the ending tower does not have to be 3. The program will output a valid solution for any number of disks as well. 
