Player_1 = input("Enter 1st Player Name: ")
Player_2 = input("Enter 2nd Player Name: ")

def game(num1, num2, bit1, bit2):
    p1 = int(num1[bit1])%3
    p2 = int(num2[bit2])%3

    if(player_one[p1]==player_two[p2]):
        print("Draw")
    elif(player_one[p1] == 'Rock' and player_two[p2] == 'Paper'):
        print(f"{Player_2} wins!!")
    elif(player_one[p1] == 'Rock' and player_two[p2] == 'Scissor'):
        print(f"{Player_1} wins!!")
    elif(player_one[p1] == 'Paper' and player_two[p2] == 'Rock'):
        print(f"{Player_1} wins!!")
    elif(player_one[p1] == 'Paper' and player_two[p2] == 'Scissor'):
        print(f"{Player_2} wins!!")
    elif(player_one[p1] == 'Scissor' and player_two[p2] == 'Rock'):
        print(f"{Player_2} wins!!")
    elif(player_one[p1] == 'Scissor'and player_two[p2] == 'Paper'):
        print(f"{Player_1} wins!!")

player_one = {0:'Rock', 1:'Paper', 2:'Scissor'}
player_two = {0:'Scissor', 1:'Rock', 2:'Paper'}

while(1):
    num1 = input(f"{Player_1}, Enter your choice: ")
    num2 = input(f"{Player_2}, Enter your choice: ")
    bit1 = int(input(f"{Player_1}, Enter the secret bit position"))
    bit2 = int(input(f"{Player_2}, Enter the secret bit position"))
    game(num1, num2, bit1, bit2)
    ch = input("Do you want to continue? y/n")
    if(ch == 'n'):
        break