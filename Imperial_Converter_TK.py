from tkinter import *
import tkinter as tk

root = tk.Tk()

HT = 120
WD = 200
var = IntVar()
Decision = 1

In_Inches = 1
In_Feet = 1

def sel():
    Decision = var.get()
    if (Decision == 1):
        label.config(text = ("Separate Ft.In with Dot!"))
    elif (Decision == 2):
        label.config(text = ("Enter a Number!"))
    # print (str(Decision))

def calc():
    Decision = var.get()
    if (Decision == 1):
        # To_Inches
        In_Feet, In_Inches = map(int,str(entry.get()).split("."))
        In_Inches = ((In_Feet * 12) + In_Inches)
        label.config(text = str(In_Inches)  + '"')

    elif (Decision == 2):
        # To_Feet
        In_Inches = int(entry.get())
        In_Feet = int(((In_Inches - (In_Inches % 12))/12))
        In_Inches = In_Inches % 12
        label.config(text = (str(In_Feet) + "'-" + str(In_Inches) + '"'))
    else:
        label.config(text = ("Choose Conversion!"))


canvas = tk.Canvas(root, height=HT, width=WD)
canvas.pack()

frame = tk.Frame(root, bg = '#ccc')
frame.place(relwidth=1, relheight=1)

label = tk.Label(frame, text="By: XYN")
label.place(relwidth=.9, relheight=.25, relx=.05, rely=.05)

entry = tk.Entry(frame)
entry.place(relwidth=.9, relheight=.25, relx=.05, rely=.35)
entry.bind("<Return>", (lambda event: calc()))

R1 = tk.Radiobutton(frame, text="To Inches", bg = '#ccc', variable=var, value=1, command=sel)
R1.place(relwidth=.35, relheight=.1, relx=.05, rely=.7)

R2 = tk.Radiobutton(frame, text="To Feet", bg = '#ccc', variable=var, value=2, command=sel)
R2.place(relwidth=.29, relheight=.1, relx=.05, rely=.85)

button = tk.Button(frame, text="Calc", command=calc)
button.place(relwidth=.4, relheight=.25, relx=.55, rely=.7)

root.mainloop()
