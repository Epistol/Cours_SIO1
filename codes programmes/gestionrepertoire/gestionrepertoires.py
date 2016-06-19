import csv
import os
import shutil

class Site(object):
    def __init__(self,codeSite,adresse,codePostal,ville,pays,codePays):
        self.codeSite = codeSite
        self.adresseComplete = adresse+" "+codePostal+" "+ville+", "+pays
        self.codePays = codePays

class Utilisateur(object):
    def __init__(self,idUtilisateur,prenom,nom,mail,genre,fonction,dateEmbauche,siteUtilisateur):
        self.idUtilisateur = idUtilisateur
        self.prenom = prenom
        self.nom = nom
        self.mail = mail
        self.genre = genre
        self.fonction = fonction
        self.dateEmbauche = dateEmbauche
        self.siteUtilisateur = siteUtilisateur

    def genererLogin(self):
        return (self.prenom[0]+self.nom+self.dateEmbauche.replace("/","")).lower()

    def genererUserHome(self):
        return "TP03SI6/User/"+self.siteUtilisateur.codePays+"/"+self.siteUtilisateur.codeSite+"/"+self.genererLogin()+"/"

    def genererPageIndex(self):
        return "<!DOCTYPE html>\n<html>\n\t<head>\n\t\t<meta charset=utf-8 />\n\t\t<title>Page perso"+self.prenom+self.nom+"</title>\n\t</head>\n\t<body>\n\t\t<h1>Espace personnel de "+self.prenom+" "+self.nom+"</h1>\n\t\t<h2>Embauche chez EuroMedic depuis : "+self.dateEmbauche+" en tant que "+self.fonction+"</h2>\n\t\t<h3>Sur le site : "+self.siteUtilisateur.codeSite+"</h3>\n\t\t<p>Pays : "+self.siteUtilisateur.codeSite+"</p>\n\t</body>\n</html>"

class Gestion(object):
    def chargerDicoSites(self,nomFichierCSV):
        fichierSites = csv.reader(open(nomFichierCSV, "r"))
        dicoCodeSiteSiteCorrespondant = {}
        i=0
        for ligne in fichierSites:
            if i>0:
                liste = ligne[0].split(";")
                dicoCodeSiteSiteCorrespondant[liste[0]] = Site(liste[0],liste[2],liste[3],liste[4],liste[5],liste[6])
            i+=1
        return dicoCodeSiteSiteCorrespondant

    def chargerDicoUtilisateurs(self,nomFichierCSV):
        fichierSites = csv.reader(open(nomFichierCSV, "r"))
        dicoIdentifiantUtilisateur = {}
        listeSites = []
        i=0
        for ligne in fichierSites:
            if i>0:
                liste = ligne[0].split(";")
                dicoIdentifiantUtilisateur[liste[0]] = Utilisateur(liste[0],liste[1],liste[2],liste[3],liste[4],liste[5],liste[6],self.dicoSite[liste[7]])
            i+=1
        return dicoIdentifiantUtilisateur
        
    def __init__(self, nomFichierSite, nomFichierUtilisateur):
        self.nomFichierSite = nomFichierSite
        self.nomFichierUtilisateur = nomFichierUtilisateur
        self.dicoSite = self.chargerDicoSites(nomFichierSite)
        self.dicoUtilisateur = self.chargerDicoUtilisateurs(nomFichierUtilisateur)

    def creerRepertoiresUtilisateurs(self):
        shutil.rmtree("TP03SI6")
        for utilisateur in self.dicoUtilisateur.values():
            try:
                os.makedirs(utilisateur.genererUserHome())
            except:
                pass
            indexUtilisateur = open(utilisateur.genererUserHome()+"index.html","w")
            indexUtilisateur.write(utilisateur.genererPageIndex())
            indexUtilisateur.close()

    def creerNavigation(self):
        indexUtilisateur = open("TP03SI6/User/index.html","w")
        indexUtilisateur.write("<meta charset=\"utf-8\" />")
        for utilisateur in self.dicoUtilisateur.values():
            indexUtilisateur.write("<a href=\""+utilisateur.siteUtilisateur.codePays+"/"+utilisateur.siteUtilisateur.codeSite+"/"+utilisateur.genererLogin()+"/index.html\">"+utilisateur.nom+" "+utilisateur.prenom+"</a><br/>")        
        indexUtilisateur.close()
        for utilisateur in self.dicoUtilisateur.values():
            if os.path.isfile("TP03SI6/User/"+utilisateur.siteUtilisateur.codePays+"/index.html"):
                indexUtilisateur = open("TP03SI6/User/"+utilisateur.siteUtilisateur.codePays+"/index.html","a")
            else:
                indexUtilisateur = open("TP03SI6/User/"+utilisateur.siteUtilisateur.codePays+"/index.html","w")
                indexUtilisateur.write("<meta charset=\"utf-8\" />")
            indexUtilisateur.write("<a href=\""+utilisateur.siteUtilisateur.codeSite+"/"+utilisateur.genererLogin()+"/index.html\">"+utilisateur.nom+" "+utilisateur.prenom+"</a><br/>")                        
            indexUtilisateur.close()
            
        for utilisateur in self.dicoUtilisateur.values():
            if os.path.isfile("TP03SI6/User/"+utilisateur.siteUtilisateur.codePays+"/"+utilisateur.siteUtilisateur.codeSite+"/index.html"):
                indexUtilisateur = open("TP03SI6/User/"+utilisateur.siteUtilisateur.codePays+"/"+utilisateur.siteUtilisateur.codeSite+"/index.html","a")
            else:
                indexUtilisateur = open("TP03SI6/User/"+utilisateur.siteUtilisateur.codePays+"/"+utilisateur.siteUtilisateur.codeSite+"/index.html","w")
                indexUtilisateur.write("<meta charset=\"utf-8\" />")
            indexUtilisateur.write("<a href=\""+utilisateur.genererLogin()+"/index.html\">"+utilisateur.nom+" "+utilisateur.prenom+"</a><br/>")                        
            indexUtilisateur.close()

siteUtil1 = Site("10","110 place premier mai","63000","Clermont-Ferrand","France","Fr")
util1 = Utilisateur("1","Michael","Lebeau","mikaleb@live.fr","Male","Informaticien","02/09/1996",siteUtil1)

testGestion = Gestion("TP03-lesSites-utf8.csv","TP03-lesUtilisateurs-utf8.csv")
testGestion.creerRepertoiresUtilisateurs()
testGestion.creerNavigation()
