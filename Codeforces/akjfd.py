def dec_to_base(num, base):  
   
    # Maximum base - 36 
    base_num = "" 
    while num > 0: 
        dig = int(num % base) 
        if dig < 10: 
            base_num += str(dig) 
        else: 
            # Using uppercase letters 
            base_num += chr(ord('A') 
                            + dig - 10 )   
        num //= base 
    # To reverse the string 
    base_num = base_num[::-1]  
    return int(base_num) 

x = input()
m = input()
y = input()
n = input()
o = input()

a = int(x, m)
b = int(y, n)

print(dec_to_base(a*b, o))