from time import sleep

op = 0

n1 = int(input("1° número: "))
n2 = int(input("2° número: "))
    

while op != 5:

    op = int(input("""
Digite uma das opções abaixo 
[1] somar 
[2] multiplicar
[3] maior
[4] novos números 
[5] Sair\n
"""))
    print(">>>>>>> Qual a sua opção? ")
    if op == 1:
        soma = n1+ n2
        
        print("A soma", soma)
        print("*" * 20)
        
    elif op == 2:
         mult = n1 * n2
        
         print("A multiplicação", mult)
         print("*" * 20)
         
    elif op == 3:
         maior = n1        
         if n1 < n2:
             maior = n2
             print("O maior número", maior)
         elif n1 == n2:
             print(f"Não existe um número maior os dois sao iguais {n1}, {n2}.")
         else:
             print(f"O maior número é {maior}")               
         print("*" * 20)
         
    elif op == 4:
        print("Digite novos números:") 
        n1 = int(input("1° número: "))
        n2 = int(input("2° número: "))
        
    elif op == 5:
        print("Finalizando...")
        sleep(1)
    else:
         print("opção válida")   
print("*" * 20)
print("Fim do programa")
    
