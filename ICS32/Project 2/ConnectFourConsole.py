#Karen Liang 45492235 and Derek Yang 63118832

import connectfour

def connectfour_ui ():
    newgame = connectfour.new_game ()
    print_board(newgame)
    updated_game = connectfour.drop (newgame, player_move())
    print_board (updated_game)
    updated_game = connectfour.drop (updated_game, player_move())
    print_board (updated_game)

    while True:
        if connectfour.winner(updated_game) == connectfour.NONE:
            p_or_d = pop_or_drop()
            if p_or_d == 'D':
                try:
                    updated_game = connectfour.drop (updated_game, player_move())
                    print_board (updated_game)
                except connectfour.InvalidMoveError:
                    print("Invalid Move. try Again!")
                    continue
            elif p_or_d == 'P':
                try:
                    updated_game = connectfour.pop (updated_game, player_move())
                    print_board (updated_game)
                except connectfour.InvalidMoveError:
                    print("Invalid Move. Try Again!")
                    continue
        else:
            winner = connectfour.winner(updated_game)
            if winner == connectfour.RED:
                print("RED Player is the Winner!")
            else:
                print("YELLOW Player is the Winner!")
            break              

def print_board (GameState):
    numbered_column = ''
    newboard = connectfour._copy_game_board (GameState.board)
    columns = range (1, connectfour.BOARD_COLUMNS +1)
    width = connectfour.BOARD_COLUMNS
    
    for numbers in columns:
        numbered_column += str (numbers) + ' '
    print (numbered_column)
    pixel=''
    for row in range(connectfour.BOARD_ROWS):
        for col in range(connectfour.BOARD_COLUMNS):
            if newboard[col][row]==connectfour.NONE:
                pixel='.'
            elif newboard[col][row]==connectfour.RED:
                pixel='R'
            elif newboard[col][row]==connectfour.YELLOW:
                pixel='Y'
            print('{} '.format (pixel),end='')
        print()
    if connectfour.winner(GameState) == connectfour.NONE:
        if GameState.turn == connectfour.RED:
            print ("It is RED player's turn.")
        else:
            print ("It is YELLOW player's turn.")
    else:
        return

def player_move()-> int:
    while True:
        try:
            column_input = int (input ('Please input column (1-7)'))
        except ValueError:
            print ('ERROR! Not in range.')
            continue
        if column_input in range (1, connectfour.BOARD_COLUMNS + 1 ):
            return column_input - 1
        else:
            print ('ERROR! Not in range.')
        
def pop_or_drop ():
    while True:
        p_or_d_input = input ('Do you want to pop or drop? Enter p or d: ')
        upper_p_or_d = p_or_d_input.upper ()
        if (upper_p_or_d == 'P') or (upper_p_or_d =='D'):
            return upper_p_or_d
        else:
            print ('Error! Please enter p or d: ')
        
            
      
if __name__ == '__main__':
    connectfour_ui ()
