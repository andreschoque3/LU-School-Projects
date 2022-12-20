<?php
// Connect to Server and Database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_news");

if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
}

// Perform query
$sql10 = "SELECT news.article as art
FROM news
WHERE news.article_id = 00005";
if($result = mysqli_query($con, $sql10)){
    if(mysqli_num_rows($result) > 0){ 
      echo "<table>";
        echo "<tr>";
        echo "<th>Article 1</th>";
        echo "</tr>"; 

        while($row = mysqli_fetch_array($result)){ // work through array of results
        echo "<tr>";
        echo "<td>" . $row['art'] . "</td>";
        echo "</tr>";
        }
        echo "</table>";
        // Free result set
        mysqli_free_result($result);
    } else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql10. " . mysqli_error($con);
}
?>