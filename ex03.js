// valor da comissão
let nome = "Ana";
let vendas = 3000;
let comissao

if (vendas >= 50000){
    comissao = ((vendas*12)/100);
    
}else if(vendas >= 30000){
    comissao = ((vendas*9.5)/100);
}else{
    comissao = ((vendas*7)/100);
}

console.log(`O ${nome} vendeu R$${vendas} e ganhou de comissao R$${comissao.replace()}`)