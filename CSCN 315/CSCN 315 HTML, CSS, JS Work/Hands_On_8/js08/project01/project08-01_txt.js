"use strict";
/*    JavaScript 7th Edition
      Chapter 8
      Project 08-01

      Project to create a timer object
      Author: Andres Choque
      Date:   10/16/2022

      Filename: project08-01.js
*/

/*--------------- Object Code --------------------*/
function timer(min, sec) {
      this.minutes = min;
      this.seconds = sec;
      this.timeID = null;
}

function runPause(timer, minBox, secBox) {

      if (timer.timeID) {
            window.clearInterval(timer.timeID);
            timer.timeID = null;
      }
      else {
            timer.timeID = window.setInterval(function () {
                  countdown(timer, minBox, secBox);
            }, 1000)
      }
}

function countdown(timer, minBox, secBox) {
      if (timer.seconds > 0) {
            timer.seconds -= 1;
      }
      else if (timer.minutes > 0) {
            timer.minutes -= 1;
            timer.seconds = 59;
      }
      else {
            window.clearInterval(timer.timeID);
            timer.timeID = null;
      }

      minBox.value = timer.minutes;
      secBox.value = timer.seconds;
}


/*---------------Interface Code -----------------*/

/* Interface Objects */
let minBox = document.getElementById("minutesBox");
let secBox = document.getElementById("secondsBox");
let runPauseTimer = document.getElementById("runPauseButton");
const myTimer = new timer(minBox.value, secBox.value);

minBox.onchange = () => {
      myTimer.minutes = minBox.value;
}

secBox.onchange = () => {
      myTimer.seconds = secBox.value;
}

runPauseTimer.onclick = () => {
      runPause(myTimer, minBox, secBox);

}
