# Eric Huynh 74814654 & Derek Yang 63118832 ICS 32 Lab Sec. 5. Project 1

from pathlib import Path
import shutil

#Main function of file manager
#-------------------------------START-OF-MAIN------------------------------------------

def MAIN():
    while True:                                                     #Asks for directory path
        poss_path= Path(input(''))
        if poss_path.exists():
            break
        else:
            print ('ERROR')
    while True:                                                     #Ask for second line of command 
        desired_search = input('')
        if desired_search.startswith('N '):                         #search for name of files
            file_results = sb_name2(poss_path, desired_search[2:])
            if file_results != []:
                break
            else:
                print("ERROR")
        elif desired_search.startswith('E '):                       #search for extention of files 
            if desired_search[2] != '.':
                file_results = sb_extension2(poss_path,'.' + desired_search[2:])
            else:
                 file_results = sb_extension2(poss_path, desired_search[2:])
            if file_results != []:
                break
            else:
                print("ERROR")
        elif desired_search.startswith('S '):                       #search for size of files  
            try:
                int_search = int(desired_search[2:])
                file_results = sb_size2(poss_path, int_search)
                if file_results != []:
                    break
            except:
                print ('ERROR')
        else:
            print ('ERROR')                     #Ask for third line of command
    while True:
        action_command = input('')
        if action_command  == 'P':              # print the file's path to console
            print_fp(file_results)
            break
        elif action_command == 'F':             # opens the file if the file is a .txt and reads the first line
            open_fp(file_results)               # prints the first lineto console
            break
        elif action_command == 'D':             # make a duplicate file into the same directory; copy should
            copy_fp(file_results)               # have .dup appended to the filename
            break
        elif action_command == 'T':
            modify_fp(file_results)             # touch the file
            break
        else:
            print ('ERROR')

#---------------------------END-OF-MAIN-----------------------------------------------



#-------------------------------START-OF-FUNCTION------------------------------------------            
#function to recursively search through folders for specificly named files          
def sb_name2(directory, search):
    '''Searches the prompted path for files with inputted name'''
    list_of_files = []
    for element in directory.iterdir():
        if element.is_dir():
            for file in sb_name2(element, search):        
                list_of_files.append(file)
        else:
            if search == element.name:
                list_of_files.append(str(element))
    return list_of_files

#---------------------------END-OF-FUNCTION-----------------------------------------------



#-------------------------------START-OF-FUNCTION------------------------------------------
#Function to recursively search through folders for specific file extentions of files
def sb_extension2(directory,search):
    '''Searches the prompted path for files with inputted extension'''
    list_of_files = []
    for element in directory.iterdir():
        if element.is_dir():
            for file in sb_extension2(element, search):
                list_of_files.append(file)
        else:
            if search == element.suffix:
                list_of_files.append(str(element))
    return list_of_files

#---------------------------END-OF-FUNCTION-----------------------------------------------



#-------------------------------START-OF-FUNCTION------------------------------------------
#Function to recursively search through folders for files of at least a specific size
def sb_size2(directory, search):
    '''Searches the prompted ptah for files with >= search'''
    list_of_files = []
    for element in directory.iterdir():
        if element.is_dir():
            for file in sb_size2(element, search):
                list_of_files.append(file)
        else:
            if search <= element.stat().st_size:
                list_of_files.append(str(element))
    return list_of_files

#---------------------------END-OF-FUNCTION-----------------------------------------------



#-------------------------------START-OF-FUNCTION------------------------------------------
#function to print files path to console
def print_fp(list_of_files):
    for file in list_of_files:
        print (file)
    return

#---------------------------END-OF-FUNCTION-----------------------------------------------



#-------------------------------START-OF-FUNCTION------------------------------------------
#Function to open and print first line of each file
def open_fp(list_of_files):

    for file in list_of_files:
        print (file)
        is_open = open(file, 'r')
        print (is_open.readline())
        is_open.close()
    return

#---------------------------END-OF-FUNCTION-----------------------------------------------



#-------------------------------START-OF-FUNCTION------------------------------------------
#Function to copy files with an extra extention of .dup
def copy_fp(list_of_files):
    for file in list_of_files:
        print (shutil.copyfile(file, file + '.dup'))
    return

#---------------------------END-OF-FUNCTION-----------------------------------------------



#-------------------------------START-OF-FUNCTION------------------------------------------
#Function to touch the file
def modify_fp(list_of_files):
    for file in list_of_files:
        Path(file).touch()
    return

#---------------------------END-OF-FUNCTION-----------------------------------------------


if __name__ == '__main__':
    MAIN ()
        
