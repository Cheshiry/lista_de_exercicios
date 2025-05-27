primeiro = int(input("1º termo: " ))
razao = int(input("Razão: " ))
decimo = primeiro + (10 - 1) * razao
i = 1

while i <= 10:
          
    print(primeiro, end = " → " )
    primeiro += razao 
    i += 1
    
print("Fim")

print("=+"*20)

primeiro = int(input("1º termo: " ))
razao = int(input("Razão: " ))
decimo = primeiro + (10 - 1) * razao

for lista in range(primeiro, decimo, razao):
    print(lista, end = " → " )
print("Fim")
