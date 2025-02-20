const { gets, print } = require('./funcaoSalario');

let salarioBruto = gets();
let beneficio = gets();
let salarioLiquido;

function verificarSalario(salarioBruto) {
    
if (salarioBruto > 0 || salarioBruto <= 1100){
    return (salarioBruto - (salarioBruto * 0.05));
        
    }
else if (salarioBruto >= 1101 || salarioBruto <= 2500){
    return (salarioBruto - (salarioBruto * 0.1));
       
        }
else if(salario < 2501){
    return (salarioBruto - (salarioBruto * 0.15));
        
}
}

novo = verificarSalario(salarioBruto)

print(novo + beneficio);
