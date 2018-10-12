#===========================================================
# Creador por: William Aguirre Zapata
# Interfaz para el tablero de GAMERS FITNESS
#===========================================================

import tkinter
from tkinter import messagebox
import serial
import time
import random
import threading
import pygame
from pygame.locals import *

gui = tkinter.Tk()
gui.title("TABLERO WOLF")
gui.geometry("1280x710")

#Variables
puntaje=0;
tiempo=0;
textoPuntaje=tkinter.StringVar()
textoTiempo=tkinter.StringVar()


x=None
y=None
z=None
w=None
a=None
b=None
c=None
d=None
f=None
g=None
imagenAleatoria = None
numero=None

#----------------TECLAS ---------------
h = []
def keyup(e):
    global h
    if(e.keycode in h):
        h.pop(h.index(e.keycode))    

def keydown(e):
    global h
    if not e.keycode in h:
        h.append(e.keycode)

def puntajeL():
    global textoPuntaje,puntaje
    textoPuntaje.set(str(puntaje))
    canvas.after(10,puntajeL)

def tiempoL():
    global textoTiempo,tiempo
    textoTiempo.set(str(tiempo))
    canvas.after(10, tiempoL)

def aumentarPuntaje():
    global puntaje
    puntaje=puntaje+1
    time.sleep(0.1)

def reducirPuntaje():
    global puntaje
    puntaje=puntaje-1
    time.sleep(0.2)

def temporizador():
    global tiempo
    if(tiempo<91 and tiempo >0):
        tiempo -= 1
        # Take advantage of the after method of the Label
    canvas.after(1000, temporizador)
    
canvas = tkinter.Canvas(gui,width=1280,height=710)
#------------MONTAR IMAGENES--------
fondo1 = tkinter.PhotoImage(file="img/fondo.png")
uno = tkinter.PhotoImage(file="img/1.png")
dos = tkinter.PhotoImage(file="img/2.png")
tres = tkinter.PhotoImage(file="img/3.png")
cuatro = tkinter.PhotoImage(file="img/4.png")
cinco = tkinter.PhotoImage(file="img/5.png")
seis = tkinter.PhotoImage(file="img/6.png")
siete = tkinter.PhotoImage(file="img/7.png")
ocho = tkinter.PhotoImage(file="img/8.png")
nueve = tkinter.PhotoImage(file="img/9.png")
#------------LETREROS-----------------
puntajeLabel=tkinter.Label(canvas,textvariable=textoPuntaje,fg="white",bg="black",font=("arcade",100,"")).place(x=1055,y=440)
tiempoLabel=tkinter.Label(canvas,textvariable=textoTiempo,fg="white",bg="black",font=("arcade",100,"")).place(x=740,y=440)
puntajeL()
tiempoL()

canvas.create_image(1280/2,710/2,image=fondo1)

def aleatorio():
    global imagenAleatoria,numero
    imagenAleatoria = random.choice([uno,dos,tres,cuatro,cinco,seis,siete,ocho,nueve])
    numero = canvas.create_image(1280/2,710/2,image=imagenAleatoria)    

aleatorio()

def keyJuego():
    global h,x,y,z,w,a,b,c,d,f,numero,imagenAleatoria,puntaje,tiempo

    if(48 in h):
        tiempo=0
        puntaje=0
    if(32 in h):
        tiempo=90
        puntaje=0
    if(49 in h):
        if(imagenAleatoria == uno):
            canvas.delete(numero)
            aumentarPuntaje()
            imagenAleatoria=None
            aleatorio()
        else:
            reducirPuntaje()
            
    if(50 in h):
        if(imagenAleatoria == dos):
            canvas.delete(numero)
            aumentarPuntaje()
            imagenAleatoria=None
            aleatorio()
        else:
            reducirPuntaje()
            
    if(51 in h):
        if(imagenAleatoria == tres):
            canvas.delete(numero)
            aumentarPuntaje()
            imagenAleatoria=None
            aleatorio()
        else:
            reducirPuntaje()

    if(52 in h):
        if(imagenAleatoria == cuatro):
            canvas.delete(numero)
            aumentarPuntaje()
            imagenAleatoria=None
            aleatorio()
        else:
            reducirPuntaje()

    if(53 in h):
        if(imagenAleatoria == cinco):
            canvas.delete(numero)
            aumentarPuntaje()
            imagenAleatoria=None
            aleatorio()
        else:
            reducirPuntaje()

    if(54 in h):
        if(imagenAleatoria == seis):
            canvas.delete(numero)
            aumentarPuntaje()
            imagenAleatoria=None
            aleatorio()
        else:
            reducirPuntaje()

    if(55 in h):
        if(imagenAleatoria == siete):
            canvas.delete(numero)
            aumentarPuntaje()
            imagenAleatoria=None
            aleatorio()
        else:
            reducirPuntaje()

    if(56 in h):
        if(imagenAleatoria == ocho):
            canvas.delete(numero)
            aumentarPuntaje()
            imagenAleatoria=None
            aleatorio()
        else:
            reducirPuntaje()

    if(57 in h):
        if(imagenAleatoria == nueve):
            canvas.delete(numero)
            aumentarPuntaje()
            imagenAleatoria=None
            aleatorio()
        else:
            reducirPuntaje()

    canvas.after(10,keyJuego)

#--------------WIDGETS------------------
hiloTemporizador = threading.Thread(target=temporizador)
hiloTemporizador.start()
canvas.focus_set()
canvas.pack()
keyJuego()
canvas.bind("<KeyPress>", keydown)#Liga el evento key al canvas
canvas.bind("<KeyRelease>", keyup)

gui.mainloop()