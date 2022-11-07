/*    JavaScript 7th Edition
      Chapter 2
      Project 02-03

      Application to return the shape of a clicked object
      Author: Andres Choque
      Date:   9/1/2022

      Filename: project02-03.js
 */
document.getElementById("square").addEventListener("click", function () {
      window.alert("You're hovering over the square");
}, false);
document.getElementById("triangle").addEventListener("click", function () {
      window.alert("You're hovering over the triangle");
}, false);
document.getElementById("circle").addEventListener("click", function () {
      window.alert("You're hovering over the circle");
}, false);