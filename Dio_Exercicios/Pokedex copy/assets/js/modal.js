function openModal(){
    const modal = document.getElementById('modal-window')
    const content = document.getElementById('modal')

    modal.classList.add('open');

    return 
    `
        
    `

    modal.addEventListener('click', (e) => {
        if(e.target.id == 'close' || e.target.id == 'modal-window'){
            modal.classList.remove('open');
        }    
    
})
}


