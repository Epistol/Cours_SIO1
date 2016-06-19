from random import randint

# cree les 7 familles
def creer7Familles():
    listeFamilles = []
    for i in range(1,8):
        listeFamilles.append("F"+str(i))
    return listeFamilles

# cree les 6 Membres
def creer6Membres():
    listemembres = []
    for i in range(1,7):
        listemembres.append("M"+str(i))
    return listemembres

# cree le jeux complet
def creerJeuComplet7Familles():
    listeJeuComplet = []
    for i in range(1,8):
        for j in range(1,7):
            listeJeuComplet.append("F"+str(i)+"M"+str(j))
    return listeJeuComplet

# affiche la liste des cartes d'un jeu
def afficher(jeu):
    for i in jeu:
        print (i,end= " ")
    return ""

# distribution des cartes aux joueurs
def distribuer7cartes(pioche):
    listeAlea = []
    for i in range(7):
        piocheAlea = randint(0,len(pioche)-1)
        listeAlea.append(pioche[piocheAlea])
        pioche.remove(pioche[piocheAlea])
    return listeAlea

# Ce que pioche un joueur
def piocher(pioche):
    piocheAlea = randint(0,len(pioche)-1)
    aPioche = pioche[piocheAlea]
    pioche.remove(pioche[piocheAlea])
    return aPioche

# Recupere dans le jeu d'un autre joueurs
def recuperer(dansLeJeu,laCarte):
    if laCarte in dansLeJeu:
        dansLeJeu.remove(laCarte)
        return laCarte
    else:
        return None

# donne seulement les 2 premiers caractere d'une carte pour avoir la famille
def extraireFamille(carte):
    return carte[0:2]

# teste si un jeu contient une famille complete
def testerFamille(jeu):
    dicoFamille = {"F1":0,
                   "F2":0,
                   "F3":0,
                   "F4":0,
                   "F5":0,
                   "F6":0,
                   "F7":0}
    for carte in jeu:
        famille = extraireFamille(carte)
        dicoFamille[famille] += 1
        if 6 in dicoFamille.values():
            return famille
    else:
        return None

# depose la famille sur la table
def deposerFamille(jeu,famille):
    for i in range(1,7):
        jeu.remove(famille+"M"+str(i))

# scores totale (nombre de familles devoilés)
def nbFamillesDevoiles(lesScores):
    return sum(lesScores)

# cible un joueur aleatoire sauf celui qui joue
def ciblerFournisseur(nbJoueurs,i_sauf):
    listeNumeroJoueurs = []
    for i in range(0,nbJoueurs):
        listeNumeroJoueurs.append(i)
    
    listeNumeroJoueurs.remove(i_sauf)
    alea = randint(0,len(listeNumeroJoueurs)-1)
    
    return int(listeNumeroJoueurs[alea])

# vérifie si un joueur à son jeu vide
def unJoueurAUnJeuVide(lesJeux):
    retour = True
    for unJeu in lesJeux:
        if len(unJeu) == 0:
            retour = False
    return retour


listeFamilles = creer7Familles() #liste des 7 familles
listemembres = creer6Membres() #liste des 6membres
listeJeuComplet = creerJeuComplet7Familles() #liste du jeu complet

pioche = listeJeuComplet

#nombre de joueurs
nbJoueurs = int(0)
while nbJoueurs < 2 or nbJoueurs > 6:
    nbJoueurs = int(input("nombre de joueurs de 2 à 6 : "))

# distribution à tous les joueurs   
lesJeux = []
for i in range(nbJoueurs):
    lesJeux.append(distribuer7cartes(pioche))

joueurQuiJoue = 0
scores = [0]*nbJoueurs

while (unJoueurAUnJeuVide(lesJeux)): #tant qu'un joueur n'a pas un jeu vide
    piocherCarte = ""

    if joueurQuiJoue > nbJoueurs-1: # verifie si le joueur qui est cencé jouer existe
        joueurQuiJoue = 0 # remet le joueur a 0 si il n'existe pas
        
