const {print, gets} = require("./funcaoSalario")

let salarioBruto = gets();
let beneficio = gets();
let salarioLiquido;

    if (salarioBruto <= 0 || salarioBruto < 1100){
        salarioLiquido = (salarioBruto - (salarioBruto * 0.05)) + beneficio;
    }
    if (salarioBruto <= 1101 || salarioBruto < 2500){
        salarioLiquido = (salarioBruto - (salarioBruto * 0.1)) + beneficio;
    }
    else{
        salarioLiquido = (salarioBruto - (salarioBruto * 0.15)) + beneficio;
    }

