from random import randint


liste =[]
for i in range(3):
    alea = randint(0,10)
    liste.append(alea)

alea = randint(0, 10)
print(liste)
print("nombre: ", alea)

if alea in liste:
    print("true")
else:
    print("False")

