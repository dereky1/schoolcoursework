#Karen Liang 45492235 and Derek Yang 63118832

import connectfour
import ConnectFourProtocol
import ConnectFourConsole

def test () -> None:
    c4connection = ConnectFourProtocol.connect ()
    user = ConnectFourProtocol.get_user ()
    

    ConnectFourProtocol._write_line(c4connection, 'I32CFSP_HELLO ' + user)
    print (ConnectFourProtocol._read_line (c4connection))

    ConnectFourProtocol._write_line (c4connection, 'AI_GAME')
    print (ConnectFourProtocol._read_line (c4connection))

    while True:
        ConnectFourProtocol._write_line (c4connection, 'DROP ' + user_input())
        print (ConnectFourProtocol._read_line (c4connection)) 
        print(ConnectFourProtocol._read_line (c4connection))
        print(ConnectFourProtocol._read_line (c4connection))
    else:
        ConnectFourProtocol.close ()


def user_input () -> int:
    userinput =  input ('Enter column number: ')
    return userinput
    
test ()
