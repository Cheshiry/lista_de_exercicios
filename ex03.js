// valor da comissão
let nome = "Ana";
let vendas = 3000;
let comissao

if (vendas >= 50000.00){
    comissao = ((vendas*12)/100);
    
}else if(vendas >= 30000.00){
    comissao = ((vendas*9.5)/100);
}else{
    comissao = ((vendas*7)/100);
}

console.log(`O ${nome} vendeu ${vendas.toLocaleString("pt-BR", { style: "currency", currency:"BRL"})} e ganhou de comissao ${comissao.toLocaleString("pt-BR",{style: "currency", currency: "BRL"}).replace(".",",")}`)