#Project #5: The Width of a Circle (Part 2)
#Derek Yang
#63118832
#Othello GUI Module

import othellogamegui
import tkinter

DEFAULT_FONT = ('Nasalization', 14)


class Othello:
    def __init__(self):
        self.root_window = tkinter.Tk()
        self.canvas = None
            
        game_label = tkinter.Label(
            master = self.root_window, text = 'Othello (Full Version)',
            font = DEFAULT_FONT)

        game_label.grid(
            row = 0, column = 0, padx = 10, pady = 10,
            sticky = tkinter.N, columnspan = 2)

        self.start_button = tkinter.Button(
            master = self.root_window, text = 'New Game', font = DEFAULT_FONT,
            command = self.on_start)

        self.start_button.grid(
            row = 2, column = 0, padx = 10, pady = 10,
            sticky = tkinter.N and tkinter.W and tkinter.S)

        self.quit_button = tkinter.Button(
            master = self.root_window, text = 'Exit', font = DEFAULT_FONT,
            command = self.on_exit)

        self.quit_button.grid(
            row = 2, column = 1, padx = 10, pady = 10, columnspan = 5,
            sticky = tkinter.N and tkinter.W and tkinter.S)

        self.start_text = tkinter.StringVar()
        self.start_text.set('Click to Start Game')

        self.start_label = tkinter.Label(
            master = self.root_window, textvariable = self.start_text,
            font = DEFAULT_FONT)

        self.start_label.grid(
            row = 1, column = 0, padx = 10, pady = 10,
            sticky = tkinter.S + tkinter.N, columnspan = 2)
    
        for i in range(2):    
            self.root_window.rowconfigure(i, weight = 1)
        
        for j in range(2):
            self.root_window.columnconfigure(j, weight = 1)


    def start(self) -> None:
        self.root_window.mainloop()


    def on_start(self) -> None:

        setup = SetUp()
        setup.show()

        if setup.clicked_ok():

            rows = setup.get_rows()
            cols = setup.get_cols()
            turn = setup.get_first()
            topleft = setup.get_top_left()
            win = setup.get_more_or_less()

            othello = othellogamegui.gamestate()
            othello.new_game(rows, cols, turn, topleft, win)

            self.canvas = tkinter.Canvas(
                master = self.root_window, width = 500, height = 500, background = 'Green',
                highlightbackground = "Black")
            
            self.canvas.grid(
                row = 3, column = 0, padx = 5, pady = 5, columnspan = 2,
            sticky = tkinter.N + tkinter.S + tkinter.E + tkinter.W)

            self.start_button.destroy()

            self.start_text.set('Turn: Black')

            self.root_window.rowconfigure(0, weight = 0)
            self.root_window.rowconfigure(1, weight = 0)

            self.quit_button.grid(
            row = 1, column = 1, padx = 10, pady = 10,
            sticky = tkinter.N and tkinter.E and tkinter.S)

            self.start_label.grid(
            row = 1, column = 0, padx = 10, pady = 10,
            sticky = tkinter.S + tkinter.N + tkinter.W, columnspan = 2)

            
            for rows in range(setup.rows):
                self.canvas.create_line(0,((500//setup.rows)*rows), 499, ((500//setup.rows)*rows),
                                   fill = "black", width = 1, )
                
            for cols in range(setup.cols):
                self.canvas.create_line(((500//setup.rows)*cols), 0, ((500//setup.rows)*cols), 499,
                                   fill = "black", width = 1, )
            

    def on_exit(self) -> None:

        self.root_window.destroy()
        raise SystemExit
    

###########################################
########## Start of SetUp Class ###########
###########################################


class SetUp:
    def __init__(self):

        self.setup_window = tkinter.Toplevel()

        who_label = tkinter.Label(
            master = self.setup_window, text = 'Initializing Othello...',
            font = DEFAULT_FONT)

        who_label.grid(
            row = 0, column = 0, columnspan = 2, padx = 10, pady = 10,
            sticky = tkinter.W)

        row_label = tkinter.Label(
            master = self.setup_window, text = 'Input Rows',
            font = DEFAULT_FONT)

        row_label.grid(
            row = 1, column = 0, padx = 10, pady = 10,
            sticky = tkinter.W)

        self.row_entry = tkinter.Entry(
            master = self.setup_window, width = 5, font = DEFAULT_FONT)

        self.row_entry.grid(
            row = 1, column = 1, padx = 10, pady = 1,
            sticky = tkinter.W + tkinter.E)

        column_label = tkinter.Label(
            master = self.setup_window, text = 'Input Columns:',
            font = DEFAULT_FONT)

        column_label.grid(
            row = 2, column = 0, padx = 10, pady = 10,
            sticky = tkinter.W)

        self.column_entry = tkinter.Entry(
            master = self.setup_window, width = 5, font = DEFAULT_FONT)

        self.column_entry.grid(
            row = 2, column = 1, padx = 10, pady = 1,
            sticky = tkinter.W + tkinter.E)

        first_move_label = tkinter.Label(
            master = self.setup_window, text = 'Which Player Goes First:',
            font = DEFAULT_FONT)

        first_move_label.grid(
            row = 3, column = 0, padx = 10, pady = 10,
            sticky = tkinter.W)

        self.first_move_entry = tkinter.Entry(
            master = self.setup_window, width = 5, font = DEFAULT_FONT)

        self.first_move_entry.grid(
            row = 3, column = 1, padx = 10, pady = 1,
            sticky = tkinter.W + tkinter.E)

        top_left_label = tkinter.Label(
            master = self.setup_window, text = 'Top Left Corner:',
            font = DEFAULT_FONT)

        top_left_label.grid(
            row = 4, column = 0, padx = 10, pady = 10,
            sticky = tkinter.W)

        self.top_left_entry = tkinter.Entry(
            master = self.setup_window, width = 5, font = DEFAULT_FONT)

        self.top_left_entry.grid(
            row = 4, column = 1, padx = 10, pady = 1,
            sticky = tkinter.W + tkinter.E)

        more_less_label = tkinter.Label(
            master = self.setup_window, text = 'More or Less Wins:',
            font = DEFAULT_FONT)

        more_less_label.grid(
            row = 5, column = 0, padx = 10, pady = 10,
            sticky = tkinter.W)

        self.more_less_entry = tkinter.Entry(
            master = self.setup_window, width = 5, font = DEFAULT_FONT)

        self.more_less_entry.grid(
            row = 5, column = 1, padx = 10, pady = 1,
            sticky = tkinter.W + tkinter.E)

        button_frame = tkinter.Frame(master = self.setup_window)

        button_frame.grid(
            row = 6, column = 0, columnspan = 2, padx = 10, pady = 10,
            sticky = tkinter.E + tkinter.S)

        ok_button = tkinter.Button(
            master = button_frame, text = 'OK', font = DEFAULT_FONT,
            command = self.ok_button)

        ok_button.grid(row = 0, column = 0, padx = 10, pady = 10)

        cancel_button = tkinter.Button(
            master = button_frame, text = 'Cancel', font = DEFAULT_FONT,
            command = self.cancel_button)

        cancel_button.grid(row = 0, column = 1, padx = 10, pady = 10)

        for i in range(7):
            self.setup_window.rowconfigure(i, weight = 1)
        self.setup_window.columnconfigure(1, weight = 1)


        self.ok_clicked = False
        self.valid = False
        self.rows = ''
        self.cols = ''
        self.first = ''
        self.top_left = ''
        self.more_or_less = ''


    def show(self):
        self.setup_window.grab_set()
        self.setup_window.wait_window()

    def clicked_ok(self):
        return self.ok_clicked

    def get_rows(self):
        return self.rows

    def get_cols(self):
        return self.cols

    def get_first(self):
        return self.first

    def get_top_left(self):
        return self.top_left

    def get_more_or_less(self):
        return self.more_or_less

    def ok_button(self) -> None:
        self.ok_clicked = True
        
        self.rows = int(self.row_entry.get())
        self.cols = int(self.column_entry.get())
        self.first = self.first_move_entry.get().upper()
        self.top_left = self.top_left_entry.get().upper()
        self.more_or_less = self.more_less_entry.get()
        
        self.setup_window.destroy()


    def cancel_button(self) -> None:
        self.setup_window.destroy()

##    def validity_test(self, parameter : str) -> bool:
##
##        while self.valid != True:
##            if othellogamegui.validate_input('rows', self.row_entry.get())):
##                if othellogamegui.validate_input('cols', self.column_entry.get()):
##                    if othellogamegui.validate_input('turn', self.first_move_entry.get()):
##                        if othellogamegui.validate_input('topleft', self.top_left_entry.get()):
##                            if othellogamegui.validate_input('win', self.more_less_entry.get()):
##    


##################


if __name__ == '__main__':
    Othello().start()

