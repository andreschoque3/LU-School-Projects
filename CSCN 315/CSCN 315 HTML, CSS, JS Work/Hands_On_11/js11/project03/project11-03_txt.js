"use strict";
/*    JavaScript 7th Edition
      Chapter 11
      Project 11-03

      Project to retrieve order history from a web server
      Author: Andres Choque
      Date:   

      Filename: project11-03.js
*/

let orderResult = document.getElementById("orderResult");
let userIDBox = document.getElementById("userID");
let pwdBox = document.getElementById("pwd");


// Retrieve order history when the View Orders button is clicked
viewOrders.onclick = function () {
      let user = userIDBox.value;
      let pwd = pwdBox.value;

      fetch(`wworders.pl?id=${user}&pwd=${pwd}`)
            .then(response => response.json())
            .then(json => buildOrderTable(json))
            .catch(error => console.log(error));
}


// Function to display order history within web tables
function buildOrderTable(obj) {
      if (obj.status === "Orders Not Found") {
            orderResult.innerHTML = "No orders found for user id and password";
      }
      else {
            let htmlCode = `<table id ="summary"><tr><th>Name</th><td>${obj.username}</td><tr><th>Total Charges</th><td>${obj.totalCharges}</td></tr></table>`;

            for (let orders of obj.orderHistory) {
                  htmlCode += `<table class="orderList"><tr><th colspan="2">${orders.orderDate}</th><th colspan="2">${orders.orderCost}</th></tr><tr><th>Description</th><th>Qty
                  </th><th>Price>/th><th>Total</th></tr>`
                  for (let items of orders.products) {
                        htmlCode += `<tr><td>${items.description}</td><td>${items.qty}</td><td>${items.price}</td><td>${items.total}</td></tr>`;
                  }
                  htmlcode += `</table>`
            }
            orderResult.innerHTML = htmlCode;
      }
}

