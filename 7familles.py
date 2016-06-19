def creer7famille():
    c7famille = []
    for i in range(1,8):
        c7famille.apend("F"+str(i))
    return c7famille

def creer6membre():
    c6membre = []
    for i in range(1, 7):
        c6membre.apend("M"+str(i))
    return c6membre

def jeuComplet():
    jeuComplet = []
    famille = creer7famille()
    membre = creer6membre()
    for i in famille(1,8):
        for j in membre(1,7):
            jeuComplet.apend("F" + "M")
    return jeuComplet

def afficher(jeu):
    print("liste des cartes: ")
    for carte in jeu:
        print(carte)

def distribuer7carte(pioche):
    unjeudecarte = []
    for i in range(7):
        indicealea = randint(0, len(pioche)-1)
        carte = pioche[indicealea]
        unjeudecarte.append(carte)
    return unjeudecarte
    
def piocher():
    carte = None
    indicealea = randint(0, len(pioche)-1)
    indicealea = pioche(indicealea)
    pioche.remove(carte)
    return carte

def recuperer(dansjeu, carte):
    if carte in dansjeu:
        dansjeu.remove(carte)
        return carte
    else:
        return None
    
def extrairefamille(carte):
    return carte[0:2]

def carteAdemander(sonJeu):
    familleAdemander = extrairefamille(sonJeu[randint(0.len(sonJeu)-1])
    cartedemande = familleAdemander
    return 



def testerFamille(jeu):
    if 
    return c7famille

def deposerFamille(jeu, famille):
    for i in range(1,7):
        jeu.remove(famille+'M'+str(i))

def nbfamilledevoile(lesScores):

def UnJoueurAUnJeuVide(lesJeux):
    


if __name__ == '__main__':

    
    print(creer7famille(jeuComplet))
    


