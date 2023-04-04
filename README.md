# 15-Puzzle-Game

15 Puzzle Game Solver using C++ language

This Puzzle Game Solver utilized A* algorithm to give the best movement solution.
A* algorithm is using priority queue to process highest priority element and manhattan distance to count heuristic of given or current state.
Manhattan distance is calculated as the sum of absolute differences between two vectors.

How to use the code:
Input : puzzle state (10-15 is A-F)
Output : best movement solution

Example: 
Input : 0942A65D78BE1C3F
Output : No solution!!

Input: 0123456789ABCDEF
Output: It is the goal state.

Input: 4263517B89AFCDE0
Output: move 0 to up
        move 0 to up
        move 0 to left
        move 0 to up
        move 0 to left
        move 0 to down
        move 0 to left
        move 0 to up
        
Input: 4123986750ABCDEF
Output: move 0 to up
        move 0 to left
        move 0 to down
        move 0 to right
        move 0 to up
        move 0 to left
        move 0 to up