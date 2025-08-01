from random import randint
vitoria = 0

print(f"\tVamos Jogar Par ou Impar\n")
while True:
    escolha = " "
    num_jogador = int(input("Digite um número: "))
    op_maquina = int(randint(0,11))
    soma = op_maquina + num_jogador
    print(op_maquina)
    print("x"*40)


    while escolha not in "PI":
        escolha = str(input("Digite [I]Impar ou [P]par: ")).upper().strip()[0]
    print(f"Vocês jogaram\nJogador: {num_jogador} X Pc: {op_maquina}\n")
    if escolha == "P":
        if soma % 2 == 0:
            print("Você venceu!")
            vitoria += 1
        else:
            print(f"GAME OVER! ") 
            break
    elif escolha == "I":
        if soma % 2 == 1:
            print("Você venceu!")
            vitoria += 1
        else:
            print(f"GAME OVER! ") 
            break
    print("Vamos jogar de novo!")
    print("x"*40)
print(f"Você venceu {vitoria}")
        


"""    
    if escolha == 2 and soma % 2 == 0:
        print(f"O jogador vencer!\nJogador: {num_jogador} + Pc: {op_maquina}\n")
        vitorias += 1
   
    elif escolha == 1 and soma % 2 != 0:
        print(f"O jogador vencer!\nJogador: {num_jogador}\nPc: {op_maquina}\n")
        vitorias += 1
    else: 
        print(f"GAME OVER! ") 
        break   
       
print("x"*40)
print(f"vitorias: {vitorias}") 
"""