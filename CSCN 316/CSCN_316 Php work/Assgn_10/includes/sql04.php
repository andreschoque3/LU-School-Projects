<?php
// Connect to Server and Database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_nation");

if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
}

// Perform query
$sql04 = "SELECT countries.name as cn, countries.country_code3, regions.name as rn
FROM countries
INNER JOIN regions ON regions.region_id = countries.region_id
LIMIT 10";

if($result = mysqli_query($con, $sql04)){
    if(mysqli_num_rows($result) > 0){
        echo "<table>";
        echo "<tr>";
        echo "<th>Country Name </th>";
        echo "<th>Country Code</th>";
        echo "<th>Region Name</th>";
        echo "</tr>"; 

        while($row = mysqli_fetch_array($result)){ // work through array of results
        echo "<tr>";
        echo "<td>" . $row['cn'] . "</td>";
        echo "<td>" . $row['country_code3'] . "</td>";
        echo "<td>" . $row['rn'] . "</td>";
        echo "</tr>";
        }
        echo "</table>";
      
        // Free result set
        mysqli_free_result($result);
    } else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql04. " . mysqli_error($con);
}
?>