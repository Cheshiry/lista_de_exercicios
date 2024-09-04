const {gets, print} = require('./funcoes02');


const mult = gets();
const tabela = [];

for (let i = 0; i <= 10; i++) {

    print(`${mult}X${i} = ${mult * i}`) ;
    
}
