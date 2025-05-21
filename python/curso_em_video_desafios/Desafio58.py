from random import randint
from time import sleep
pc = randint(0, 5)

print("Sou seu pc, e pensei em um número adivinhe ")
print("Será que você consegue adivinhar qual foi?")

acertou = False
palpite = 0


while not acertou:
    jogador = int(input("Qual o seu palpite? "))
    palpite += 1 
    
    print("=="*20)

    if jogador == pc:
        acertou = True
    else:
        if jogador < pc:
            print("Mais... tente mais uma vez.")  
        elif jogador > pc:
            print("Menos... tente mais uma vez.")  
     
        
print("Você venceu a máquina", jogador, pc)
print("No round",palpite)
