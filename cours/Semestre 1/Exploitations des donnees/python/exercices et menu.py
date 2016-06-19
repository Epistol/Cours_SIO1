from math import sqrt

continuer = "oui"

while continuer == "oui":
    print ("*****************************************************")
    print ("*            *****************************          *")
    print ("*            *1 : Tranches d’âge         *          *")
    print ("*            *2 : Equation 2nd degré     *          *")
    print ("*            *3 : Table de multiplication*          *")
    print ("*            *4 : Suite de Syracuse      *          *")
    print ("*            *5 : Fonction puissance     *          *")
    print ("*            *6 : DESSINE-MOI un mouton! *          *")
    print ("*            *****************************          *")
    print ("*****************************************************")
    menu = input("numero exercice : ")
    # EXO 1 #
    if int(menu) == 1:
        age = int(input("Votre age en chiffre : "))
        if age < 2:
            print ("Vous faites parti des bébés")
        elif age < 12:
            print ("Vous faites parti des enfants")
        elif age < 18:
            print ("Vous faites parti des adolescents")
        elif age < 60:
            print ("Vous faites parti des adultes")
        else:
            print ("Vous faites parti des vieux")
            
    # EXO 2 #
    elif int(menu) == 2:
        a = int(input("saisir a : "))
        b = int(input("saisir b : "))
        c = int(input("saisir c : "))
        print ("fonction : ",a,"x² + ",b,"x+",c)
        delta = b**2 - 4*a*c
        print ("delta = ", delta)

        if delta == 0:
            print ("une solution : ", (0-b)/(2*a))
        elif delta >0:
            print ("deux solution : ", ((0-b)- sqrt(delta))/(2*a), "et", ((0-b)+ sqrt(delta))/(2*a))
        else:
            print ("pas de solution")
            
    # EXO 3 #
    elif int(menu) == 3:
        table = int(input("choix table : "))
        taille = int(input("jusqu'a : "))
        nombre = 0

        while nombre <= taille:
            print (table, "*", nombre,"=",table*nombre)
            nombre += 1
            
    # EXO 4 #
    elif int(menu) == 4:
        compteur = int(0)
        entier = int(input("choix entier : "))
        while entier != 1:
            if entier == 0:
                break
            compteur +=1
            if entier%2 == 0:
                entier = entier//2
            else:
                entier = entier*3+1
            entier = int(entier)
            print (entier)
        print()
        print("fait en : ", compteur, "calculs")

    # EXO 5 #
    elif int(menu) == 5:
        def puissance(a,n):
            resultat = a
            for i in range(int(n-1)):
                resultat *= a
            return resultat

        a = input("choix nombre : ")
        n = input("choix puissance : ")
        a = puissance(int(a),int(n))
        print (a)

    # EXO 6 #
    elif int(menu) == 6:
        
        def Deplacement(x,y):
            for i in range(y):
                print()
            for k in range(x):
                print(end="  ")
                
        def DessinerRectangle(largeur, longueur, typ, x):
            for i in range(largeur):
                print (end="* ")
            print()
            
            if typ == "plein":
                for i in range(int(longueur-1)):
                    for k in range(x):
                        print(end="  ")
                    for j in range(int(largeur)):
                        print (end="* ")
                    print ()
            else:
                for i in range(int(longueur-2)):
                    for k in range(x):
                        print(end="  ")
                    print(end="* ")
                    for j in range(int(largeur-2)):
                        print (end="  ")
                    print(end="* ")
                    print ()
                for k in range(x):
                     print(end="  ")
                for i in range(int(largeur)):
                    print (end="* ")
                    
        print ("DESSINONS UN MOUTON : ")
        print ("  ,-''''-.")
        print (" (.  ,.   L        ___...__")
        print (" /7} ,-`  `'-==''``        ''._")
        print ("//{                           '`.")
        print ("\_,X ,                         : )")
        print ("    7                          ;`")
        print ("    :                  ,       /")
        print ("     \_,                \     ;")
        print ("       Y   L_    __..--':`.    L")
        print ("       |  /| ````       ;  y  J")
        print ("       [ j J            / / L ;")
        print ("       | |Y \          /_J  | |")
        print ("       L_J/_)         /_)   L_J")
        print ("      /_)                  /_)")

        print ()
        print ("MAINTENANT : dessinons un rectangle")
        typ = input("plein ou vide : ")
        largeur = input("largeur : ")
        longueur = input("longueur : ")
        emplacementX = input("emplacement X : ")
        emplacementY = input("emplacement Y : ")
        
        Deplacement(int(emplacementX),int(emplacementY))
        DessinerRectangle(int(largeur),int(longueur),str(typ), int(emplacementX))
        
    continuer = input("autre exercice ? oui/non :")
    print()
