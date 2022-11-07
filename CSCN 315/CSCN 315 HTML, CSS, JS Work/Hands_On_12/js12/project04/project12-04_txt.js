"use strict";
/*    JavaScript 7th Edition
      Chapter 12
      Project 12-04

      Project to create an interactive slideshow
      Author: Andres Choque
      Date:   

      Filename: project12-04.js
*/

let slideNumber = 0;


$('img#leftbutton').click(() => {
      if (slideNumber > 0) {

            $('img.slideImages').animate({
                  left: "+=401px"
            }, 1000);


            slideNumber -= 1;


            let currentSlide = $("img.slideImages")[slideNumber];
            let slideCaption = $(currentSlide).attr("alt");
            changeCaption(slideCaption);
      }
});


$('img#rightbutton').click(() => {
      if (slideNumber < 11) {

            $('img.slideImages').animate({
                  left: "-=401px"
            }, 1000);


            slideNumber += 1;


            let currentSlide = $("img.slideImages")[slideNumber];
            let slideCaption = $(currentSlide).attr("alt");
            changeCaption(slideCaption);
      }
});


function changeCaption(captionText) {
      $('div#caption').hide("blind", { direction: "left" }, 500, () => {
            $("div#caption").text(captionText);
      }).show("blind", { direction: "left" }, 500);
}
