import math
import random
import EightTile

class Stack: # lifted directly from pacman util.py
    "A container with a last-in-first-out (LIFO) queuing policy."
    def __init__(self):
        self.list = []

    def __len__(self):
        return len(self.list)

    def push(self,item):
        "Push 'item' onto the stack"
        self.list.append(item)

    def pop(self):
        "Pop the most recently pushed item from the stack"
        return self.list.pop()

    def isEmpty(self):
        "Returns true if the stack is empty"
        return len(self.list) == 0

class utility:

    def shuffle(self, Puzzle, step_count):
		# comment out the for loop below and indent return Puzzle if using _init_state in EightTile.py
        for i in range(step_count):
            row, col = self.find(Puzzle, 0)
            free = self._get_legal_moves(Puzzle)
            target = random.choice(free) 
            self.swap(Puzzle, (row, col), target)
            row, col = target
		
	return Puzzle

    def something(self, a, b):
        return a + b

    def _get_legal_moves(self, Puzzle):
        # returns list of tuples with which the free space may be swapped
        # get row and column of the empty piece
        row, col = self.find(Puzzle, 0)
        free = [] 

        # find which pieces can move there
        if row > 0:
            free.append((row - 1, col))
        if col > 0:
            free.append((row, col - 1))
        if row < 2:
            free.append((row + 1, col))
        if col < 2:
            free.append((row, col + 1))

        return free

    def find(self, Puzzle, value):
		# returns the row, col of specified value in the puzzle.
        if value < 0 or value > 8:
            raise Exception("value out of range")

        for row in range(3):
            for col in range(3):
                if Puzzle.adj_matrix[row][col] == value:
                    return row, col

    def peek(self,Puzzle, row, col):
        # returns the value at the specified row and column
        return Puzzle.adj_matrix[row][col]

    def set(self, Puzzle, row, col, value):
		# sets the value at the specified row and column
        Puzzle.adj_matrix[row][col] = value
		
    def swap(self, Puzzle, pos_a, pos_b): 
		# swaps values at the specified coordinates (used when creating puzzles for after a move has been performed)
		# pos_a and pos_b are tuples that follow the order (row, col)

        temp = self.peek(Puzzle, *pos_a)
        self.set(Puzzle, pos_a[0], pos_a[1], self.peek(Puzzle, *pos_b))
        self.set(Puzzle, pos_b[0], pos_b[1], temp)
        return Puzzle
