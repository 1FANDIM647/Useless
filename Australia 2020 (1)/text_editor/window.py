import tkinter
from tkinter import *
from tkinter.filedialog import asksaveasfile, askopenfile
from tkinter.messagebox import showerror
from tkinter import messagebox
from tkinter import *
import webbrowser
import tkinter as tk


root = tkinter.Tk()
root.title(" Window")
root.iconbitmap(r'C:/Users/USER/Desktop/Australia 2020 (1)/text_editor/awas.ico')

#minimum height and width in program
root.minsize(width=1000, height=1000)
root.maxsize(width=1000, height= 1000)

text = tkinter.Text(root, width=400, height=400, wrap="word")
#scroll bar _from tikinter 
scrollb = Scrollbar(root, orient=VERTICAL, command=text.yview)
scrollb.pack(side="right", fill="y")
text.configure(yscrollcommand=scrollb.set)

root.mainloop()