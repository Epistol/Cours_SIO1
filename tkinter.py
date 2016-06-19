from tkinter import *

def clavier(event):
    label.config(text = entree.get("1.0","end"))
    touche = event.keysym
    print(touche)
    

fenetre1 = Tk()

label = Label(fenetre1, text="", bg="white")

value = StringVar() 
value.set("")
entree = Text(fenetre1, width=30)

entree.bind("<Return>", clavier)

label.pack()
entree.pack()

