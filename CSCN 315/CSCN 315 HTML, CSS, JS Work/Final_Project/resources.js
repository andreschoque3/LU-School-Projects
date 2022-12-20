const storeLink = (evt) => {
    let linkURL = evt.target.value;
    let newWin = window.open(linkURL);
}

const changeFunction = (evt) => {
    storeLink(evt);
}

const anonymous = () => {
    const allSelect = document.querySelectorAll("form#govLinks select");
    for (let i = 0; i < allSelect.length; i++) {
        allSelect[i].addEventListener("change", changeFunction);
    }
}

window.onload = (event) => {
    anonymous();
};