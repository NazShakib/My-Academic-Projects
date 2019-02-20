grammar Calculator;


PLUS 	: '+' ;
MINUS	: '-' ;
MULT	: '*' ;
DIV	    : '/' ;
RPAREN	: ')' ;
LPAREN	: '(' ;
ASSIGN	: '=' ;
PI     : 'pi';
DOUBLE : [0-9]+'.'[0-9]+;
ID 	:	('a'..'z'|'A'..'Z')+;
INT 	:	'0'..'9'+;
NEWLINE :	'\r'?'\n';


prog :		start+;
start :		expr NEWLINE
	|	ID ASSIGN expr NEWLINE
	|	NEWLINE; 			

expr 	:	multipleExpr ((PLUS | MINUS )multipleExpr)*;

multipleExpr:	atom ((MULT | DIV) atom )*;

atom 	:	INT
	|	ID
	|	LPAREN expr RPAREN
	|   DOUBLE
	|	PI    ;

WS 	:	(' '|'\t'|'\n'|'\r')+ -> skip;


