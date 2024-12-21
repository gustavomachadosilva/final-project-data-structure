import string
import secrets
import random

fileName = "test.txt"
numberOfRows = 100
isOrdered = False
separator = ";"

file = open(fileName, "w")


def createRandonRangeOfNumbers(numberOfRows):

    randomRange = []

    for i in range(1, numberOfRows + 1):

        randomRange.append(i)

    random.shuffle(randomRange)
    
    return randomRange


if (isOrdered == True):

    for i in range(1, numberOfRows + 1):

        password = ""
        for _ in range(3):
            password += secrets.choice(string.ascii_lowercase)
            password += secrets.choice(string.ascii_uppercase)
            password += secrets.choice(string.digits)
        
        file.write(str(i) + separator + password + "\n")

else:

    randomRange = createRandonRangeOfNumbers(numberOfRows)

    for i in randomRange:

        password = ""
        for _ in range(3):
            password += secrets.choice(string.ascii_lowercase)
            password += secrets.choice(string.ascii_uppercase)
            password += secrets.choice(string.digits)
        
        file.write(str(i) + separator + password + "\n")


file.close()
