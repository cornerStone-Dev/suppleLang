// suppleLangLex.re

/*!max:re2c*/                        // directive that defines YYMAXFILL
/*!re2c                              // start of re2c block
	
	// comments and white space
	scm = "//" [^\n\x00]* "\n";
	wsp = ([ \r\n\t] | scm )+;

	// integer literals
	oct = "0" [0-7]*;
	dec = [1-9][0-9]*;
	hex = '0x' [0-9A-F]+; // a-f removed
	integer = "-"? (oct | dec | hex);

	// floating literals
	frc = [0-9]* "." [0-9]+ | [0-9]+ ".";
	exp = 'e' [+-]? [0-9]+;
	flt = "-"? (frc exp? | [0-9]+ exp) [fFlL]?;

	// string literals
	string_lit = ["] ([^"\x00] | ([\\] ["]))* ["];
	string_lit_chain = ([^"\n] | ([\\] ["]))* "\n";
	string_lit_end = ([^"\n] | ([\\] ["]))* ["];
	
	// character literals
	char_lit = ['] ([^'\\\x00] | ([\\] ['nrt\\])) ['];
	
	identifier = [a-zA-Z_!$%&/*:<>=?\x5e~][a-zA-Z_!$%&/*:<>=?\x5e~0-9+.@-]*;
	
*/                                   // end of re2c block


static s32
suppleLexOptions(u8 *YYCURSOR)
{
	u8 *YYMARKER;
	u8 *start;

	start = YYCURSOR;

	/*!re2c                            // start of re2c block **/
	re2c:define:YYCTYPE = "u8";
	re2c:yyfill:enable  = 0;

	* { printf("Invalid Option: %s, try --help.\n",start); return 0; }
	[\x00] { printf("Invalid Option: NULL try --help.\n"); return 0; }
	
	"--help" {
		return 1;
	}
	
	"--repl" {
		return 2;
	}
	
	[a-zA-Z_/0-9] [a-zA-Z_/0-9-]* ".gift" {
		return 3;
	}
	
	*/                                  // end of re2c block
}

// cursor, line number, token ID, String pointer, string length, meta
// returns memory filled with tokens
Token*
tokenizeString(u8 *string)
{
	u8 *YYCURSOR = string;
	// allocate massive amount of space for tokens, will resize before we return
	Token *tokens = malloc(sizeof(token)*4096*1024);
	Token *tokenCursor = tokens;
	u64 lineNumber = 1;
	
//~ loop:
	
	return tokens;
}




