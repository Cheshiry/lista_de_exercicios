primeiro = int(input("1º termo: " ))
razao = int(input("Razão: " ))

i = 1
stop = 1

while stop !=0 :

    if stop == 1:
        i = 0
        while i <= 10:
            print(primeiro, end = " → " )
            primeiro += razao 
            i += 1
    stop = int(input("\nGostaria de parar? \n[0] Sim\n[1] Não\n"))
    
print("Fim")

print("=+"*20)
