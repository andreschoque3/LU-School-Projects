"use strict";
/*    JavaScript 7th Edition
      Chapter 12
      Project 12-02

      Project to convert between celsius and fahrenheit
      Author: Andres Choque
      Date:   

      Filename: project12-02.js
*/


$("input#cValue").change(function (event) {

      let celsius = $(event.target).val();


      let fahrenheit = 1.8 * celsius + 32;


      $("input#fValue").val(fahrenheit.toFixed(0));

});


$("input#fValue").change(function (event) {

      let fahrenheit = $(event.target).val();


      let celsius = (fahrenheit - 32) / 1.8;


      $("input#cValue").val(celsius.toFixed(0));

});