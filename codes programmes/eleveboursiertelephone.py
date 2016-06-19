class Telephone(object):
    def __init__(self,numeroTel,typeTel):
        self._numeroTel = numeroTel
        self._typeTel = typeTel

    def getNumeroTel(self):
        return self._numeroTel

    def getTypeTel(self):
        return self._typeTel

    def __str__(self):
        return self._typeTel+" : "+self._numeroTel

###############################################################

class Etudiant(object):
    def __init__(self,nom,prenom,):
        self._nom = nom
        self._prenom = prenom
        self._list_Telephone = []

    def ajouterTel(self,telephone):
        self._list_Telephone.append(telephone)

    def getNom(self):
        return self._nom

    def getPrenom(self):
        return self._prenom

    def getList_telephone(self):
        return self._list_Telephone

    def __str__(self):
        telephones = ""
        for tel in self._list_Telephone:
            telephones += tel+" "
        return self._nom+" "+self._prenom+" : "+telephones

class EtudiantBoursier(Etudiant):
    def __init__(self, nom,prenom, bourse):
        Etudiant.__init__(self,nom,prenom)
        self._bourse = bourse

    def getBourse(self):
        return self._bourse

    def __str__(self):
        telephones = ""
        for tel in self._list_Telephone:
            telephones += "\n\t"+str(tel)
        return self._nom+" "+self._prenom+" : "+self._bourse+"\ntelephone(s) : "+telephones


eleve1 = EtudiantBoursier("Rieu","Alexandre","B1")
eleve1.ajouterTel(Telephone("0648101584","maison"))
eleve1.ajouterTel(Telephone("0658960313","moi"))
print (eleve1)

