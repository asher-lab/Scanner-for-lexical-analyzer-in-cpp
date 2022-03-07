def TRACK_FIRST_COLUMN ():
        a_file = open("././DUMP/tank.por", "r")
        list_of_lists = []
        for line in a_file:
            stripped_line = line.strip()
            line_list = stripped_line.split()
            list_of_lists.append(line_list)
        return (list_of_lists)
        a_file.close()
