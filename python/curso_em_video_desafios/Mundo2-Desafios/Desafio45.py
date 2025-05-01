
from random import randint
from time import sleep

itens = ["Pedra", "Papel", "Tesoura"]

computador = randint(0,2)

print("{:=^100}".format(" Joquenpô: "))
jogador = int(input(""" Qual a sua jogada\n[0] Pedra\n[1] Papel\n[2] Tesoura\nDigite sua opção: """))

print("*" * 50)
print("Jo")
sleep(1)
print("Ken")
sleep(1)
print("Po")
sleep(1)

print("*" * 50)

print(f"Pc: {itens[computador]} \nJogador: {itens[jogador]}")

print("*" * 50)

if jogador == 0:
    if computador == 0:
        print("Deu empate")
    elif computador == 1:
        print("Pc venceu")
    elif computador == 2:
        print("Jogador venceu")
    else:
        print("Jogada Inválida!")
elif jogador == 1:
    if computador == 0:
        print("Jogador venceu")
    elif computador == 1:
        print("Empate")
    elif computador == 2:
        print("Computador venceu")
    else:
        print("Jogada Inválida!")
elif jogador == 2:
    if computador == 0:
        print("computador venceu")
    elif computador == 1:
        print("Jogador venceu")
    elif computador == 2:
        print("Empate")
    else:
        print("Jogada Inválida!")
