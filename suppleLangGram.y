/*
 * grammar for a c-like language that is context free
*/

%include{
#define YYNOERRORRECOVERY 1
#define YYSTACKDEPTH 150
}

%extra_context {context *c}

%token_type   {tokenData}
%default_type {terminalData}

%syntax_error {
	printf("%d\n", c->lineNumber);
}

program ::= terminal_list(A).
{
	printf("parse done, input exhausted.\n");
	c->lineNumber = A.lineNumber;
}

terminal_list ::= TERMINAL.
terminal_list ::= terminal_list TERMINAL.
