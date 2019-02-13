#Project #4: The Width of a Circle (Part 1)
#Derek Yang
#63118832
#Othello Game Logic Module

import othelloui

BOUND = -1
NONE = 0
BLACK = 1
WHITE = 2

class InvalidInputError(Exception):
    pass

class InvalidMoveError(Exception):
    pass
    

class gamestate:
    def __init__(self):
        
        self.board = []
        self.rows = 2
        self.cols = 2
        self.turn = NONE
        self.rules = "FULL"
        self.top_left = NONE
        self.black = 2
        self.white = 2
        self.win = ''
        self.black_turn = -1
        self.white_turn = -1


    #initiallizes the new game board
    def new_game(self, rows: int, cols: int, turn: str, top_left: str, win: str) -> None:

        self.rows += rows
        self.cols += cols

        if turn == 'B':
            self.turn = 1
        else:
            self.turn = 2

        if top_left == 'B':
            self.top_left = 1
        else:
            self.top_left = 2
            
        self.win = win

        self.make_board()
            
        self.board[self.rows//2 - 1][self.cols//2 - 1] = self.top_left
        self.board[self.rows//2 - 1][self.cols//2] = self.opposite_turn(self.top_left)
        self.board[self.rows//2][self.cols//2 - 1] = self.opposite_turn(self.top_left)
        self.board[self.rows//2][self.cols//2] = self.top_left
        


    #makes a double list board   
    def make_board(self) -> None:
        
        for row in range(self.rows):
            self.board.append([])
            for col in range(self.cols):
                if row == 0 or row == self.rows - 1 or col == 0 or col == self.cols -1: 
                    self.board[-1].append(BOUND)
                else:
                    self.board[-1].append(NONE)


    #counts the black and white pieces
    def count_pieces(self) -> None:

        black_count = 0
        white_count = 0
        
        for row in range(self.rows):
            for col in range(self.cols):
                if self.board[row][col] == BLACK:
                    black_count += 1
                elif self.board[row][col] == WHITE:
                    white_count += 1
                    
        self.black = black_count
        self.white = white_count
                    

    #changes player turn
    def change_turns(self) -> None:
        
        if self.turn == WHITE:
             self.turn = BLACK
        else:
            self.turn = WHITE


    #returns opposite players turn
    def opposite_turn(self, turn: int) -> int:
        
        if turn == WHITE:
            return BLACK
        else:
            return WHITE


    #def place_piece_FULL(self, row: int, col: int) -> None:
    def check_position(self, row: int, col: int) -> bool:

        if self.board[row][col] != NONE:
            return False
        else:
            return True


    #makes the move if valid or raises exceptions
    def make_move(self, row: int, col: int) -> None:
        
        if self.check_all(row, col, 1) and self.check_position(row, col):
            self.board[row][col] = self.turn
            print('VALID')
            self.change_turns()
        else:
            raise InvalidMoveError


    #scans board to find any possible moves
    def any_moves(self) -> None:

        for row in range(self.rows):
            for col in range(self.cols):
                if self.board[row][col] != BOUND and self.board[row][col] == NONE:
                    if self.check_all(row, col, 0):
                        if self.turn == BLACK:
                            self.black_turn = 1
                            return
                        else:
                            self.white_turn = 1
                            return
                    else:
                        if self.turn == BLACK:
                            self.black_turn = -1
                        else:
                            self.white_turn = -1


    #determines whether the game has ended or not
    def win_or_not(self) -> bool:

        self.any_moves()

        if (self.black + self.white) == ((self.rows - 2) * (self.cols - 2)):
            return False
        elif self.black_turn == -1 and self.white_turn == -1:
            return False
        else:
            return True


#####################################
# Start of Validity Testing Methods #
#####################################

    #Runs validity test of input
    def check_all(self, row: int, col: int, mode: int) -> bool:

        down = self.check_down(row, col, mode)
        up = self.check_up(row, col, mode)
        left = self.check_left(row, col, mode)
        right = self.check_right(row, col, mode)
        up_right = self.check_up_right(row, col, mode)
        up_left = self.check_up_left(row, col, mode)
        down_left = self.check_down_left(row, col, mode)
        down_right = self.check_down_right(row, col, mode)

        if (down or up or left or right or up_right or up_left or down_left
            or down_right):
            return True
        
        else:
            return False
    
     
    def check_down(self, row: int, col: int, mode: int) -> bool:

        move = 0
        positions_list = []
        
        for rows in range(self.rows - row - 2):
            if self.board[row + 1 + rows][col] == NONE:
                return False
            
            elif self.board[row + 1 + rows][col] == BOUND:
                return False
            
            elif self.board[row + 1 + rows][col] == self.turn:
                if move == 0:
                    return False
                else:
                    if mode == 1:
                        for nums in positions_list:
                            self.board[nums][col] = self.turn    
                    return True
                
            elif self.board[row + 1 + rows][col] == self.opposite_turn(self.turn):
                move += 1         
                positions_list.append(row + 1 + rows)

            

    def check_up(self, row: int, col: int, mode: int) -> bool:

        move = 0
        positions_list = []
        
        for rows in range(row - 1):
            if self.board[row - 1 - rows][col] == NONE:
                return False
            
            elif self.board[row - 1 - rows][col] == BOUND:
                return False
            
            elif self.board[row - 1 - rows][col] == self.turn:
                if move == 0:
                    return False
                else:
                    if mode == 1:
                        for nums in positions_list:
                            self.board[nums][col] = self.turn
                    return True
                
            elif self.board[row - 1 - rows][col] == self.opposite_turn(self.turn):
                move += 1         
                positions_list.append(row - 1 - rows)



    def check_left(self, row: int, col: int, mode: int) -> bool:

        move = 0
        positions_list = []
        
        for cols in range(col - 1):
            if self.board[row][col - 1 - cols] == NONE:
                return False
            
            elif self.board[row][col - 1 - cols] == BOUND:
                return False
            
            elif self.board[row][col - 1 - cols] == self.turn:
                if move == 0:
                    return False
                else:
                    if mode == 1:
                        for nums in positions_list:
                            self.board[row][nums] = self.turn
                    return True
                
            elif self.board[row][col - 1 - cols] == self.opposite_turn(self.turn):
                move += 1         
                positions_list.append(col - 1 - cols)

    

    def check_right(self, row: int, col: int, mode: int) -> bool:

        move = 0
        positions_list = []

        for cols in range(self.cols - col - 2):
            if self.board[row][col + 1 + cols] == NONE:
                return False
            
            elif self.board[row][col + 1 + cols] == BOUND:
                return False
            
            elif self.board[row][col + 1 + cols] == self.turn:
                if move == 0:
                    return False
                else:
                    if mode == 1:
                        for nums in positions_list:
                            self.board[row][nums] = self.turn
                    return True
                
            elif self.board[row][col + 1 + cols] == self.opposite_turn(self.turn):
                move += 1         
                positions_list.append(col + 1 + cols)  



    def check_up_left(self, row: int, col: int, mode: int) -> bool:

            move = 0
            r_positions_list = []
            c_positions_list = []

            if col - 1 < row - 1:
                parameter = col - 1
            else:
                parameter = row - 1

            for units in range(parameter):
                if self.board[row - 1 - units][col - 1 - units] == NONE:
                    return False
                
                elif self.board[row - 1 - units][col - 1 - units] == BOUND:
                    return False
                
                elif self.board[row - 1 - units][col - 1 - units] == self.turn:
                    if move == 0:
                        return False
                    else:
                        if mode == 1:
                            for num in range(len(r_positions_list)):
                                r_num = r_positions_list[num]
                                c_num = c_positions_list[num]
                                self.board[r_num][c_num] = self.turn
                        return True
                    
                elif self.board[row - 1 - units][col - 1 - units] == self.opposite_turn(self.turn):
                    move += 1
                    r_positions_list.append(row - 1 - units)
                    c_positions_list.append(col - 1 - units)


    def check_up_right(self, row: int, col: int, mode: int) -> bool:

            move = 0
            r_positions_list = []
            c_positions_list = []

            if self.cols - col - 2 < row - 1:
                parameter = self.cols - col - 2
            else:
                parameter = row - 1

            for units in range(parameter):
                if self.board[row - 1 - units][col + 1 + units] == NONE:
                    return False
                
                elif self.board[row - 1 - units][col + 1 + units] == BOUND:
                    return False
                
                elif self.board[row - 1 - units][col + 1 + units] == self.turn:
                    if move == 0:
                        return False
                    else:
                        if mode == 1:
                            for num in range(len(r_positions_list)):
                                r_num = r_positions_list[num]
                                c_num = c_positions_list[num]
                                self.board[r_num][c_num] = self.turn 
                        return True
                    
                elif self.board[row - 1 - units][col + 1 + units] == self.opposite_turn(self.turn):
                    move += 1
                    r_positions_list.append(row - 1 - units)
                    c_positions_list.append(col + 1 + units) 



    def check_down_right(self, row: int, col: int, mode: int) -> bool:

            move = 0
            r_positions_list = []
            c_positions_list = []

            if self.cols - col - 2 > self.rows - row - 2:
                parameter = self.cols - col - 2
            else:
                parameter = self.rows - row - 2

            for units in range(parameter):
                if self.board[row + 1 + units][col + 1 + units] == NONE:
                    return False
                
                elif self.board[row + 1 + units][col + 1 + units] == BOUND:
                    return False
                
                elif self.board[row + 1 + units][col + 1 + units] == self.turn:
                    if move == 0:
                        return False
                    else:
                        if mode == 1:
                            for num in range(len(r_positions_list)):
                                r_num = r_positions_list[num]
                                c_num = c_positions_list[num]
                                self.board[r_num][c_num] = self.turn
                        return True
                    
                elif self.board[row + 1 + units][col + 1 + units] == self.opposite_turn(self.turn):
                    move += 1
                    r_positions_list.append(row + 1 + units)
                    c_positions_list.append(col + 1 + units)



    def check_down_left(self, row: int, col: int, mode: int) -> bool:

        move = 0
        r_positions_list = []
        c_positions_list = []

        if col - 1 > self.rows - row - 2:
            parameter = col - 1
        else:
            parameter = self.rows - row - 2

        for units in range(parameter):
            if self.board[row + 1 + units][col - 1 - units] == NONE:
                return False
            
            elif self.board[row + 1 + units][col - 1 - units] == BOUND:
                return False
            
            elif self.board[row + 1 + units][col - 1 - units] == self.turn:
                if move == 0:
                    return False
                else:
                    if mode == 1:
                            for num in range(len(r_positions_list)):
                                r_num = r_positions_list[num]
                                c_num = c_positions_list[num]
                                self.board[r_num][c_num] = self.turn
                    return True
                
            elif self.board[row + 1 + units][col - 1 - units] == self.opposite_turn(self.turn):
                move += 1
                r_positions_list.append(row + 1 + units)
                c_positions_list.append(col - 1 - units)


###################################
# End of Validity Testing Methods #
###################################


#raises errors for invalid inputs
def validate_input(parameter: str, number: 'imput') -> bool:

    if parameter == 'rows' or parameter == 'cols':
        if (number % 2) != 0 or number < 4 or number > 16:
            raise InvalidInputError
    elif parameter == 'win':
        if number != '<' and number != '>':
            raise InvalidInputError
    elif parameter == 'turn' or parameter == 'topleft':
        if number != 'B' and number != 'W':
            raise InvalidInputError
    return True
      
    
