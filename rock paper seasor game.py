# rock paper scissors game in python

import random

def gameWin(comp,you):
    if (comp==you):
        return None
    elif comp=='r':
        if you=='s':
            return False
        elif you=='p':
            return True
    elif comp=='s':
        if you=='p':
            return False
        elif you=='r':
            return True
    elif comp=='p':
        if you=='s':
            return True
        elif you=='r':
            return False

print("computer turn : scissors(s),paper(p),rock(r) ?")
randNo=random.randint(1,2)
#print(randNo)  
#this line help to know which is chose the computer.

if randNo==1:
    comp='r'
elif randNo==2:
    comp='p'
elif randNo==3:
    comp='s'

you =input("your turn: scissors(s),paper(p),rock(r) ? ")
a=gameWin(comp,you)

print(f"comp chose {comp}")
print(f"you chose {you}")

if a==None:
    print("its a Tie!")
elif a:
    print("you win")
else:
    print("you losse")
