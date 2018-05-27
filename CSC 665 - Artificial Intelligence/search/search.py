# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()

class Node:

	def __init__(self, state, parent=None, action=None, path_cost=0):
		self.state = state
		self.parent = parent
		self.action = action
		if parent:
			self.path_cost = parent.path_cost + path_cost
			self.depth = parent.depth + 1
		else:
			self.path_cost = path_cost
			self.depth = 0
	
	def __repr__(self):
		return "<Node %s>" % (self.state,)
	
	def nodePath(self):
		x, result = self, [self.action] #x is the calling node, result is a list of nodes.
		while x.parent.action: # if x has a parent...
			result.append(x.parent.action) # append the parent to the list 
			x = x.parent # set x to become the parent and repeat the process.
		result.reverse() # reverse the list such that the parents are on the top assuming all parents of a node have been found.
		return result
	
	def expand(self, problem):
		return [Node(next, self, act, cost) 
				for (next, act, cost) in problem.getSuccessors(self.state)]
				
def graphSearch(problem, fringe):
	startstate = problem.getStartState()
	fringe.push(Node(problem.getStartState()))
	try: 
		startstate.__hash__()
		visited = set()
	except:
		visited = list()
		
	while not fringe.isEmpty():
		node = fringe.pop()
		if problem.isGoalState(node.state):
			return node.nodePath()
		try:
			inVisited = node.state in visited
		except:
			visited = list(visited)
			inVisited = node.state in visited
		
		if not inVisited:
			if isinstance(visited, list):
				visited.append(node.state)
			else:
				visited.add(node.state)
			nextNodes = node.expand(problem)
			
			for nextnode in nextNodes:
				fringe.push(nextnode)
				
	return None

def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print "Start:", problem.getStartState()
    print "Is the start a goal?", problem.isGoalState(problem.getStartState())
    print "Start's successors:", problem.getSuccessors(problem.getStartState())
    """
    return graphSearch(problem, util.Stack())
    util.raiseNotDefined()

def breadthFirstSearch(problem):
    """Search the shallowest nodes in the search tree first."""
    return graphSearch(problem, util.Queue())
    util.raiseNotDefined()

def uniformCostSearch(problem):
    """Search the node of least total cost first."""
    return graphSearch(problem, util.PriorityQueueWithFunction(lambda node: node.path_cost))
    util.raiseNotDefined()

def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    return graphSearch(problem, util.PriorityQueueWithFunction(lambda node: node.path_cost + heuristic(node.state, problem)))
    util.raiseNotDefined()


# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
