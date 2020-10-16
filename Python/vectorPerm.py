import string
letters = string.ascii_letters + " "


def permVector(password):
    cols = len(password)

    perm = [cols]*cols
    inpw = []
    for i in range(cols):
        n = letters.index(password[i]) % cols
        if n not in inpw:
            inpw.append(n)
            perm[i] = n

    spare = []
    for i in range(cols):
        if i not in inpw:
            spare.append(i)

    spareIndex = 0
    for i in range(cols):
        if perm[i] == cols:
            perm[i] = spare[spareIndex]
            spareIndex += 1

    return perm


def encrypt(plain, password):
    perm = permVector(password)
    partLength = len(perm)
    cipher = ""
    parts = len(plain) // partLength
    if len(plain) > (parts * partLength):
        parts += 1

    plainIndex = 0
    for i in range(parts):
        partCipher = [" "]*partLength
        for j in range(partLength):
            partCipher[perm[j]] = plain[plainIndex]
            plainIndex += 1
            if plainIndex == len(plain):
                break
        cipher = cipher + "".join(partCipher)

    return cipher


def decrypt(cipher, password):
    perm = permVector(password)

    partLength = len(perm)
    invPerm = [0]*partLength
    for i in range(partLength):
        invPerm[perm[i]] = i

    plain = ''
    parts = len(cipher) // partLength
    if len(cipher) > (parts * partLength):
        parts += 1

    cipherIndex = 0
    for i in range(parts):
        partplain = [' ']*partLength
        for j in range(partLength):
            partplain[invPerm[j]] = cipher[cipherIndex]
            cipherIndex += 1
            if cipherIndex == len(cipher):
                break
        plain += "".join(partplain)

    return plain


plain = input("Plain text: ")
password = input("Password: ")
print(permVector(password))

cipher = encrypt(plain, password)
print("\nCipher: ", cipher)
plains = decrypt(cipher, password)
print("Plain: ", plains)
