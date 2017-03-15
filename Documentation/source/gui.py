# By Geetha, Ali, Yaseen, Majid and Mortaza
# import Tkinter as Tk # Python2
import tkinter as Tk # Python3
import subprocess


class Calculator:
    # Constructor for adding buttons
    def __init__(self, window):
        window.title('Calculator By Geetha, Ali, Yaseen, Majid and Mortaza')
        window.geometry()
        self.text_box = Tk.Entry(window, width=40, font="Noto 20 bold")
        self.text_box.grid(row=0, column=0, columnspan=6)
        self.text_box.focus_set()
        # Buttons
        Tk.Button(window,text="+",font="Noto 10 bold",width=14,height=6,command=lambda:self.action('+')).grid(row=4, column=3)
        Tk.Button(window,text="*",font="Noto 10 bold",width=14,height=6,command=lambda:self.action('*')).grid(row=2, column=3)
        Tk.Button(window,text="-",font="Noto 10 bold",width=14,height=6,command=lambda:self.action('-')).grid(row=3, column=3)
        Tk.Button(window,text="/",font="Noto 10 bold",width=14,height=6,command=lambda:self.action('/')).grid(row=1, column=3)
        Tk.Button(window,text="7",font="Noto 10 bold",width=14,height=6,command=lambda:self.action('7')).grid(row=1, column=0)
        Tk.Button(window,text="8",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(8)).grid(row=1, column=1)
        Tk.Button(window,text="9",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(9)).grid(row=1, column=2)
        Tk.Button(window,text="4",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(4)).grid(row=2, column=0)
        Tk.Button(window,text="5",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(5)).grid(row=2, column=1)
        Tk.Button(window,text="6",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(6)).grid(row=2, column=2)
        Tk.Button(window,text="1",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(1)).grid(row=3, column=0)
        Tk.Button(window,text="2",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(2)).grid(row=3, column=1)
        Tk.Button(window,text="3",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(3)).grid(row=3, column=2)
        Tk.Button(window,text="0",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(0)).grid(row=4, column=0)
        Tk.Button(window,text=".",font="Noto 10 bold",width=14,height=6,command=lambda:self.action('.')).grid(row=4, column=1)
        Tk.Button(window,text="(",font="Noto 10 bold",width=14,height=6,command=lambda:self.action('(')).grid(row=1, column=4)
        Tk.Button(window,text=")",font="Noto 10 bold",width=14,height=6,command=lambda:self.action(')')).grid(row=2, column=4)
        Tk.Button(window,text="=",font="Noto 10 bold",width=14,height=6,command=lambda:self.equals()).grid(row=4, column=2)
        Tk.Button(window,text="^",font="Noto 10 bold",width=14,height=6,command=lambda:self.action('^')).grid(row=3, column=4)
        Tk.Button(window,text='Clear',font="Noto 10 bold",width=14,height=6,command=lambda:self.clearall()).grid(row=4, column=4)
    
    def action(self, arg):
        """Attaching button's value to end of the text box"""
        self.text_box.insert(Tk.END, arg)

    def get(self):
        """Getting expression from c++ code"""
        self.expression = self.text_box.get()

    def equals(self):
        self.get()
        self.expression=self.expression.replace('(','\(') # Because of echo!
        self.expression=self.expression.replace(')','\)') # Because of echo!
        self.value= subprocess.check_output("echo {} | ./main.x".format(self.expression), shell=True)
        self.text_box.delete(0, Tk.END)
        self.text_box.insert(0, self.value)

    def clearall(self):
        """Clearing the text box"""
        self.text_box.delete(0, Tk.END)


window = Tk.Tk()
ob = Calculator(window)
window.mainloop()
