/*    JavaScript 7th Edition
      Chapter 4
      Project 04-01

      Application to calculate total moving cost
      Author: Andres Choque
      Date:   9/18/2022

      Filename: project04-01.js
*/

// Global Constants
COST_PER_LB = 0.50;
COST_PER_MILE = 0.75;
SETUP_COST = 500;

// Global Variables
let wgtBox = document.getElementById("wgtBox");
let distBox = document.getElementById("distBox");
let msgBox = document.getElementById("msgBox");


// Event Handlers
document.getElementById("wgtBox").onchange = calcTotal;
document.getElementById("distBox").onchange = calcTotal;
document.getElementById("setupBox").onclick = calcTotal;

// Function to calculate an estimate of the total moving cost
function calcTotal() {
   let totalCost = 0;      // Set the initial estimate to $0

   errBox.innerHTML = "";  // Erase any warnings in the message box

   msgBox.innerHTML = "";

   totalCost.innerHTML = "";


   if (document.getElementById("setupBox").checked) {
      totalCost += SETUP_COST
   }

   // Display the moving cost estimate in the totalBox, formatted as currency
   try {

      if (wgtBox.value <= 0) throw "!! Enter a positive weight";
      if (distBox.value <= 0) throw "!! Enter a positive mileage";

      totalCost += wgtBox.value * COST_PER_LB;
      totalCost += distBox.value * COST_PER_MILE;


      document.getElementById("totalBox").innerHTML = formatCurrency(totalCost);
   }
   catch (err) {
      errBox.innerHTML = err;
   }

   // Function to display a numeric value as a text string in the format $##.## 
   function formatCurrency(value) {
      return "$" + value.toFixed(2);
   }
}