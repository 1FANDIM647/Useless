import tkinter as tkinter
from tkinter import filedialog
from PIL import Image

root = tk.Tk()

canvas1 = tk.Canvas(root,width=400,height=250,bg='azure3',relief="raised")
canvas1.pack()

label1 = tk.Label(root , text="File Conversion Tool" ,bg='azure3')
label1.config(font=('helvetica',20))
canvas1.create_window(150,60,window=label1)


def getPNG():
	global im1

	import_file_path =filedialog.askopenfiledialog()
	im1 = Image.open(import_file_path)

	