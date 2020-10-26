letters = "abcdefghijklmnopqrstuvwxyz "

print(letters[5], letters[20], letters[2], letters[10])

invLetters = {}

numLetters = len(letters)

for i in range(numLetters):
    invLetters[letters[i]] = i


def encrypt(plain, shift):
    global letters, invLetters, numLetters
    cipher = ""
    for i in range(len(plain)):
        index = (invLetters[plain[i]]+shift) % numLetters
        cipher = cipher + letters[index]
    return cipher


def decrypt(cipher, shift):
    global letters, invLetters, numLetters
    plain = ""
    for i in range(len(cipher)):
        index = (invLetters[cipher[i]]-shift) % numLetters
        plain = plain + letters[index]
    return plain


plain = input("Enter plain text: ")
shift = input("Shift: ")

shift = int(shift)

cipher = encrypt(plain, shift)
plain = decrypt(cipher, shift)
print("Cipher: " + cipher)
print("Plain: " + plain + '\n')
