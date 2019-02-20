grammar experiment;		
prog:	(em NEWLINE)* ;
em:  exf ('@') exl;
exf: ex | ex fex* ;
fex : ('.')ex;
exl: ex fex*;
ex : LE+;

NEWLINE : [\r\n]+ ;

LE :[a-z]+[0-9]*;
