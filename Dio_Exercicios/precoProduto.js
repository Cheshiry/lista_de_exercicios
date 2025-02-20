let precoEtiqueta = 200.00;
const metodoPagamento = 2;

if (metodoPagamento === 1) {
    //dinheiro
    precoEtiqueta = precoEtiqueta - (precoEtiqueta * 1.5);
    
    console.log(`O preço ficou ${precoEtiqueta}`);

} else if(metodoPagamento === 2) {
    //'debito', 'pix'
    precoEtiqueta = precoEtiqueta - (precoEtiqueta * 0.1);
    
    
    console.log(`O preço ficou ${precoEtiqueta}`);

} else if(metodoPagamento === 3){
    //2x no cartão
    
    console.log(`O preço ficou ${precoEtiqueta}`);

} else {
    //mais de 2x
    precoEtiqueta = precoEtiqueta + (precoEtiqueta * 0.10);
    console.log(`O preço ficou ${precoEtiqueta}`);
}