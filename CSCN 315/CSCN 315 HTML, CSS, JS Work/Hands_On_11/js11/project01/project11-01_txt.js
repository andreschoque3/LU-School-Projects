"use strict";
/*    JavaScript 7th Edition
      Chapter 11
      Project 11-01

      Project to retrieve the Astronomy Picture of the Day from NASA
      Author: Andres Choque
      Date:   

      Filename: project11-01.js
*/

let imageBox = document.getElementById("nasaImage");
let dateBox = document.getElementById("dateBox");

async function fetchData(req) {
      let response = await fetch(req);
      console.log(response);
      if (response.ok == true) {
            return await response.json();
      }
      throw new Error(response.statusText);
}


dateBox.onchange = function () {
      var dateStr = dateBox.value;

      fetch(`https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY&date=${dateStr}`)
            .then(response => response.json())
            .then(json => showPicture(json))
            .catch(error => console.log(error));

}

function showPicture(json) {

      if (json.media_type === "video") {

            imageBox.innerHTML = `<iframe src= ${json.url}></iframe><h1>title</h1><p>${json.explanation}</p>`;
      }
      else if (json.media_type === "image") {

            imageBox.innerHTML = `<img src= ${json.url}></iframe><h1>${json.title}</h1><p>${json.explanation}</p>`;
      }
      else {
            imageBox.innerHTML = "Image not Available";
      }
}



