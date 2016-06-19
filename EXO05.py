
chaine = input("saisisser les valeur: ")
str(chaine)
print (chaine.split(' ', 4) and chaine.split('  ', 1) and chaine.replace("  ", ";")and chaine.replace("  ", "\n"))

e = chaine

for e in enumerate(chaine):
    print ("nom:",e,"prénom:",e,"classe:",e)
