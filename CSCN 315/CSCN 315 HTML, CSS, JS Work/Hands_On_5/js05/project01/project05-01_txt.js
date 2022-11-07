"use strict";
/*    JavaScript 7th Edition
      Chapter 5
      Project 05-01

      Project to present an online quiz with a countdown clock
      Author: Andres Choque
      Date:   9/25/2022

      Filename: project05-01.js
*/

// Constants to set the time given for the quiz in seconds
// and the correct answers to each quiz question
let timeID;
let questionList = document.querySelectorAll("div#quiz input");

document.querySelectorAll("div#quiz input");
const quizTime = 20;
const correctAnswers = ["10", "4", "-6", "5", "-7"];


// Elements in the quiz page
let startQuiz = document.getElementById("startquiz");
let quizClock = document.getElementById("quizclock");
let overlay = document.getElementById("overlay");

startQuiz.onclick = function () {

   overlay.className = "showquiz";

   timeID = setInterval(function () {
      countdown();
   }, 1000);
};

function countdown() {

   if (timeLeft === 0) {

      clearInterval(timeID);

      let totalCorrect = checkAnswers();

      if (totalCorrect === correctAnswers.length) {

         alert("Congrats on scoring the 100%! ");

      } else {

         alert("Incorrect answers count: " + (questionList.length - totalCorrect));

         timeLeft = quizTime;
         quizClock.value = timeLeft;
         overlay.className = "hidequiz";
      }

   } else {

      timeLeft = timeLeft - 1;
      quizClock.value = timeLeft;

   }
}
// Initialize the quiz time
quizClock.value = quizTime;
let timeLeft = quizTime;

// Declare the ID for timed commands
// and the node list for questions
function checkAnswers() {
   let correctCount = 0;

   for (let i = 0; i < questionList.length; i++) {
      if (questionList[i].value === correctAnswers[i]) {
         correctCount++;
         questionList[i].className = "";
      } else {
         questionList[i].className = "wronganswer";
      }
   }
   return correctCount;
}





















/*------------- Function to check the student answers ----------------*/
function checkAnswers() {
   let correctCount = 0;

   for (let i = 0; i < questionList.length; i++) {
      if (questionList[i].value === correctAnswers[i]) {
         correctCount++;
         questionList[i].className = "";
      } else {
         questionList[i].className = "wronganswer";
      }
   }
   return correctCount;
}