##########################################################
#sortie de boucle si pioche vide ET nombre de joueurs a 2#
##########################################################
    if nbJoueurs == 2 and len(pioche) == 0:
        break

#############################
#FAIS LA DEMANDE A UN JOUEUR#
#############################
        
    demandeAJoueur = ciblerFournisseur(nbJoueurs,joueurQuiJoue) #choisi un joueur aleatoire a qui demander
    #recherche une famille aleatoire que le joueur a dans son jeu
    FamilleCarteRecherche = randint(0,len(lesJeux[joueurQuiJoue])-1)
    FamilleCarteRecherche = str(lesJeux[joueurQuiJoue][FamilleCarteRecherche])
    FamilleCarteRecherche = extraireFamille(FamilleCarteRecherche)
    #recherche la demande de la carte en fonction de la famille
    LaCarte = str(randint(1,6))
    LaCarte = FamilleCarteRecherche+"M"+LaCarte
    while LaCarte in lesJeux[joueurQuiJoue]: # tant que la carte est déjà dans le jeu du joueur
        LaCarte = str(randint(1,6)) # recherche de nouveau le membre de la famille
        LaCarte = FamilleCarteRecherche+"M"+LaCarte
        
    print ("Joueur",(joueurQuiJoue+1),"demande",LaCarte,"a Joueur",(demandeAJoueur+1))

#########################
#DONNE CARTE SI POSSIBLE#
#########################
    donnerCarte = recuperer(lesJeux[demandeAJoueur],LaCarte)
    if donnerCarte != None:
        lesJeux[joueurQuiJoue].append(LaCarte)
        print("Joueur",(demandeAJoueur+1),"donne",LaCarte,"a joueur",(joueurQuiJoue+1))
########################
#SINON PIOCHE UNE CARTE#
########################
    else:
        if len(pioche) > 0:
            piocherCarte = piocher(pioche)
            lesJeux[joueurQuiJoue].append(piocherCarte)
            print("Joueur",(joueurQuiJoue+1),"pioche",piocherCarte)
            print("Il reste", len(pioche),"cartes dans la pioche")
            if piocherCarte == LaCarte:
                print("Bonne Pioche!!!!!!!")
        else:
            print("Il reste", len(pioche),"cartes dans la pioche")
##############################################
#verifier si un joueur à une famille complete#
##############################################
    for i in range(nbJoueurs):
        JoueurAFamilleComplete = testerFamille(lesJeux[i])
        if JoueurAFamilleComplete != None:
            ##############################
            #depose la famille si complet#
            ##############################
            print ("joueur", joueurQuiJoue+1,"depose famille",JoueurAFamilleComplete) 
            deposerFamille(lesJeux[joueurQuiJoue],JoueurAFamilleComplete)
            scores[joueurQuiJoue] += 1
######################
#Affichage des scores#
######################
    print ("Scores :",scores)
    print ()
    joueurQuiJoue += 1
    if nbJoueurs <6:
        if piocherCarte == LaCarte: #verifie si le joueur avait eu une bonne pioche
            joueurQuiJoue-=1

############################
#Affichages apres fin de jeu#
############################   
print("-"*80)
print("-"*80)

for i in range(nbJoueurs):  #joueurs qui n'ont plus de cartes
    if len(lesJeux[i]) ==0:
        print("joueur",i+1,"n'a plus de carte !")
print()

for i in range(nbJoueurs): # jeux de chaque joueurs
    print("Jeu du joueur",i+1,":",end="")
    print(afficher(lesJeux[i]))
print()
print("Nombre de familles devoile :",nbFamillesDevoiles(scores)) #familles devoilées
jeuxAvecLePlusDeFamiles = []

for i in range(nbJoueurs): #joueur(s) gagnant(s)
    if scores[i] == max(scores):
        jeuxAvecLePlusDeFamiles.append("joueur "+str(i+1))
print("Joueur(s) gagnant(s) :", jeuxAvecLePlusDeFamiles,"avec",max(scores),"familles devoilées")

    
