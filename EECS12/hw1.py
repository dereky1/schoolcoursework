
#hw1.py
#Future Value Program
#Derek Yang 63118832

def main():
    print ("This program calculates the future value")
    y = eval(input("Enter the number of years:"))
    principal = sprincipal = eval(input("Enter the initial principal: ")) 
    apr = eval(input("Enter the annual interest rate: "))   
    print ("Investment values under simple interest and compound interest:")
    print ("\t")
    print (0, "      ", principal, "        ", principal)
    for i in range(y):
        srincipal = sprincipal + (sprincipal * apr * (i+1))
        principal = principal * (1 + apr) 
        print (i + 1, "      ", srincipal, "      ", principal)
main()

