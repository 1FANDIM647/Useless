from tkinter import *
from PIL import ImageTk,Image
import random


root = Tk()
root.title('С Новым Годом!')
cw = 1280
ch = 720
c = Canvas(root, width=cw, height=ch, bg="#002137")
c.pack()

#следующие две строчки можно пропустить, если вам лень качать и подгонять картинку с ёлкой
image = ImageTk.PhotoImage(file = "elka.png")
c.create_image(100, 100, image=image, anchor = NW)
    
def createText():
    a = ("""
Пусть этот праздник принесет
Всё то, что в жизни много значит!
Желаю в светлый Новый год
Добра, здоровья и удачи!

Пускай веселый смех звучит,
А сердце — счастье заполняет,
Ведь дед Мороз осуществит
Всё, что душа твоя желает!
""", """
Желаю в новом вам году
Поймать удачу на ходу.
Всех удивлять, все успевать,
Смеяться и не унывать.

Любить, надеяться и верить
И счастье на себя примерить,
И никогда вам не тужить,
И просто интересно жить!
""", """
С Новым годом поздравляю
И от всей души желаю
Море счастья, море смеха
И во всех делах успеха.

Всех желаний исполненья
И во всём только везенья,
Крепкого здоровья впрок
И волшебных дней клубок.
""")
    c.create_text(cw*2/3, ch/2, text = random.choice(a), fill='white', font="Times 24 bold")
 
def createSnow(s, n):
    for i in range(250):
        x = random.randint(1, cw)
        y = random.randint(-ch*n - 8, ch*(1-n))
        w = random.randint(3, 8)
        c.create_oval(x, y, x+w, y+w, fill='white', tag=s)
 
def motion():
    global indicator_count
    c.move("group1", 0, 1)
    c.move("group2", 0, 1)
    c.move(indicator, 0, 1)
    if c.coords(indicator)[1] < ch+1:
        root.after(20, motion)
    else:
        c.move(indicator, 0, -ch-5)
        root.after(20, motion)
        if indicator_count == 0:
            c.delete("group1")
            createSnow("group1", 1)
            indicator_count = 1
        else:
            c.delete("group2")
            createSnow("group2", 1)
            indicator_count = 0

def main():
    global indicator, indicator_count
        
    indicator = c.create_oval(23, -5, 28, 0, fill='white')
    indicator_count = 0

    createText()
    createSnow("group1", 0)
    createSnow("group2", 1)

    motion()
 
main()

root.mainloop()