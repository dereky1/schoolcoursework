import ConnectFourProtocol

def UI () -> None:
    connection = ConnectFourProtocol.connect ()
    try:
        while _hand_command_send (connection):
            print ('success')
    finally:
        print ('goodbye')
    
def _handle_send_command(connection: ConnectFourProtocol.ConnectFourConnection) -> None:
    '''
    Handles a Send command by asking the user what message they'd like to
    send, then sending it to the server.
    '''
    message_to_send = input('Message to Send: ').strip()

    if len(message_to_send) == 0:
        print('Empty messages are not allowed')
    else:
        ConnectFourProtocol.send(connection, message_to_send)
        print('Sent')


_handle_send_command(ConnectFourProtocol.ConnectFourConnection)
