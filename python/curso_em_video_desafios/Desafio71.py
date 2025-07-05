valor_saque = 0
resp = " "
'''div5
div10
div20
div50
div100'''
titulo = "Banco Amigo"
print(f"{titulo:=^30}")
saldo = int(input("Digite quanto quer sacar:"))
total_notas = saldo
nota = 50
q_nota = 0

while True:
    if total_notas >= nota:
   
        total_notas -= nota 
        q_nota += 1
    else:
        if q_nota > 0:
            print(f"Total:{q_nota} notas de {nota}")
            	        
        if nota == 50:
            nota = 20
            
        elif nota == 20:
             nota = 10
             
        elif nota == 10:
            nota = 1
         
        q_nota = 0    
            
        if total_notas == 0:
            break
    
    
    
    
