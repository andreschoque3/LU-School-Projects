/*    JavaScript 7th Edition
      Chapter 4
      Project 04-03

      Application to count the number of characters in a review comment
      Author: Andres Choque
      Date:   9/18/2022

      Filename: project04-03.js
*/

// Maximum Length of Review
"use strict";
MAX_REVIEW = 100;
document.getElementById("limit").innerHTML = MAX_REVIEW;

// Reference to elemets in the web page
let wordCountBox = document.getElementById("countValue");
let warningBox = document.getElementById("warningBox");

// Event listener for typing into the comment box
let keyup = "keyup";
document.getElementById("comment").addEventListener(keyup, updateCount);

// Function to update the count with each keyup event
function updateCount() {
   // Set the warning box to an empty text string 

   warningBox.innerHTML = "";

   // Count the number of characters in the comment box
   commentText = document.getElementById("comment").value;
   charCount = countCharacters(commentText);

   try {
      if (charCount > MAX_REVIEW) {
         throw 'You have exceeded the character count limit';
      }
   }
   catch (err) {
      warningBox.innerHTML = err;
   }
   finally {
      wordCountBox.innerHTML = charCount;
   }
}


/*=================================================================*/
// Function to count the number of characters in a text string
function countCharacters(textStr) {
   var commentregx = /\s/g;
   var chars = textStr.replace(commentregx, "");
   return chars.length;
} 