
# -- STEP ONE RENAMING STAGE -- #
from FUNCTIONS.TokenStep1 import scanOutput
tokens = scanOutput()
lexemes = []
file_object = open('DUMP/SymbolTable.txt', 'w')
file_object.write('')
file_object = open('DUMP/SymbolTable.txt', 'a')
for x in tokens:
    file_object.write(x.token + " " + x.lexeme + "\n")
file_object.close()

# -- STEP TWO OF RENAMING STAGE -- #
from FUNCTIONS.TokenStep2 import scanOutputv2
tokens = scanOutputv2()
lexemes = []
file_object = open('DUMP/SymbolTableV2.txt', 'w')
file_object.write('')
file_object = open('DUMP/SymbolTableV2.txt', 'a')
for x in tokens:
    file_object.write(x.lexeme + " " + x.token+ "\n")
#file_object.write( "End_of_input" )
file_object.close()



# -- ADDING SECOND COLUMN IN FILE -- #
from FUNCTIONS.SECOND_COLUMN_TRACKER import TRACK_SECOND_COLUMN
hey = TRACK_SECOND_COLUMN()
j = 0;
file_object = open('DUMP/SymbolTableV3.txt', 'w')
file_object.write('')
file_object = open('DUMP/SymbolTableV3.txt', 'a')
filepath = 'DUMP/SymbolTableV2.txt'
with open(filepath) as file:
    for line in file:
        k = hey[j]
        l = line.rstrip().split(' ', 1)[-1]
        position = k.find(l)
        if position != -1:
            print(f"{position + 1} " + line.rstrip(), file=file_object)
        if (line.rstrip().split(' ', 1)[-1]) == hey[j][-1]:
            j = j + 1
            pass


# -- ADDING FIRST COLUMN IN FILE -- #

from FUNCTIONS.FIRST_COLUMN_TRACKER import TRACK_FIRST_COLUMN
hey = TRACK_FIRST_COLUMN()
j = 0
file_object = open('DUMP/SymbolTableV4.txt', 'w')
file_object.write('')
file_object = open('DUMP/SymbolTableV4.txt', 'a')
filepath = 'DUMP/SymbolTableV2.txt'
with open(filepath) as file:
    for line in file:
        if any((line.rstrip().split(' ', 1)[-1]) in s for s in hey[j]):
            print(f"{j+1} " +  line.rstrip(), file=file_object)
            if (line.rstrip().split(' ', 1)[-1]) == hey[j][-1]:
                j = j + 1
                pass


# -- FINAL -- #

from FUNCTIONS.FIRST_COLUMN_TRACKER import TRACK_FIRST_COLUMN
hey = TRACK_FIRST_COLUMN()
j = 0
file_object = open('SYMBOLTABLE.txt', 'w')
file_object.write('')
file_object = open('SYMBOLTABLE.txt', 'a')
filepath = 'DUMP/SymbolTableV3.txt'
with open(filepath) as file:
    for line in file:
        if any((line.rstrip().split(' ')[-1]) in s for s in hey[j]):
            print(f"{j+1} " +  line.rstrip(), file=file_object)
            if (line.rstrip().split(' ')[-1]) == hey[j][-1]:
                j = j + 1
                pass
    file_object.write(f"{j+1}" + " " + "1 " + "End_of_input")

