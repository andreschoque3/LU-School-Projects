"use strict";
/*    JavaScript 7th Edition
      Chapter 6
      Project 06-01

      Project to validate a form used for setting up a new account
      Author: Andres Choque
      Date:   10/02/2022

      Filename: project06-01.js
*/
let submitButton = document.getElementById("submitButton");

let pwd = document.getElementById("pwd");

let pwd2 = document.getElementById("pwd2");

submitButton.addEventListener("click", function () {
      let passwd = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,20}$/;

      if (pwd.value.match(passwd)) {
            if (pwd.value != pwd2.value) {
                  pwd2.setCustomValidity("Your passwords must match");
                  return false;
            } else {
                  document.getElementById('signup').action = './formsubmit.html';
                  document.getElementById('signup').submit();
                  return true;
            }
      }
      else {
            pwd.setCustomValidity("Your password must be atleast 8 characters with at least one letter and one number.");
            return false;
      }
});
