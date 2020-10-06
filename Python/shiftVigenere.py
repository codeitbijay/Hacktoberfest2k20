letters = "abcdefghijklmnopqrstuvwxyz "
invLetters = {}
numLetters = len(letters)

for i in range(numLetters):
    invLetters[letters[i]] = i


def encrypt(plain, password):
    global letters, invLetters, numLetters
    cipher = ""
    passwordIndex = 0
    for i in range(len(plain)):
        shift = invLetters[password[passwordIndex]]
        index = (invLetters[plain[i]]+shift) % numLetters
        cipher = cipher + letters[index]
        passwordIndex = (passwordIndex+1) % len(password)
    return cipher


def decrypt(cipher, password):
    global letters, invLetters, numLetters
    plain = ""
    passwordIndex = 0
    for i in range(len(cipher)):
        shift = invLetters[password[passwordIndex]]
        index = (invLetters[cipher[i]]-shift) % numLetters
        plain = plain + letters[index]
        passwordIndex = (passwordIndex+1) % len(password)
    return plain


plain = input("Plain text: ")
password = input("Password: ")
cipher = encrypt(plain, password)
plain = decrypt(cipher, password)

print("Cypher: " + cipher)
print("Plain: " + plain)
