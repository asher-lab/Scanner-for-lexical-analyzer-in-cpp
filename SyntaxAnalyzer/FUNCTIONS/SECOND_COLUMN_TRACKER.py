def TRACK_SECOND_COLUMN():
    a_file = "././DUMP/tank.por"
    with open(a_file) as file:
        lines = [line.rstrip('\n') for line in file]
    return(lines)
