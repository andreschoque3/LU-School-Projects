"use strict";
/*    JavaScript 7th Edition
      Chapter 9
      Project 09-03

      Project to retrieve date of last visit from web storage and mark new article
      Author: Andres Choque
      Date:   10/23/2022

      Filename: project09-03.js
*/

/* Page Objects */

let lastVisitDate = document.getElementById("lastVisitDate");
let articleDates = document.getElementsByClassName("posttime");

if (localStorage.sbloggerVisit) {
      const storedLastDate = localStorage.sbloggerVisit;

      lastVisitDate.innerHTML = storedLastDate;

      const lastDate = storedLastDate;

      for (let i = 0; i < articleDates.length; i++) {
            let articleDate = articleDates[i].innerHTML;

            if (articleDate > lastDate) {
                  articleDates[i].innerHTML = articleDates[i].innerHTML + "<strong>new</strong>";

            }
      }
}
else {
      lastVisitDate.innerHTML = "Welcome to SBlogger!";

      for (let i = 0; i < articleDates.length; i++) {
            articleDates[i].innerHTML = articleDates[i].innerHTML + "<strong>new</strong>";
      }
}

let currentDate = new Date("9/12/2024");
localStorage.sbloggerVisit = currentDate.toLocaleString();

