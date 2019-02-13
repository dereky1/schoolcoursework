#Karen Liang 45492235 and Derek Yang 63118832

import connectfour
import ConnectFourProtocol
import ConnectFourConsole
import ConnectFourFunctions


class protocolerror (Exception):
    pass



def test () -> None:
    c4connection = ConnectFourProtocol.connect ()
    user = ConnectFourProtocol.get_user ()


    ConnectFourProtocol._write_line(c4connection, 'I32CFSP_HELLO ' + user)
    print (ConnectFourProtocol._read_line (c4connection))

    ConnectFourProtocol._write_line (c4connection, 'AI_GAME')
    print (ConnectFourProtocol._read_line (c4connection))


    
##    newgame = connectfour.new_game ()
##    ConnectFourFunctions.print_board(newgame)
##    updated_game = connectfour.drop (newgame, ConnectFourFunctions.player_move())
##    ConnectFourFunctions.print_board (updated_game)

    
    while True:

        ConnectFourProtocol._write_line (c4connection, 'DROP ' + str (ConnectFourFunctions.player_move(1)))
        ProtocolArray = []
        
        while True:
            readProtocol =  (ConnectFourProtocol._read_line (c4connection))
            print (readProtocol)
            ProtocolArray.append (readProtocol)
            if ProtocolArray [-1] == 'READY':
                break
            elif ProtocolArray [-1] == 'WINNER_RED' or ProtocolArray [-1] == 'WINNER_YELLOW':
                raise SystemExit
    
                

       
            


                    
##                if (ConnectFourProtocol._read_line (c4connection)) == "/r/n":
##                    raise protocolerror
####            except protocolerror:
####                print ('exception')
####                break
##            

        
##        if connectfour.player_name == 'RED':
##            p_or_d = ConnectFourFunctions.pop_or_drop()
##            if p_or_d == 'D':
##                    updated_game = connectfour.drop (updated_game, ConnectFourFunctions.player_move())
##                    ConnectFourFunctions.print_board (updated_game)
##                
##            elif p_or_d == 'P':
##                    updated_game = connectfour.pop (updated_game, ConnectFourFunctions.player_move())
##                    ConnectFourFunctions.print_board (updated_game)
##        else:
##            ConnectFourProtocol._write_line (c4connection, 'DROP ' + str (ConnectFourFunctions.player_move()))

    else:
        ConnectFourProtocol.close ()


def user_input () -> int:
    userinput =  input ('Enter column number: ')
    return userinput
    
test ()
