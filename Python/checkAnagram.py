def checkAnagram(str1, str2):
    len1 = len(str1)
    len2 = len(str2)

    if len1 != len2:
        return 0

    str1 = sorted(str1)
    str2 = sorted(str2)

    for i in range(0, len(str1)):
        if str1[i] != str2[i]:
            return 0

    return 1


str1 = input("Enter String 1: ")
str2 = input("Enter String 2: ")

if checkAnagram(str1, str2):
    print("Strings are ANAGRAM")
else:
    print("Strings are NOT ANAGRAM")