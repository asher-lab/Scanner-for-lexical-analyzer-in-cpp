
class Token:
    def __init__(self,token,lexeme):
        self.token = token
        self.lexeme = lexeme


def scanOutputv2():
    f = open("././DUMP/SymbolTable.txt", "r")
    tokenList = []
    IDENTIFIER = 1
    STRING = 1

    for x in f:
        # -- CHANGE to Identifier
        if IDENTIFIER == 1:
            y = x.replace("ValidIdentifier", "Identifier")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue

        # -- CHANGE to String
        if STRING == 1:
            y = x.replace("ValidString", "String")
            tokenList.append(Token(x.split()[0], y.split()[1]))
            continue
        else:
            tokenList.append(Token(x.split()[0], x.split()[1]))
    f.close()
    return tokenList
