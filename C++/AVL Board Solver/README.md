// AVL Board Solver //

This project was HUGE.  Essentially, two previous assignments bled together into one big project.  The Board Solver project did a brute force solve on a randomly generated board:
123
456
789
The AVL project only took ints and demonstrated the organizational power of an AVL tree.  This project assigned a score to each board with an algorithm that added together the distance each number was from their home locations.  That score was used to prioritize which board was pulled off the top of the self-rebalancing AVL tree to randomly move another number, recalculate the score, and throw it back on the tree.  It would stop when a solved board was pulled off the top.