import connectfour



def MAIN() -> None:
    board = connectfour._new_game_board()
    test = [[1,2,3,4,5,6,7],[1,2,3,4,5,6,7],[1,2,3,4,5,6,7],[1,2,3,4,5,6,7],[1,2,3,4,5,6,7],[1,2,3,4,5,6,7]]
    print_board(test)


def print_board(board: [[str]]):
    for column in board:
        for row in column:
            print(str(row))

if __name__ == '__main__':
    MAIN ()
