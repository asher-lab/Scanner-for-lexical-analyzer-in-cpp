
class Token:
    def __init__(self,token,lexeme):
        self.token = token
        self.lexeme = lexeme


def scanOutput():
    f = open("././DUMP/Output1.txt", "r")
    tokenList = []
    DATA_TYPES_INT = ["1"]
    DATA_TYPES_FLOAT = ["float"]
    DATA_TYPES_DOUBLE = ["double"]
    DATA_TYPES_BOOL = ["bool"]
    DATA_TYPES_CHAR = ["char"]

    DATA_TYPES = ["int", "float", "double", "char", "bool"]

    SEMICOLON = [";"]
    ADDITION = ["+"]
    SUBTRACTION = ["-" ]
    DIVISION = ["/"]
    MODULO = ["%"]
    MULT = ["*"]
    ASSIGN = ["="]
    LESSEQUAL = ["<="]
    GREATEREQUAL = [">="]
    NONEQUAL = ["!="]
    EQUALEQUAL = ["=="]
    AND = ["&&"]
    OR = ["||"]
    GREATER = [">"]
    LESS = ["<"]

    PRINT = ["out"]
    IFF = ["if"]
    ELSEE = ["if"]
    WHILE = ["while"]

    IDENTIFIER = 1


    LEFT_PAREN = ["("]
    RIGHT_PAREN = [")"]

    LEFT_BRAK = ["["]
    RIGHT_BRAK = ["]"]
    LEFT_BRAC = ["{"]
    RIGHT_BRAC = ["}"]

    IDENTIFIER = 1
    STRING = 1
    COMMA = [","]

    for x in f:




        # -- CHANGE to Integer
        if x.split(' ', 1)[0].isnumeric():
            y = x.replace("ValidInteger", "Integer")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to Semicolon
        elif x.split(' ', 1)[0] in SEMICOLON:
            y = x.replace("ValidDelimiter", "Semicolon")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to Keyword_while
        elif x.split(' ', 1)[0] in DATA_TYPES:
            y = x.replace("ValidKeyword", "DataType")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue


        # -- CHANGE to Keyword_while
        elif x.split(' ', 1)[0] in WHILE:
            y = x.replace("ValidIdentifier", "Keyword_while")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue



        # -- CHANGE to LeftParen
        elif x.split(' ', 1)[0] in LEFT_PAREN:
            y = x.replace("ValidParenthesis", "LeftParen")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to RightParen
        elif x.split(' ', 1)[0] in RIGHT_PAREN:
            y = x.replace("ValidParenthesis", "RightParen")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue


        # -- CHANGE to Op_assign
        elif x.split(' ', 1)[0] in ASSIGN:
            y = x.replace("ValidAssignmentOperator", "Op_assign")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue


        # -- CHANGE to Op_add
        elif x.split(' ', 1)[0] in ADDITION:
            y = x.replace("ValidAdditionOperator", "Op_add")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to Op_less
        elif x.split(' ', 1)[0] in LESS:
            y = x.replace("ValidLessthanOperator", "Op_less")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to LefBrace
        elif x.split(' ', 1)[0] in LESS:
            y = x.replace("ValidCurlyBrackets", "LeftBrace")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to Keyword_print
        elif x.split(' ', 1)[0] in PRINT:
            y = x.replace("ValidKeyword", "Keyword_print")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to LeftBrace
        elif x.split(' ', 1)[0] in LEFT_BRAC:
            y = x.replace("ValidCurlyBrackets", "LeftBrace")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue
        # -- CHANGE to RightBrace
        elif x.split(' ', 1)[0] in RIGHT_BRAC:
            y = x.replace("ValidCurlyBrackets", "RightBrace")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to Comma
        elif x.split(' ', 1)[0] in COMMA:
            y = x.replace("ValidComma", "Comma")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to LessEqual
        elif x.split(' ', 1)[0] in LESSEQUAL:
            y = x.replace("ValidLessthanorEqualtoOperator", "Op_lessequal")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to GreaterEqual
        elif x.split(' ', 1)[0] in GREATEREQUAL:
            y = x.replace("ValidGreaterthanorEqualtoOperator", "Op_greaterequal")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to NonEqual
        elif x.split(' ', 1)[0] in NONEQUAL:
            y = x.replace("ValidNotEqualtoOperator", "Op_notequal")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to Op_equal
        elif x.split(' ', 1)[0] in EQUALEQUAL:
            y = x.replace("ValidEqualOperator", "Op_equal")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to Op_and
        # -- wrong in lexical of Andrew
        elif x.split(' ', 1)[0] in AND:
            y = x.replace("ValidOrOperator", "Op_and")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to Op_or
        # -- wrong in lexical of Andrew
        elif x.split(' ', 1)[0] in OR:
            y = x.replace("ValidAndOperator", "Op_or")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to Op_greater
        elif x.split(' ', 1)[0] in GREATER:
            y = x.replace("ValidGreaterthanOperator", "Op_greater")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue




        # -- CHANGE to String
        if STRING == 1:
            y = x.replace("ValidString", "String")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue


        # -- CHANGE to Identifier
        if IDENTIFIER == 1:
            y = x.replace("ValidIdentifier", "Identifiers")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue



        elif x.split(' ', 1)[0] in SUBTRACTION:
            y = x.replace("ValidSubtractionOperator", "ValidOperator")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue


        elif x.split(' ', 1)[0] in MULT:
            y = x.replace("ValidMultiplicationOperator", "ValidOperator")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue


        elif x.split(' ', 1)[0] in DIVISION:
            y = x.replace("ValidDivisionOperator", "ValidOperator")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue


        elif x.split(' ', 1)[0] in MODULO:
            y = x.replace("ValidModuloOperator", "ValidOperator")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue



        else:
            tokenList.append(Token(x.split()[0], x.split()[1]))
    f.close()
    return tokenList
