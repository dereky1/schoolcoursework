#Karen Liang 45492235 and Derek Yang 63118832

import collections
import connectfour
import ConnectFourFunctions

def connectfour_ui ():
    newgame = connectfour.new_game ()

    ConnectFourFunctions.print_board(newgame)
    updated_game = connectfour.drop (newgame, ConnectFourFunctions.player_move())
    ConnectFourFunctions.print_board (updated_game)
    updated_game = connectfour.drop (updated_game, ConnectFourFunctions.player_move())
    ConnectFourFunctions.print_board (updated_game)

    while True:
        if connectfour.winner(updated_game) == 0:
            p_or_d = ConnectFourFunctions.pop_or_drop()
            if p_or_d == 'D':
                try:
                    updated_game = connectfour.drop (updated_game, ConnectFourFunctions.player_move())
                    ConnectFourFunctions.print_board (updated_game)
                except connectfour.InvalidMoveError:
                    print("Invalid Move. try Again!")
                    continue
            elif p_or_d == 'P':
                try:
                    updated_game = connectfour.pop (updated_game, ConnectFourFunctions.player_move())
                    ConnectFourFunctions.print_board (updated_game)
                except connectfour.InvalidMoveError:
                    print("Invalid Move. Try Again!")
                    continue
        else:
            winner = connectfour.winner(updated_game)
            named_winner = ConnectFourFunctions.player_name (winner)
            print("{} player is the winner!".format(named_winner))
            break              


            

    

if __name__ == '__main__':
    connectfour_ui ()
