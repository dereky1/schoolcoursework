#Karen Liang 45492235 and Derek Yang 63118832

import collections
import connectfour

def print_board (GameState):
    numbered_column = ''
    newboard = connectfour._copy_game_board (GameState.board)
    columns = range (1, connectfour.BOARD_COLUMNS +1)
    width = connectfour.BOARD_COLUMNS
    name = player_name (GameState.turn)
    
    for numbers in columns:
        numbered_column += str (numbers) + ' '
    print (numbered_column)
    pixel=''
    for row in range(connectfour.BOARD_ROWS):
        for col in range(connectfour.BOARD_COLUMNS):
            if newboard[col][row]==0:
                pixel='.'
            elif newboard[col][row]==1:
                pixel='R'
            elif newboard[col][row]==2:
                pixel='Y'
            print('{} '.format (pixel),end='')
        print()
        
    if connectfour.winner(GameState) == 0:
        print ("It is {} player's turn.".format (name))
    else:
        return

    
def player_name (turn: int) -> str:
    if turn == 1:
        return 'RED'
    elif turn == 2:
        return 'YELLOW'
    else:
        return 'No'


def pop_or_drop ():
    while True:
        p_or_d_input = input ('Do you want to pop or drop? Enter P or D. ')
        upper_p_or_d = p_or_d_input.upper ()
        if  (upper_p_or_d == 'P') or (upper_p_or_d == 'D'):
            return  upper_p_or_d
        else:
            print ('ERROR! Please enter p or d.')


def player_move(mode)-> int:
##    if mode == 0:
##        column_input = (input ('Please input column (1-7) ')).strip()
##        return column_input
##    else:
    while True:
        column_input = (input ('Please input column (1-7) ')).strip()
        try:
            col_input = int(column_input)
            #column_input = int ((input ('Please input column (1-7) ')).strip())
        except ValueError:
            if mode == 0:
                print ('ERROR! Not in range.')
                continue
            else:
                return column_input
                
 
        if column_input in range (1, connectfour.BOARD_COLUMNS + 1 ):
            return column_input
        elif column_input == "":
            print ('ERROR! Not in range.')
        else:
            print ('ERROR! Not in range.')
##        else:
##            if mode == 0:
##                print ('ERROR! Not in range.')
##            else:
##                return column_input



