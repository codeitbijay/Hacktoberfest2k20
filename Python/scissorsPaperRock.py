from random import randint

## player input
player = input("Please choose \nscissors(s) , paper(p) or rock(r):\n")

if player=="s":
    pf="Scissors >8"
elif player=="p":
    pf="Paper _"
else:
    pf="Rock O"


## computer input
comp = randint(1,3)

if comp==1:
    cf = "Scissors >8"
    comp="s"
elif comp==2:
    cf = "Paper _"
    comp="p"
else:
    cf = "Rock O"
    comp="r"


## display stats
print("You choose ", pf)
print("vs")
print("Computer choose ", cf)


## deciding winner
if player==comp:
    print("It's a draw")
elif (player=="s" and comp=="p") or (player=="p" and comp=="r") or (player=="r" and comp=="s"):
    print("You win")
else:
    print("Computer wins")


