<?php
// Connect to Server and Database
$con = mysqli_connect("localhost","jwestfal_student","cscn3162022","jwestfal_office");

if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  exit();
}

// Perform query
$sql01 = "SELECT regions.REGION_ID, regions.REGION_NAME, countries.COUNTRY_ID, countries.REGION_ID, countries.COUNTRY_NAME, locations.COUNTRY_ID, locations.STREET_ADDRESS, locations.CITY, locations.POSTAL_CODE
FROM regions, countries, locations
WHERE regions.REGION_ID = countries.REGION_ID AND countries.COUNTRY_ID = locations.COUNTRY_ID";
if($result = mysqli_query($con, $sql01)){
    if(mysqli_num_rows($result) > 0){ 
        echo "<table>";
        echo "<tr>";
        echo "<th>Country</th>";
        echo "<th>Region</th>";
        echo "<th>Street Address</th>";
        echo "<th>City</th>";
        echo "<th>Postal code</th>";
        echo "</tr>";

        while($row = mysqli_fetch_array($result)){ // work through array of results
        echo "<tr>";
        echo "<td>" . $row['COUNTRY_NAME'] . "</td>";
        echo "<td>" . $row['REGION_NAME'] . "</td>";
        echo "<td>" . $row['STREET_ADDRESS'] . "</td>";
        echo "<td>" . $row['CITY'] . "</td>";
        echo "<td>" . $row['POSTAL_CODE'] . "</td>";
        echo "</tr>";

        }
        echo "</table>";

        // Free result set
        mysqli_free_result($result);
    } else{
        echo "No records matching your query were found.";
    }
} else{
    echo "ERROR: Could not connect to execute $sql01. " . mysqli_error($con);
}
 
// Close connection
// mysqli_close($con);
?>