k=int(input("Enter a positive integer: "))
sen=input("Enter the text: ")

def il(w,k):
    p=((ord(w)-97)+k)%26
    return chr(p+97)

def iu(w,k):
    p=((ord(w)-65)+k)%26
    return chr(p+65)
ct=""
for c in sen:
    if (c.isupper()):
        ct+=iu(c,k)
    elif (c.islower()):
        ct+=il(c,k)
    else:
        ct+=c

print("Ciphered text is:", ct)
