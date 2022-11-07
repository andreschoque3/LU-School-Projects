"use strict";
/*    JavaScript 7th Edition
      Chapter 5
      Project 05-03

      Project to create a table of headings from an article
      Author: Andres Choque
      Date:   9/24/2022

      Filename: project05-03.js
*/
const sourceDoc = document.getElementById('source_doc');
const toc = document.getElementById('toc');

let headingCount = 1;
const heading = "H2";

for (let i = 0; i < sourceDoc.children.length; i++) {

      const n = sourceDoc.children[i];

      if (n.nodeName == heading) {

            const anchor = document.createElement('a');

            anchor.setAttribute('name', 'doclink' + headingCount);

            n.insertBefore(anchor, n.children[0]);

            const listitem = document.createElement('li');
            const link = document.createElement('a');

            listitem.appendChild(link);

            link.textContent = n.textContent;
            link.setAttribute('href', '#doclink' + headingCount);

            toc.appendChild(listitem);

            headingCount++;
      }

}
