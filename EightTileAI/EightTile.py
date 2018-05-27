# solves a randomized 8 tile puzzle using several common search algorithms

import util
import sys
sys.setrecursionlimit(5000);

_goal_state = [[1, 2, 3],
               [4, 5, 6],
               [7, 8, 0]]
			   
_init_state = [[2, 5, 3], # this puzzle fails DFS even with 5000 recursion calls allowed!!!
			   [1, 0, 6],
			   [4, 7, 8]]

def index(item, seq):
    # helper function that returns -1 for non-found index value of a seq
    if item in seq:
        return seq.index(item)
    else:
        return -1

class EightPuzzle:

    def __init__(self):

        # heuristic value
        self._heurval = 0
        # search depth of current instance
        self._depth = 0
        # parent node in search path
        self._parent = None
        self.adj_matrix = []
        for i in range(3):
            self.adj_matrix.append(_goal_state[i][:]) # for debugging, take _goal_state and make it _init_state

    def getter(self):
        return self.adj_matrix

    def __eq__(self, other):
        if self.__class__ != other.__class__:
            return False
        else:
            return self.adj_matrix == other.adj_matrix

    def __str__(self):
        res = ''
        for row in range(3):
            res += ' '.join(map(str, self.adj_matrix[row]))
            res += '\r\n'
        return res

    def _clone(self):
        p = EightPuzzle()
        for i in range(3):
            p.adj_matrix[i] = self.adj_matrix[i][:]
        return p

    def _generate_moves(self):
        utilit = util.utility()
        free = utilit._get_legal_moves(self)
        zero = utilit.find(self, 0)

        def swap_and_clone(a, b):
            p = self._clone()
            p = utilit.swap(p, a, b)
            p._depth = self._depth + 1
            p._parent = self
            return p

        return map(lambda pair: swap_and_clone(zero, pair), free)

    def _generate_solution_path(self, path):
        if self._parent == None:
            return path
        else:
            path.append(self)
            return self._parent._generate_solution_path(path)

    def solve(self, heur, algorithm):
		# performs BFS, UCS, or A* search for goal state.
        # heur(puzzle) - heuristic function, returns an integer

		def is_solved(puzzle):
			return puzzle.adj_matrix == _goal_state
		
		fringe = [self]  # list that contains all nodes to be expanded/examined
		path = []  # list that contains the final path taken through the tree to the goal state
		move_count = 0
		while len(fringe) > 0:
			x = fringe.pop(0)
			move_count += 1
			if (is_solved(x)):
				if len(path) > 0:
					return x._generate_solution_path([]), move_count
				else:
					return [x]

			successor = x._generate_moves()
			fringe_index = path_index = -1
			for move in successor:
                # check for if the node has already been seen
				fringe_index = index(move, fringe)
				path_index = index(move, path)
				heurval = heur(move)
				# total utility is defined as heuristic value of the matrix after move as well as its depth in the tree- 
				# the lower the depth, the more costly it is to expand that node, and the costlier it is. For all intents
				# and purposes, the depth of the node in the tree is taken as the 'cost' of that node.
				total_utility = heurval + move._depth 

				if path_index == -1 and fringe_index == -1:
					move._heurval = heurval
					fringe.append(move)
				elif fringe_index > -1:
					copy = fringe[fringe_index]
					if total_utility < copy._heurval + copy._depth:
                        # copy the successor's values over the existing node
						copy._heurval = heurval
						copy._parent = move._parent
						copy._depth = move._depth
				elif path_index > -1:
					copy = path[path_index]
					if total_utility < copy._heurval + copy._depth:
						move._heurval = heurval
						path.remove(copy)
						fringe.append(move)

			path.append(x)
			if algorithm == 'BFS' or algorithm == 'UCS':
				fringe = sorted(fringe, key=lambda p: p._depth)
			elif algorithm == 'A*':
				fringe = sorted(fringe, key=lambda p: p._heurval + p._depth) 
				
        # if the goal state is never reached, return an empty list (representing the path taken is null) 
		# and 0 for the number of steps.
		return [], 0
	
    def solve_DFS(self):
        # performs DFS search for goal state.		

        def is_solved(puzzle):
            return puzzle.adj_matrix == _goal_state

        fringe = util.Stack()
        visited = list()
        move_count = 0
        
        fringe.push(self)
        while not fringe.isEmpty():
            node = fringe.pop()
            move_count += 1

            if(node not in visited):
                visited.append(node)
            
                if (is_solved(node)):
                    return node._generate_solution_path([]), move_count
                    
                successor = node._generate_moves()
                for move in successor:
                    move.parent = node
                    fringe.push(move)
             
        return [], 0
	

def heur(puzzle, item_total_util, total_util):
    """
    heuristic template that provides the current and target position for each number and the 
    total function.
    
    parameters:
    puzzle - the puzzle
    item_total_util - takes 4 parameters: current row, target row, current col, target col. returns int.
    total_util - takes 1 parameter, the sum of item_total_util over all entries, and returns int. 
    """
    t = 0
    utilit = util.utility()
    for row in range(3):
        for col in range(3):
            val = utilit.peek(puzzle, row,
                              col) - 1  # value is -1 if the peeked index is 0. triggers if target_row < 0 below.
            target_col = val % 3
            target_row = val / 3

            # account for 0 as blank
            if target_row < 0:
                target_row = 2
            t += item_total_util(row, target_row, col, target_col)


    return total_util(t)

# both h_manhattan and h_default are to be used with the heur() function above
# the lambda arguments in the return statement below specify how to use total_calc and item_total_calc above.

def h_manhattan(puzzle):
    return heur(puzzle,
                lambda r, tr, c, tc: abs(tr - r) + abs(tc - c),
                lambda t: t)


def h_default(puzzle):
    return 0


def main():
	utility = util.utility()
	p = EightPuzzle()
	shuffle = utility.shuffle(p, 20)
	print "Starting puzzle:" 
	print shuffle
	
	selection = raw_input("Which algorithm would you like to use to solve this matrix? (DFS, BFS, UCS, A*, or All for all four) \n")
	if selection == "DFS":
		path, count = shuffle.solve_DFS()
		path.reverse()
		print "Path to goal state:"
		for i in path:
			print i
		print "Solved with DFS search in", count, "node expansions"
	elif selection == "BFS":
		path, count = shuffle.solve(h_default, 'BFS')
		path.reverse()
		print "Path to goal state:"
		for i in path:
			print i
		print "Solved with BFS search in", count, "node expansions"
	elif selection == "UCS":
		path, count = shuffle.solve(h_default, 'UCS')
		path.reverse()
		print "Path to goal state:"
		for i in path:
			print i
		print "Solved with UCS search in", count, "node expansions"
	elif selection == "A*":
		path, count = shuffle.solve(h_manhattan, 'A*')
		path.reverse()
		print "Path to goal state:"
		for i in path:
			print i
		print "Solved with A* search utilizing Manhattan distance hueuristic in", count, "node expansions"
	elif selection == "All" or "all":
		path, count = shuffle.solve(h_manhattan, 'A*')
		path.reverse()
		print "Path to goal state:"
		for i in path:
			print i
		print "Solved with A* search utilizing Manhattan distance hueuristic in", count, "node expansions"
		path, count = shuffle.solve(h_default, 'UCS')
		print "Solved with UCS search in", count, "node expansions"
		path, count = shuffle.solve(h_default, 'BFS')
		print "Solved with BFS search in", count, "node expansions"
		path, count = shuffle.solve_DFS()
		print "Solved with DFS search in", count, "node expansions"
	
if __name__ == "__main__":
    main()
