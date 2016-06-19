class Etudiant:
    def __init__(self, nom, prenom):
        self._nom = nom
        self._prenom = prenom
        self._tel = ""

    def ajouterTel(self, tel):
        self._tel.append(tel)
        
        

    
    def nom(self):
        return self._nom

    def prenom(self):
        return self._prenom

    def tel(self):
        return self._listeTel

    def __str__(self):
        tel = ""
        for tel in self._tel:
            tel = tel+ " "
        return


    
