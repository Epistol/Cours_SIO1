from random import randint

print ("******************************************************************************")
print ("*                               JEUX DU + OU -                               *")
print ("*   Pénalité de 5 coups si vous proposez un nombre qui a déjà été proposé    *")
print ("******************************************************************************")

alea = int(randint(0,100))
liste = []
nombre = int(101)
coups = 0

while alea != nombre:
    nombre = int(input("votre nombre : "))
    if nombre in liste:
        coups += 5
    else:
        coups +=1
        liste.append(nombre)

    if nombre > alea :
        print ("************")
        print ("*Trop grand*")
        print ("************")
    elif nombre < alea :
        print ("************")
        print ("*Trop petit*")
        print ("************")
    
    print("nombre de coups : ", coups)

print ()
print ("**************************************")
print ("*Vous avez trouvé en ", coups, "coups*")
print ("**************************************")
