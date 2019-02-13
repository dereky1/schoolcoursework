#Karen Liang 45492235 and Derek Yang 63118832

from collections import namedtuple
import socket
import connectfour

#ask for host and port
#ask for username
#connect
#error if unable to connect and close program
#run console if connection is succesful
#red player is user, yellow player is program

host = 'woodhouse.ics.uci.edu'
port = 4444
user = 'username'


ConnectFourConnection = namedtuple ('ConnectFourConnection', ['c4socket', 'c4input', 'c4output'])

class c4error (Exception):
    pass

def connect () -> ConnectFourConnection:
    host = get_host()
    port = get_port()
    
    connectfour_socket = socket.socket ()
    print ('connecting')
    
    try:
        connectfour_socket.connect ((host, port))
        print ('connected')
    except socket.gaierror:
        print ('Error! Invalid host or port.')
        raise SystemExit
        
    connectfour_input = connectfour_socket.makefile ('r')
    connectfour_output = connectfour_socket.makefile ('w')
    
    return ConnectFourConnection (
        c4socket = connectfour_socket,
        c4input = connectfour_input,
        c4output = connectfour_output)


def get_host ()-> str:
    while True:
        ConnectFourHost= input ('Enter host name: ').strip ()
        if ConnectFourHost == '':
            print ('Error! Incorrect host name')
        else:
            return ConnectFourHost
        
def get_port () -> int:
    while True:
        try:
            ConnectFourPort = int (input ('Enter port name: ').strip ())

            if (ConnectFourPort < 0) or (ConnectFourPort > 65535):
                print ('Error! Port must be an integer between 0 and 65535.')
            else:
                return ConnectFourPort
        except ValueError:
            print ('Error! Port must be an integer between 0 and 65535.')


def get_user () -> str:
    while True:
        ConnectFourUser= input ('Enter username: ')
        if ' ' in ConnectFourUser:
            print ("Error! Username can not contain whitespaces.")
        return ConnectFourUser

def _read_line (connection: ConnectFourConnection) -> str:
    return connection.c4input.readline () [:-1]

##def _expect_line (connection: ConnectFourConnection, expected: str)-> None:
##    line = _read_line (connection)
##    if line != expected:
##        raise c4error

def _write_line(ConnectFourConnection, line: str) -> None:
    ConnectFourConnection.c4output.write(line + '\r\n')
    ConnectFourConnection.c4output.flush()


def close (connection: ConnectFourConnection) -> None:
    connection.c4input.close ()
    connection.c4output.close ()
    connection.socket.close ()


##def send (connection: ConnectFourConnection, message:str, expected:str) -> None:
##    _write_line (connection, 'Sending' + message)
##    _expect_line (connection, expected + '\r\n')




##def test () -> None:
##    c4connection = connect ()
##    print (_read_line (c4connection))
##    while True:
##        try:
##             (c4connection, 'I32CFSP_HELLO ' + user, 'WELCOME ' + user)
##        except c4error:
##            print ('error')
