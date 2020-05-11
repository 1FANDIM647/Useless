from tkinter import *

#class for create window
class Window:
	def __init__(self,width,height,title="Application title",resizable=(False,False)):
		self.root = Tk()
		self.root.title(title)
		self.root.geometry(f"{width}x{height}+200+200")
		self.root.resizable(resizable[0],resizable[1])

		if icon:
			self.root.iconbitmap(icon)
	def run(self):
		self.root.mainloop()
			
         
window = Tk()
window.title("Application title")#the create title for our the app.
window.geometry("400x200")#window size of the app.
window.resizable(False, False)#we can change size of window by X and Y.
window.iconbitmap("c:/Users/USER/Desktop/workstation/Australia 2020 (1)/GUI/icon.ico")#icon of the app



window.mainloop()