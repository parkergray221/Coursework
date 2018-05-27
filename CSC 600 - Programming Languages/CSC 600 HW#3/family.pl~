% Facts

m(['Parker','Brennan','Bob','Brian','Mike','Jordan','GreatGramps']).
f(['Barbara','Elizabeth','Sharon','Darlene','Susan','Hayley','GreatGrams']).
family(['GreatGramps','GreatGrams',['Elizabeth']]). %Great Ancestor Mom's Side
family(['Darlene',['Bob']]). %Grandma Dad's Side
family(['Elizabeth',['Barbara','Susan','Sharon']]). %Grandma Mom's Side
family(['Bob','Barbara',['Parker','Brennan']]). %Gray family
family(['Mike','Susan',['Jordan','Hayley']]). %Elwell family
family(['Brian','Sharon']). %Mars family

% Rules

male(X) :- m(M), member(X,M). %X is a male if X is M.
female(X) :- f(F), member(X,F). %X is a female is X is F.

parent(P,C) :- family([P,_,X]), member(C,X). %P is father of C if P is in head
parent(P,C) :- family([_,P,X]), member(C,X). %and child is in tail list.
father(P,C) :- male(P), parent(P,C).
mother(P,C) :- female(P), parent(P,C).

siblings1(X,Y) :- father(F,X), father(F,Y), mother(M1,X), mother(M2,Y), M1\=M2, X\=Y. %children with the same father
siblings1(X,Y) :- father(F1,X), father(F2,Y), mother(M,X), mother(M,Y), F1\=F2, X\=Y. %children with the same mother
brother1(X,Y) :- male(X), siblings1(X,Y).
sister1(X,Y) :- female(X), siblings1(X,Y).

siblings2(X,Y) :- father(F,X), father(F,Y), mother(M,X), mother(M,Y), X\=Y.
brother2(X,Y) :- male(X), siblings2(X,Y).
sister2(X,Y) :- female(X), siblings2(X,Y).

cousins(X,Y) :- parent(A,X), parent(B,Y), siblings1(A,B), X\=Y.
cousins(X,Y) :- parent(A,X), parent(B,Y), siblings2(A,B), X\=Y.
uncle(U,C) :- parent(P,C), brother1(U,P).
uncle(U,C) :- parent(P,C), brother2(U,P).
aunt(A,C) :- parent(P,C), sister1(A,P).
aunt(A,C) :- parent(P,C), sister2(A,P).

grandchild(GC,GP) :- parent(P,GC), parent(GP,P).
grandson(GS,GP) :- male(GS), grandchild(GS,GP).
granddaughter(GD,GP) :- female(GD), grandchild(GD,GP).
greatgrandparent(GGP,C) :- parent(P,C), grandchild(P,GGP).

ancestor(A,C) :- parent(A,C).
ancestor(A,C) :- parent(P,C), ancestor(A,P).
