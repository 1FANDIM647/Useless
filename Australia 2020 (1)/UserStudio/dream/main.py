import tkinter
from tkinter import *
from tkinter.filedialog import asksaveasfile, askopenfile
from tkinter.messagebox import showerror
from tkinter import messagebox
from tkinter import *
import webbrowser
import tkinter as tk
import fileinput
from tkinter import messagebox
from tkinter.filedialog import *
from tkinter.messagebox import *

canvas_width = 1000
canvas_height = 700
brush_size = 7
color ="black"




def paint(event):
    global brush_size
    global color
    x1 = event.x - brush_size
    x2 = event.x - brush_size
    y1 = event.y - brush_size
    y2 = event.y - brush_size
    w.create_oval(x1 ,y1 ,x2,y2, fill= color , outline = color)

def brish_size_change(new_size):
    global brush_size
    brush_size = new_size

def color_change (new_color):
    global color
    color = new_color


root = Tk()
root.title("Dream")

w = Canvas( root , 
            width=canvas_width,
            height=canvas_height,
            bg="white")
w.bind("<B1 -Motion>", paint)


#Colors



w.grid(row =1 , column = 0 , columnspan = 1 , padx = 1, pady =1, sticky=E+W+S+N)

w.columnconfigure(6 ,weight=1)
w.rowconfigure(2,weight = 1)


red_btn = Button(text = "red",width = 5 , command=lambda:color_change("red"))
blue_btn = Button(text = "blue" , width =5, command=lambda:color_change("blue"))
yellow_btn = Button(text = "yellow" , width =5, command=lambda: color_change("yellow"))
green_btn = Button(text= "green" , width=5,command= lambda:color_change("green"))
black_btn = Button(text= "black" , width=5 ,command= lambda:color_change("black"))
eraser = Button (text= "eraser" , width=5 , command=lambda:color_change("white"))

clear_all =Button(text= "clear all" , width=8, command=lambda:w.delete("all"))

change_size_5 = Button(text = "change size", width= 8, command=lambda: brish_size_change(5))

#create  color buttons  
red_btn.grid(row=0,column=1)
blue_btn.grid(row = 0 , column=2)
yellow_btn.grid(row = 0,column=3)
green_btn.grid(row = 0,column =4)
black_btn.grid(row = 0,column =5)
eraser.grid(row =0 ,column =6)
clear_all.grid(row =0,column =7 , sticky=W)
change_size_5.grid(row = 0,column =9)
root.mainloop()