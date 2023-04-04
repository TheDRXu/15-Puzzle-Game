# 15-Puzzle-Game

15 Puzzle Game Solver using C++ language

This Puzzle Game Solver utilized A* algorithm to give the best movement solution.<br /><br />
A* algorithm is using priority queue to process highest priority element and manhattan distance to count heuristic of given or current state.<br />
Manhattan distance is calculated as the sum of absolute differences between two vectors.

How to use the code:
Input : puzzle state (10-15 is A-F)<br />
Output : best movement solution

Example: <br/>
Input : 0942A65D78BE1C3F<br />
Output : No solution!!

Input: 0123456789ABCDEF<br />
Output: It is the goal state.

Input: 4263517B89AFCDE0<br />
Output: move 0 to up<br />
        move 0 to up<br />
        move 0 to left<br />
        move 0 to up<br />
        move 0 to left<br />
        move 0 to down<br />
        move 0 to left<br />
        move 0 to up<br />
        
Input: 4123986750ABCDEF<br />
Output: move 0 to up<br />
        move 0 to left<br />
        move 0 to down<br />
        move 0 to right<br />
        move 0 to up<br />
        move 0 to left<br />
        move 0 to up<br />
