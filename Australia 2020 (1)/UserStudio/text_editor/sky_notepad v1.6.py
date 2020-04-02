import tkinter
from tkinter import *
from tkinter.filedialog import asksaveasfile, askopenfile
from tkinter.messagebox import showerror
from tkinter import messagebox
from tkinter import *
import webbrowser
import tkinter as tk



FILE_NAME = tkinter.NONE







def new_file():
	global FILE_NAME
	FILE_NAME = "Untitled"
	text.delete('1.0', tkinter.END)

def save_file():
	data = text.get('1.0', tkinter.END)
	out = open(FILE_NAME, 'w')
	out.write(data)
	out.close()

def save_as():
	out = asksaveasfile(mode='w', defaultextension='txt')
	data = text.get('1.0', tkinter.END)
	try:
		out.write(data.rstrip())
	except Exception:
		showerror(title="Error", message="Saving file error")
#we save programms which was written in C		
def save_as_C_programm():
    	
	out = asksaveasfile(mode='w', defaultextension='c')
	data = text.get('1.0', tkinter.END)
	try:
		out.write(data.rstrip())
	except Exception:
		showerror(title="Error", message="Saving file error")
#we save programms which was written in Python 		


def open_file():
    	
	global FILE_NAME
	inp = askopenfile(mode="r")
	if inp is None:
		return
	FILE_NAME = inp.name
	data = inp.read()
	text.delete('1.0', tkinter.END)
	text.insert('1.0', data)
#fonts of texts 
def fonts():
    root=tk.Tk()
    var1=tk.IntVar()
    var2=tk.IntVar()
    check1=tk.Checkbutton(root,text=u'Русский times 10', font="times 10", anchor=tk.W, variable=var1,onvalue=1,offvalue=0)
    check2=tk.Checkbutton(root,text=u'Русский times 13', font="times 13", anchor=tk.W, variable=var2,onvalue=1,offvalue=0)
    check3=tk.Checkbutton(root,text=u'Русский clearlyu 13', font="clearlyu 13", anchor=tk.W, variable=var2,onvalue=1,offvalue=0)
    check4=tk.Checkbutton(root,text=u'Русский clearlyu 15', font="clearlyu 15", anchor=tk.W, variable=var2,onvalue=1,offvalue=0)
    check5=tk.Checkbutton(root,text=u'Русский terminal 13', font="terminal 13", anchor=tk.W, variable=var2,onvalue=1,offvalue=0)
    check6=tk.Checkbutton(root,text=u'Русский terminal 15', font="terminal 15", anchor=tk.W, variable=var2,onvalue=1,offvalue=0)
  
    check1.pack(fill=tk.X, expand=True)
    check2.pack(fill=tk.X, expand=True)
    check3.pack(fill=tk.X, expand=True)
    check4.pack(fill=tk.X, expand=True)
    check5.pack(fill=tk.X, expand=True)
    check6.pack(fill=tk.X, expand=True)


    	
    	
   
 
    	
    	
   

    	

def info():
	messagebox.showinfo("Information", "Sky_Notepad v1.6 By Shishov Michael")
#function open webbrowser	
def callback():
    webbrowser.open_new(r"http://www.google.com")

root = Tk()
root.iconbitmap(r'C:/Users/USER/Desktop/Australia 2020 (1)/text_editor/awas.ico')
link = Label(root, text="Google Hyperlink", fg="blue", cursor="hand2")
link.pack()
link.bind("<Button-1>", callback)

#sourceFile = open('python.txt', 'w')
#print("Круто же, правда?", file = sourceFile)
#sourceFile.close()



    
root = tkinter.Tk()
root.title(" Sky_Notepad v1.6")
root.iconbitmap(r'C:/Users/USER/Desktop/Australia 2020 (1)/text_editor/awas.ico')

#minimum height and width in program
root.minsize(width=1000, height=1000)
root.maxsize(width=1000, height= 1000)

text = tkinter.Text(root, width=400, height=400, wrap="word")
#scroll bar _from tikinter 
scrollb = Scrollbar(root, orient=VERTICAL, command=text.yview)
scrollb.pack(side="right", fill="y")
text.configure(yscrollcommand=scrollb.set)

 
text.pack()
menuBar = tkinter.Menu(root)
fileMenu = tkinter.Menu(menuBar)
fileMenu.add_command(label="New", command=new_file)
fileMenu.add_command(label="Open", command=open_file)
fileMenu.add_command(label="Save", command=save_file)
fileMenu.add_command(label="Save as file in txt", command=save_as)

fileMenu.add_command(label= "Save Program in C" ,command=save_as_C_programm)

fileMenu.add_command(label= "Google" , command=callback)
text.pack()



menuBar.add_cascade(label="File", menu=fileMenu)
menuBar.add_cascade(label="Info", command=info)
menuBar.add_cascade(label="Exit", command=root.quit)
menuBar.add_cascade(label="FUCK IT", command=root.quit)
menuBar.add_cascade(label="Google" ,command=callback)
menuBar.add_cascade(label="Fonts",command =fonts  )

root.config(menu=menuBar)
root.mainloop()