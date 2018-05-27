% X/Y is a spot on the coordinate plane corresponding to (column, row)
% of a queen. nocheck() verifies if the given X/Y coordinate pair checks
% any other queens. If there are no other queens checked by X/Y, return
% true.
nocheck(_,[]).
nocheck(X/Y,[X1/Y1 | Rest]) :-
	% X=\=X1, x's are assumed to be distinct from one another in eightqueens(X)
	Y=\=Y1,
	abs(Y1-Y) =\= abs(X1-X),
	nocheck(X/Y, Rest).

% legal(L) checks if the placement of queens is 'valid'- no queens check
% one another and the x/y coords given are valid for the board.
legal([]).
legal([X/Y | Rest]) :-
	legal(Rest),
	% member(X,[1,2,3,4,5,6,7,8]), x's are already a membr of this set in eightqueens(X)
	member(Y,[1,2,3,4,5,6,7,8]),
        nocheck(X/Y, Rest).

% If we want to give all of the queens locations at once, use
% eight_queens(X) to check if X is a legal placement of the queens. each
% element of the list is listed with its x coordinate coming first
% before the /.
eightqueens(X) :-
	X = [1/_,2/_,3/_,4/_,5/_,6/_,7/_,8/_],
        legal(X).
