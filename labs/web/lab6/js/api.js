let inputs = 0;

function addOrder() {
    let table = document.getElementById("orders");

    let tr = document.createElement("TR");

    let td1 = document.createElement("TD");
    let td2 = document.createElement("TD");
    let td3 = document.createElement("TD");
    let td4 = document.createElement("TD");

    let orderName = document.createElement("p");
    let price = document.createElement("p");

    inputs++;

    if (inputs > 0) {
        var checkbox = document.createElement("INPUT");
        checkbox.setAttribute("type", "checkbox");

        checkbox.checked = true; // Check it.

        let img = document.createElement('IMG');
        img.setAttribute('src', "delete.gif");
        img.setAttribute('width', '7%');

        img.onclick = function() {
            removeOrder(tr);
            recalculatePrice();
        }

        checkbox.onclick = function () {
            recalculatePrice();
        }

        td3.appendChild(checkbox);
        td4.appendChild(img);
    }

    let orderTitle = "";
    let orderPrice = 0;

    orderTitle = prompt("Введите название товара", orderTitle);
    orderPrice = prompt("Введите цену товара", orderPrice);

    while (orderPrice <= 0) {
        orderPrice = prompt("Вы ввели неверное значение цены. Пожалуйста, введите ненулевое значение цены. \r\rВведите цену товара", orderPrice);
    }

    orderName.textContent = orderTitle;
    price.textContent = parseInt(orderPrice);

    table.appendChild(tr);

    tr.appendChild(td1);
    tr.appendChild(td2);
    tr.appendChild(td3);
    tr.appendChild(td4);

    td1.appendChild(orderName);
    td2.appendChild(price);

    recalculatePrice();
}

function removeOrder(tr) {
    tr.parentNode.removeChild(tr);
}

function recalculatePrice() {
    let totalPrice = 0;

    // get a table and all checkboxes of a table
    let table = document.getElementById("orders");
    let checkboxes = document.getElementsByTagName('input');

    //gets rows of table
    let rowLength = table.rows.length;

    //loops through rows
    if (rowLength > 2) {
        for (i = 0; i < rowLength - 2; i++) {
            if (checkboxes.item(i).checked) {
                //gets cells of current row
                //since we have shifted 2 cells -> we need to move right to 2.
                let oCells = table.rows.item(i + 2).cells;

                //gets amount of cells of current row
                let cellLength = oCells.length;

                //loops through each cell in current row
                for (var j = 0; j < cellLength; j++) {
                    // check price cell
                    if (j == 1) {
                        oCells.item(1).style.backgroundColor = "#43ff6424";
                        totalPrice += parseInt(oCells.item(1).innerHTML.replaceAll("<p>", "").replaceAll("</p>", ""));
                    }
                }
            }
            else {
                //gets cells of current row
                //since we have shifted 2 cells -> we need to move right to 2.
                let oCells = table.rows.item(i + 2).cells;

                //gets amount of cells of current row
                let cellLength = oCells.length;

                //loops through each cell in current row
                for (var j = 0; j < cellLength; j++) {
                    // check price cell
                    if (j == 1) {
                        oCells.item(1).style.backgroundColor = "#f00d0a24";
                    }
                }
            }
        }
    }

    document.getElementById('totalPrice').value = totalPrice;
}