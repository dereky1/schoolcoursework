#Project #4: The Width of a Circle (Part 1)
#Derek Yang
#63118832
#Othello User Interface Module

import othellogame

def run_ui() -> None:

    othello = othellogame.gamestate()
    print(othello.rules)
    not_invalid = True
    
    rows = get_inputs('rows')
    cols = get_inputs('cols')
    turn = get_inputs('turn')
    topleft = get_inputs('topleft')
    win = get_inputs('win')

    othello.new_game(rows, cols, turn, topleft, win)
    print_board(othello)


    while othello.win_or_not():

        if othello.turn == othellogame.BLACK:
            if othello.black_turn == -1:
                othello.change_turns()
                continue
        else:
            if othello.white_turn == -1:
                othello.change_turns()
                continue
        
        if not_invalid:
            print_turn(othello)
        else:
            not_invalid = True
        
        move = input('')
        
        try:
            row, col = move.split(' ')
        except ValueError:
            print('INVALID')
            not_invalid = False
            continue
        
        try:
            othello.make_move(int(row),int(col))
            print_board(othello)
        except:
            print('INVALID')
            not_invalid = False

    else:
        print_winner(othello)
        raise SystemExit
        

#gets user inputs
def get_inputs(parameter: str):

    if parameter == 'win' or parameter == 'turn' or parameter == 'topleft':
        number = input('')
    else:
        number = int(input(''))

    try:    
        if othellogame.validate_input(parameter, number):
            return number
    except othellogame.InvalidInputError:
        get_inputs(parameter)


#prints the board
def print_board(othello: 'gamestate') -> None:
    
    othello.count_pieces()
    print("B: {} W: {}".format(othello.black, othello.white))
    
    pixel = ''
    for row in range(othello.rows):
        for col in range(othello.cols):
            if othello.board[row][col] != othellogame.BOUND:
                if othello.board[row][col] == othellogame.NONE:
                    pixel='.'
                elif othello.board[row][col] == othellogame.BLACK:
                    pixel='B'
                elif othello.board[row][col] == othellogame.WHITE:
                    pixel='W'
                print('{} '.format(pixel),end='')
        if pixel != '':
            print('')
            pixel = '' 


#prints out the winner
def print_winner(othello: 'gamestate') -> None:
    if othello.win == '>':
        if othello.black > othello.white:
            print('WINNER: BLACK')
        elif othello.white > othello.black:
            print('WINNER: WHITE')
        else:
            print('WINNER: NONE')
    else:
        if othello.black < othello.white:
            print('WINNER: BLACK')
        elif othello.white < othello.black:
            print('WINNER: WHITE')
        else:
            print('WINNER: NONE')


#prints which players turn
def print_turn(othello: 'gamestate') -> None:
    
    if othello.turn == othellogame.BLACK:
        turn = 'B'
    else:
        turn = 'W'
        
    print('TURN: {}'.format(turn))


if __name__ == '__main__':
    run_ui()
