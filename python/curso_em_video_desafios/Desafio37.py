print("\033[1;36m=+"*25)
print("Conversor numérico")
num = int(input("escreva um número inteiro: "))
escolha = int(input("""
Escolha qual o formato de conversão do número:
    1. Binário
    2. Octal
    3. Hexadecimal
	"""))

if escolha == 1:
	
    	novo_num = bin(num)
    	print(novo_num)
	
elif escolha == 2:
    	novo_num = hex(num)
    	print(novo_num)
else:
    novo_num = oct(num)
    print(novo_num)
    
print("\033[1;36m=+"*25)
