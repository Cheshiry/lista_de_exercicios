const { gets, print } = require('./funcaoSalario');

let salarioBruto = gets();
let beneficio = gets();

function calcularPorcentagem(salario, porcento){
    return salario * (porcento / 100);
}

function pegarAlicota(salarioBruto) {
    
if (salarioBruto >= 0 && salarioBruto <= 1100){
    return 5;
        
    }
else if (salarioBruto >= 1100.01 && salarioBruto <= 2500){
    return 10;
       
        }
else if(salarioBruto >= 2500.01){
    return 15;
        
}
}
const alicotaImposto = pegarAlicota(salarioBruto);

const valorImposto = calcularPorcentagem(salarioBruto, alicotaImposto);

const valorATrasferir = (salarioBruto - valorImposto) + beneficio;

print(valorATrasferir);
