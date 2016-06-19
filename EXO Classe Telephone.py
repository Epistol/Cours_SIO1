class Telephone(object):
    def __init__(self):
        self.numero
        self.type
    def __get_numero(self):
        self.numero = "Composer"
        return self.numero
    def __get_type(self):
        self.type = "Type de telephone"
        return self.type
    
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
        telephones =
        for tel in self._list_Telephone
            telephones += tel+ 
        return self._nom+ +self._prenom+  +telephones

class EtudiantBoursier(Etudiant):
    def __init__(self, nom,prenom, bourse)
        Etudiant.__init__(self,nom,prenom)
        self._bourse = bourse

    def getBourse(self):
        return self._bourse

    def __str__(self):
        telephones =
        for tel in self._list_Telephone
            telephones += nt+str(tel)
        return self._nom+ +self._prenom+  +self._bourse+ntelephone(s)  +telephones


eleve1 = EtudiantBoursier(Singe,Jesus,B1)
eleve1.ajouterTel(Telephone(0687654321,maison))
eleve1.ajouterTel(Telephone(0612345678,moi))
print (eleve1)
    
