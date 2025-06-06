primeiro = int(input("1º termo: " ))
razao = int(input("Razão: " ))
contador = 1
mais = 10
total = 1

while mais != 0 :
    total += mais
    while contador != total:
        print(primeiro, end = " → " )
        primeiro += razao 
        contador += 1
    print("Pausa")
    mais = int(input("Quantos a mais? "))
print(f"A pa foi finalizada com {total-1} de termos.")
print("Fim")

print("=+"*20)
