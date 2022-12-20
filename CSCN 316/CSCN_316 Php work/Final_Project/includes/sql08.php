<?php
// Connect to Server and Database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_news");

if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
}

// Perform query
$sql08 = "SELECT news.article as art, news.date as dat, news.newstype as ntype
FROM news
WHERE news.article_id = 00008";
if($result = mysqli_query($con, $sql08)){
    if(mysqli_num_rows($result) > 0){ 
      echo "<table>";
        echo "<tr>";
        echo "<th>Article 2</th>";
        echo "<th>date</th>";
        echo "<th>News Type</th>";
        echo "</tr>"; 

        while($row = mysqli_fetch_array($result)){ // work through array of results
        echo "<tr>";
        echo "<td>" . $row['art'] . "</td>";
        echo "<td>" . $row['dat'] . "</td>";
        echo "<td>" . $row['ntype'] . "</td>";
        echo "</tr>";
        }
        echo "</table>";
        // Free result set
        mysqli_free_result($result);
    } else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql08. " . mysqli_error($con);
}
?>