/*    JavaScript 7th Edition
      Chapter 2
      Project 02-02

      Application to test for completed form
      Author: Andres Choque
      Date:   9/1/2022

      Filename: project02-02.js
 */
function verifyForm() {
      var name = document.getElementById("name");
      var email = document.getElementById("email");
      var phone = document.getElementById("phone");
      (name.value && email.value && phone.value) ? window.alert("Thank you!") :
            window.alert("Please fill in all the fields.");
}
document.getElementById("submit").addEventListener("click", verifyForm, false);