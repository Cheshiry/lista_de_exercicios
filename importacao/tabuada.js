const {gets, print} = require('./funcoes02');

let tabuada = 2;
const mult = gets();
const tabela = [];

for (let i = 0; i < mult; i++) {

    tabela.push(tabuada * mult); 
    
}

print(tabela);