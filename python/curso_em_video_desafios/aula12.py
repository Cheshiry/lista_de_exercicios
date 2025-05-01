for a in range(6, 0, -1):
    print(a)
    
i = int(input("Início: "))
f = int(input("Fim: "))
p = int(input("Passo: "))

for a in range(i, f+1, p):
    print(a)
    
for b in range(0, 3):
    n = int(input("Digite um número: "))

s = 0

for d in range(0, 4):
    n = int(input("Digite um número: "))
    s += n
print(s)
