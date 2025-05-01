from random import randint
from time import sleep

pc = randint(0, 5)

print("=="*20)
num = (int(input("Adivinhe o númeroque eu pensei: ")))
print("=="*20)

print("PROCESSANDO...")

sleep(2)

if num == pc:
    print("Você venceu a máquina ", num, pc)
else:
    print("O pc venceu  ",num, pc)
