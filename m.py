from tkinter import * 

fenetre = Tk()
for ligne in range(5):
    for colonne in range(5):
        Button(fenetre, text='L%s-C%s' % (ligne, colonne), borderwidth=1, height = 10, width=10).grid(row=ligne, column=colonne)
