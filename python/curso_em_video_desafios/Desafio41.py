from random import randint

itens = ["Pedra", "Papel", "Tesoura"]

computador = randint(0,2)

jogador = int(input(""" Qual a sua jogada\n[0] Pedra\n[1] Papel\n[2] Tesoura\n"""))

print("*" * 25)

print(f"Pc: {itens[computador]} \nJogador: {itens[jogador]}")

print("*" * 25)


if jogador == 0:
    if computador == 0:
        print("Deu empate")
    elif computador == 1:
        print("Pc venceu")
    elif computador == 2:
        print("Jogador venceu")
        
elif jogador == 1:
    if computador == 0:
        print("Jogador venceu")
    elif computador == 1:
        print("Empate")
    elif computador == 2:
        print("Computador venceu")
        
elif jogador == 2:
    if computador == 0:
        print("computador venceu")
    elif computador == 1:
        print("Jogador venceu")
    elif computador == 2:
        print("Empate")
        
