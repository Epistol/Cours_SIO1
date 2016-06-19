
from random import randint

alea = int(randint(0,100))
liste = []
nombre = int(101)
coup = int(0)


            
while alea != nombre:
    int(input("Votre nombre: "))
    if alea < nombre:
        print("c'est moins")
        coup +=1
    elif alea > nombre:
        print ("c'est plus")
        coup +=1
    else:
        print("Gagner")
